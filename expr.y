%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tipoNo.h"

#define NUM_FUNCOES 128
#define TAM_MAX_STRING 1024
#define TAM_MAX_NOMEVAR 1024

int yyerror(const char *);
int yylex();

tipoNo *criaInteger(int);
tipoNo *criaReal(float val);
tipoNo *criaString(char *str);
tipoNo *criaId(char *name, int tipo);
tipoNo *criaOpr(int opr, Repeticao *rep, int nOps, ...);
void excluirNo(tipoNo *no);
Funcao* criaFuncao(int tipo, char *nome, Item *prms, Bloco *blc);
ListaDecl *criaListaDecl(Declaracao *decl);
Declaracao* criaDeclaracao(int tipo, Item *vars);
Bloco* criaBloco(ListaDecl *decl, Item *cmds);
Item* criaItem(tipoNo *arv);
Repeticao* criaRepeticao(Item *cmds, Item *senao);
void AddListaDecl(ListaDecl *o, ListaDecl *ad);
void AddItem(Item *o, Item *ad);
void AddFuncao(Funcao *f1, Funcao *f2);
void printFuncao(Funcao *f);
void printComandos(Item *cmds);

Item *tbl_sim;

%}

%union {
	float real;
	int integer;
	char *string;
	char *id;
	tipoNo *nPtr;
	Item *item;
	Bloco *bloco;
	Funcao *funcao;
	Declaracao *declaracao;
	ListaDecl *listadecl;
};

%define parse.error verbose

// Abre e fecha () e {}
%token SIM_ABREPARENTESES SIM_FECHAPARENTESES SIM_ABRECHAVES SIM_FECHACHAVES 
// Virgula ,
%token SIM_VIRGULA
// Operadores aritmeticos + * - /
%token SIM_ADICAO SIM_MULTIPLICACAO SIM_SUBTRACAO SIM_DIVISAO
// Igual =
%token SIM_IGUAL 
// Ponto e virgula ;
%token SIM_FIM
// Operadores relacionais == != > < >= <=
%token SIM_IGUALIGUAL SIM_DIFERENTE SIM_MAIORQUE SIM_MENORQUE SIM_MAIOROUIGUAL SIM_MENOROUIGUAL 
// Operadores logicos && || !
%token SIM_E SIM_OU SIM_NEGACAO

// Comandos
// Return 
%token COM_RETORNO
// If e Else
%token COM_SE COM_SENAO
// While
%token COM_ENQUANTO
// Print e Read
%token COM_IMPRIME COM_LER

// Tipos void, int, literal, string e float
%token TIPO_VOID TIPO_INT TIPO_STRING TIPO_FLOAT
%token TID CONS_INT CONS_LITERAL CONS_FLOAT
%type <id> TID
%type <integer> CONS_INT 
%type <string> CONS_LITERAL 
%type <real> CONS_FLOAT

%left SIM_MAIOROUIGUAL SIM_MENOROUIGUAL SIM_IGUALIGUAL SIM_DIFERENTE SIM_MAIORQUE SIM_MENORQUE
%left SIM_ADICAO SIM_SUBTRACAO
%left SIM_MULTIPLICACAO SIM_DIVISAO

%type <nPtr> Expr Expra Exprl Exprr Termo Fator Parametro Comando CmdIf CmdWhile CmdAtrib CmdWrite CmdRead ChamadaProc Retorno ListaParametros ChamaFuncao
%type <integer> Tipo TipoRetorno
%type <item> ListaCmd Bloco ListaId DeclParametros
%type <listadecl> Declaracoes
%type <declaracao> Declaracao
%type <bloco> BlocoPrincipal
%type <funcao> Funcao ListaFuncoes

%%
Programa: ListaFuncoes BlocoPrincipal YYEOF {AddFuncao($1, criaFuncao(TIPO_INT, "main", NULL, $2));printFuncao($1);}
	| BlocoPrincipal YYEOF {printFuncao(criaFuncao(285, "main", NULL, $1));}
	| YYEOF {exit(0);}
	;
ListaFuncoes: ListaFuncoes Funcao {AddFuncao($1, $2);$$ = $1;}
	| Funcao {$$ = $1;}
	;
Funcao: TipoRetorno TID SIM_ABREPARENTESES DeclParametros SIM_FECHAPARENTESES BlocoPrincipal {$$ = criaFuncao($1, $2, $4, $6);}
	| TipoRetorno TID SIM_ABREPARENTESES SIM_FECHAPARENTESES BlocoPrincipal {$$ = criaFuncao($1, $2, NULL, $5);}
	;
TipoRetorno: Tipo {$$ = $1;}
	| TIPO_VOID {$$ = TIPO_VOID;}
	;
DeclParametros: DeclParametros SIM_VIRGULA Parametro {AddItem($1, criaItem($3));$$ = $1;}
	| Parametro {$$ = criaItem($1);}
	;
Parametro: Tipo TID {$$ = criaId($2, $1);}
	;
BlocoPrincipal: SIM_ABRECHAVES Declaracoes ListaCmd SIM_FECHACHAVES {$$ = criaBloco($2, $3);}
	| SIM_ABRECHAVES Declaracoes SIM_FECHACHAVES {$$ = criaBloco($2, NULL);}
	| SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES {$$ = criaBloco(NULL, $2);}
	| SIM_ABRECHAVES SIM_FECHACHAVES {$$ = NULL;}
	;
Declaracoes: Declaracoes Declaracao {AddListaDecl($1, criaListaDecl($2));$$ = $1;}
	| Declaracao {$$ = criaListaDecl($1);}
	;
Declaracao: Tipo ListaId SIM_FIM {$$ = criaDeclaracao($1, $2);}
	;
Tipo: TIPO_INT {$$ = TIPO_INT;}
	| TIPO_STRING {$$ = TIPO_STRING;}
	| TIPO_FLOAT {$$ = TIPO_FLOAT;}
	;
ListaId: ListaId SIM_VIRGULA TID {AddItem($1, criaItem(criaId($3, 0)));$$ = $1;}
	| TID {$$ = criaItem(criaId($1, 0));}
	;
Bloco: SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES {$$ = $2;}
	| SIM_ABRECHAVES SIM_FECHACHAVES {$$ = NULL;}
	;
ListaCmd: ListaCmd Comando {$1->prox = criaItem($2); $$ = $1;}
	| Comando {$$ = criaItem($1);}
	;
Comando: CmdIf {$$ = $1;}
	| CmdWhile {$$ = $1;}
	| CmdAtrib {$$ = $1;}
	| CmdWrite {$$ = $1;}
	| CmdRead {$$ = $1;}
	| ChamadaProc {$$ = $1;}
	| Retorno {$$ = $1;}
	;
Retorno: COM_RETORNO Expra SIM_FIM {$$ = criaOpr(COM_RETORNO, NULL, 1, $2);}
	| COM_RETORNO CONS_LITERAL SIM_FIM {$$ = criaOpr(COM_RETORNO, NULL, 1, criaString($2));}
	| COM_RETORNO SIM_FIM {$$ = criaOpr(COM_RETORNO, NULL, 0);}
	;
CmdIf: COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco {$$ = criaOpr(COM_SE, criaRepeticao($5, NULL), 1, $3);}
	| COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco COM_SENAO Bloco {$$ = criaOpr(COM_SENAO, criaRepeticao($5, $7), 1, $3);}
	;
CmdWhile: COM_ENQUANTO SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco {$$ = criaOpr(COM_ENQUANTO, criaRepeticao($5, NULL), 1, $3);}
	;
CmdAtrib: TID SIM_IGUAL Expra SIM_FIM {$$ = criaOpr(SIM_IGUAL, NULL, 2, criaId($1, 0), $3);}
	| TID SIM_IGUAL CONS_LITERAL SIM_FIM {$$ = criaOpr(SIM_IGUAL, NULL, 2, criaId($1, 0), criaString($3));}
	;
CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES SIM_FIM {$$ = criaOpr(COM_IMPRIME, NULL, 1, $3);}
	| COM_IMPRIME SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES SIM_FIM {$$ = criaOpr(COM_IMPRIME, NULL, 1, $3);}
	| COM_IMPRIME SIM_ABREPARENTESES CONS_LITERAL SIM_FECHAPARENTESES SIM_FIM {$$ = criaOpr(COM_IMPRIME, NULL, 1, criaString($3));}
	;
CmdRead: COM_LER SIM_ABREPARENTESES TID SIM_FECHAPARENTESES SIM_FIM {$$ = criaOpr(COM_LER, NULL, 1, criaId($3, 0));}
	;
ChamadaProc: ChamaFuncao SIM_FIM {$$ = $1;}
	;
ChamaFuncao: TID SIM_ABREPARENTESES ListaParametros SIM_FECHAPARENTESES {$$ = criaOpr(1, NULL, 2, criaId($1, 1), $3);}
	| TID SIM_ABREPARENTESES SIM_FECHAPARENTESES {$$ = criaOpr(1, NULL, 1, criaId($1, 1));}
	;
ListaParametros: Expra SIM_VIRGULA ListaParametros {$$ = criaOpr(2, NULL, 2, $1, $3);}
	| TID SIM_VIRGULA ListaParametros {$$ = criaOpr(2, NULL, 2, criaId($1, 0), $3);}
	| Expra {$$ = $1;}
	| TID {$$ = criaId($1, 0);}
	;

Expr: Exprl {$$ = $1;}
	| Expra {$$ = $1;}
	| Exprr {$$ = $1;}
	;
Exprr: Exprr SIM_MAIORQUE Expra {$$ = criaOpr(SIM_MAIORQUE, NULL, 2, $1, $3);}
	| Exprr SIM_MENORQUE Expra {$$ = criaOpr(SIM_MENORQUE, NULL, 2, $1, $3);}
	| Exprr SIM_MAIOROUIGUAL Expra {$$ = criaOpr(SIM_MAIOROUIGUAL, NULL, 2, $1, $3);}
	| Exprr SIM_MENOROUIGUAL Expra {$$ = criaOpr(SIM_MENOROUIGUAL, NULL, 2, $1, $3);}
	| Exprr SIM_IGUALIGUAL Expra {$$ = criaOpr(SIM_IGUALIGUAL, NULL, 2, $1, $3);}
	| Exprr SIM_DIFERENTE Expra {$$ = criaOpr(SIM_DIFERENTE, NULL, 2, $1, $3);}
	| Expra {$$ = $1;}
	;
Expra: Expra SIM_ADICAO Termo {$$ = criaOpr(SIM_ADICAO, NULL, 2, $1, $3);}
	| Expra SIM_SUBTRACAO Termo {$$ = criaOpr(SIM_SUBTRACAO, NULL, 2, $1, $3);}
	| Termo {$$ = $1;}
	;
Termo: Termo SIM_MULTIPLICACAO Fator {$$ = criaOpr(SIM_MULTIPLICACAO, NULL, 2, $1, $3);}
	| Termo SIM_DIVISAO Fator {$$ = criaOpr(SIM_DIVISAO, NULL, 2, $1, $3);}
	| Fator {$$ = $1;}
	;
Fator: CONS_INT {$$ = criaInteger($1);}
	| CONS_FLOAT {$$ = criaReal($1);}
	| TID {$$ = criaId($1, 0);}
	| ChamaFuncao {$$ = $1;}
	| SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES {$$ = $2;}
	;
Exprl: Exprl SIM_E Expra {$$ = criaOpr(SIM_E, NULL, 2, $1, $3);}
	| Exprl SIM_OU Expra {$$ = criaOpr(SIM_OU, NULL, 2, $1, $3);}
	| SIM_NEGACAO Expra {$$ = criaOpr(SIM_NEGACAO, NULL, 1, $2);}
	| Expra {$$ = $1;}
	;
%%
#define SIZEOF_TIPONO ((char *)&no->inteiro - (char *)no)

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
} 		 

eTipo getTipoId(int v){
	if (v == TIPO_INT)
		return typeInt;
	else if (v == TIPO_FLOAT)
		return typeFloat;
	else if (v == TIPO_STRING)
		return typeString;
	else if (v == TIPO_VOID)
		return typeVoid;
}

char *getIdTipo(eTipo v){
	if (v == typeInt)
		return "int";
	else if (v == typeFloat)
		return "float";
	else if (v == typeString)
		return "string";
	else if (v == typeVoid)
		return "void";
}

int inFila(Item *f, char *name){
	while(f){
		if (!strcmp(f->arv->id.name, name))
			return 1;
		f = f->prox;
	}
	return 0;
}

tipoNo *criaInteger(int val){
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeInt);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");

	no->type = typeInt;
	no->inteiro.val = val;
	return no;
}

tipoNo *criaReal(float val){
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeFloat);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");

	no->type = typeFloat;
	no->real.val = val;
	return no;
}

tipoNo *criaString(char *str){
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeString);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");

	no->type = typeString;
	no->string.str = strdup(str);
	return no;
}

tipoNo *criaId(char *name, int tipo){
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeId);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");
	
	no->type = typeId; 
	no->id.name = strdup(name);
	no->id.tipo = getTipoId(tipo);
	if (tipo != 1){
		if (tbl_sim == NULL){
			tbl_sim = criaItem(no);
		}else{
			if (!inFila(tbl_sim, no->id.name))
				AddItem(tbl_sim, criaItem(no));
		}
	}
	return no;
}

tipoNo *criaOpr(int opr, Repeticao *rep, int nOps, ...){
	va_list ap;
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeOpr) + (nOps - 1) * sizeof(tipoNo*);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");
	if ((no->opr.op = malloc(nOps * sizeof(tipoNo*))) == NULL)
		yyerror("Sem memória");
	if ((no->opr.rep = malloc(sizeof(Repeticao))) == NULL)
		yyerror("Sem memória");

	no->type = typeOpr;
	no->opr.rep = rep;
	no->opr.opr = opr;
	no->opr.nOps = nOps;
	va_start(ap, nOps);
	for (int i=0;i<nOps;i++){
		no->opr.op[i] = va_arg(ap, tipoNo*);
	}
	va_end(ap);
	return no;
}

void excluirNo(tipoNo *no){
	if (!no)
		return;
	if (no->type == typeOpr){
		for (int i=0;i < no->opr.nOps; i++){
			excluirNo(no->opr.op[i]);
		}
	}
	free(no);
}

Item* criaItem(tipoNo *arv){
	Item *i = malloc(sizeof(Item));
	if (i == NULL){
		printf("Error ao alocar memória para o Item");
		exit(1);
	}
	if (arv->type == typeId)
		arv->id.i = 0;
	
	i->prox = NULL;
	i->arv = arv;
	return i;
}

Repeticao* criaRepeticao(Item *cmds, Item *senao){
	Repeticao *r = malloc(sizeof(Repeticao));
	if (r == NULL){
		printf("Error ao alocar memória para a Repetição");
		exit(1);
	}
	r->cmds = cmds;
	r->senao = senao;
	return r;
}

Declaracao* criaDeclaracao(int tipo, Item *vars){
	Declaracao *d = malloc(sizeof(Declaracao));
	if (d == NULL){
		printf("Error ao alocar memória para as Declarações");
		exit(1);
	}
	d->tipo = getTipoId(tipo);
	d->vars = vars;
	Item *var = d->vars;
	while (var != NULL){
		var->arv->type = getTipoId(tipo);
		var = var->prox;
	}
	return d;
}

ListaDecl *criaListaDecl(Declaracao *decl){
	ListaDecl *l = malloc(sizeof(ListaDecl));
	if (l == NULL){
		printf("Error ao alocar memória para a Lista de Declarações");
		exit(1);
	}
	l->prox = NULL;
	l->decl = decl;
	return l;
}

Bloco* criaBloco(ListaDecl *decl, Item *cmds){
	Bloco* b = malloc(sizeof(Bloco));
	if (b == NULL){
		printf("Error ao alocar memória para o Bloco");
		exit(1);
	}
	b->decl = decl;
	b->cmds = cmds;
	return b;
}

Funcao* criaFuncao(int tipo, char *nome, Item *prms, Bloco *blc){
	Funcao *f = malloc(sizeof(Funcao));
	if (f == NULL){
		printf("Error ao alocar memória para a função");
		exit(1);
	}
	f->i = 0;
	f->tipo = getTipoId(tipo);
	f->name = strdup(nome);
	f->syms = tbl_sim;
	tbl_sim = NULL;
	f->prms = prms;
	f->blc = blc;
	return f;
}

void AddItem(Item *o, Item *ad){
	while(o->prox)
		o = o->prox;
	o->prox = malloc(sizeof(Item));
	if (o->prox == NULL){
		printf("Erro ao alocar memória para o próximo item");
		exit(1);
	}
	if (o->arv->type == typeId && ad->arv->type == typeId)
		ad->arv->id.i = o->arv->id.i + 1;
	o->prox = ad;
}

void AddListaDecl(ListaDecl *o, ListaDecl *ad){
	while(o->prox != NULL)
		o = o->prox;
	o->prox = malloc(sizeof(ListaDecl));
	if (o->prox == NULL){
		printf("Erro ao alocar memória para a próxima Lista de Declarações");
		exit(1);
	}
	o->prox = ad;
}

void AddFuncao(Funcao *f1, Funcao *f2){
	while(f1->prox != NULL)
		f1 = f1->prox;
	f1->prox = malloc(sizeof(Funcao));
	if (f1->prox == NULL){
		printf("Erro ao alocar memória para a próxima função");
		exit(1);
	}
	f2->i = f1->i + 1;
	f1->prox = f2;
	f2->prox = NULL;
}

void printParametros(Item *prms){
	printf("%s ", getIdTipo(prms->arv->id.tipo));
	printf("%s", prms->arv->id.name);

	if (prms->prox != NULL){
		printf(", ");
		printParametros(prms->prox);
	}
}

void printVariaveis(Item *vars){
	printf("%s", vars->arv->id.name);

	if (vars->prox != NULL){
		printf(", ");
		printVariaveis(vars->prox);
	}
}

void printDeclaracao(Declaracao *decl){
	printf("%s ", getIdTipo(decl->tipo));
	printVariaveis(decl->vars);
	printf(";\n");
}

void printDeclaracoes(ListaDecl *decl){
	printDeclaracao(decl->decl);
	if (decl->prox != NULL)
		printDeclaracoes(decl->prox);
}

void printNo(tipoNo *cmd){
	switch(cmd->type){
		case typeInt:
			printf("%d", cmd->inteiro.val);
			break;
		case typeFloat:
			printf("%f", cmd->real.val);
			break;
		case typeString:
			printf("%s", cmd->string.str);
			break;
		case typeId:
			printf("%s", cmd->id.name);
			break;
		case typeOpr:
			switch(cmd->opr.opr){
				case 1: // Chama Função
					printNo(cmd->opr.op[0]);
					printf("(");
					/* if (cmd->opr.op[1])
						printNo(cmd->opr[1]); */
					printf(")");
					break;
				case 2: // Parâmetros da Função

					break;
				case SIM_ADICAO:
					printNo(cmd->opr.op[0]);
					printf("+");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MULTIPLICACAO:
					printNo(cmd->opr.op[0]);
					printf("*");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_SUBTRACAO:
					printNo(cmd->opr.op[0]);
					printf("-");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_DIVISAO:
					printNo(cmd->opr.op[0]);
					printf("/");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_IGUAL:
					printNo(cmd->opr.op[0]);
					printf("=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_IGUALIGUAL:
					printNo(cmd->opr.op[0]);
					printf("==");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_DIFERENTE:
					printNo(cmd->opr.op[0]);
					printf("!=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MAIORQUE:
					printNo(cmd->opr.op[0]);
					printf(">");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MENORQUE:
					printNo(cmd->opr.op[0]);
					printf("<");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MAIOROUIGUAL:
					printNo(cmd->opr.op[0]);
					printf(">=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MENOROUIGUAL:
					printNo(cmd->opr.op[0]);
					printf("<=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_E:
					printNo(cmd->opr.op[0]);
					printf("&&");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_OU:
					printNo(cmd->opr.op[0]);
					printf("||");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_NEGACAO:
					printf("!");
					printNo(cmd->opr.op[0]);
					break;
				case COM_RETORNO:
					printf("return ");
					printNo(cmd->opr.op[0]);
					break;
				case COM_SE:
					printf("if(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					break;
				case COM_SENAO:
					printf("if(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					printf("else{\n");
					printComandos(cmd->opr.rep->senao);
					printf("}");
					break;
				case COM_ENQUANTO:
					printf("while(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					break;
				case COM_IMPRIME:
					printf("print(");
					printNo(cmd->opr.op[0]);
					printf(")");
					break;
				case COM_LER:
					printf("read(");
					printNo(cmd->opr.op[0]);
					printf(")");
					break;
			}
			break;
	}
}

void printComandos(Item *cmds){
	printNo(cmds->arv);
	printf(";\n");
	if (cmds->prox != NULL)
		printComandos(cmds->prox);
}

void printBloco(Bloco *blc){
	printf("{\n");
	if (blc->decl)
		printDeclaracoes(blc->decl);
	if (blc->cmds)
		printComandos(blc->cmds);
	printf("}\n");
}

void printFuncao(Funcao *f){
	printVariaveis(f->syms);
	printf("\n");
	printf("%s ", getIdTipo(f->tipo));
	printf("%s", f->name);
	
	printf("(");
	if (f->prms != NULL)
		printParametros(f->prms);
	printf(")");

	if (f->blc != NULL)
		printBloco(f->blc);
	

	printf("\n");
	if (f->prox != NULL)
		printFuncao(f->prox);
}