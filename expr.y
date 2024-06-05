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
tipoNo *criaOpr(int opr, int nOps, ...);
void excluirNo(tipoNo *no);
Funcao* criaFuncao(int tipo, char *nome, Item *prms, Bloco *blc);
ListaDecl *criaListaDecl(Declaracao *decl);
Declaracao* criaDeclaracao(int tipo, Item *vars);
Bloco* criaBloco(ListaDecl *decl, Item *cmds);
Item* criaItem(tipoNo *arv);
void AddListaDecl(ListaDecl *o, ListaDecl *ad);
void AddItem(Item *o, Item *ad);

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
Programa: ListaFuncoes BlocoPrincipal YYEOF {criaFuncao(TIPO_INT, NULL, NULL, $2);}
	| BlocoPrincipal YYEOF {criaFuncao(285, "main", NULL, $1);}
	| YYEOF {exit(0);}
	;
ListaFuncoes: ListaFuncoes Funcao {}
	| Funcao {}
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
Retorno: COM_RETORNO Expra SIM_FIM {$$ = criaOpr(COM_RETORNO, 1, $2);}
	| COM_RETORNO CONS_LITERAL SIM_FIM {$$ = criaOpr(COM_RETORNO, 1, criaString($2));}
	| COM_RETORNO SIM_FIM {$$ = criaOpr(COM_RETORNO, 0);}
	;
CmdIf: COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco {$$ = criaOpr(COM_SE, 2, $3, $5);}
	| COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco COM_SENAO Bloco {$$ = criaOpr(COM_SE, 3, $3, $5, $7);}
	;
CmdWhile: COM_ENQUANTO SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco {$$ = criaOpr(COM_ENQUANTO, 2, $3, $5);}
	;
CmdAtrib: TID SIM_IGUAL Expra SIM_FIM {$$ = criaOpr(SIM_IGUAL, 2, criaId($1, 0), $3);}
	| TID SIM_IGUAL CONS_LITERAL SIM_FIM {$$ = criaOpr(SIM_IGUAL, 2, criaId($1, 0), criaString($3));}
	;
CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_IMPRIME, 1, $3);}
	| COM_IMPRIME SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_IMPRIME, 1, $3);}
	| COM_IMPRIME SIM_ABREPARENTESES CONS_LITERAL SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_IMPRIME, 1, criaString($3));}
	;
CmdRead: COM_LER SIM_ABREPARENTESES TID SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_LER, 1, criaId($3, 0));}
	;
ChamadaProc: ChamaFuncao SIM_FIM {$$ = $1;}
	;
ChamaFuncao: TID SIM_ABREPARENTESES ListaParametros SIM_FECHAPARENTESES {$$ = criaOpr(1, 2, criaId($1, 0), $3);}
	| TID SIM_ABREPARENTESES SIM_FECHAPARENTESES {$$ = criaOpr(1, 1, criaId($1, 0));}
	;
ListaParametros: Expra SIM_VIRGULA ListaParametros {$$ = criaOpr(1, 2, $1, $3);}
	| TID SIM_VIRGULA ListaParametros {$$ = criaOpr(1, 2, criaId($1, 0), $3);}
	| Expra {$$ = $1;}
	| TID {$$ = criaId($1, 0);}
	;

Expr: Exprl {$$ = $1;}
	| Expra {$$ = $1;}
	| Exprr {$$ = $1;}
	;
Exprr: Exprr SIM_MAIORQUE Expra {$$ = criaOpr(SIM_MAIORQUE, 2, $1, $3);}
	| Exprr SIM_MENORQUE Expra {$$ = criaOpr(SIM_MENORQUE, 2, $1, $3);}
	| Exprr SIM_MAIOROUIGUAL Expra {$$ = criaOpr(SIM_MAIOROUIGUAL, 2, $1, $3);}
	| Exprr SIM_MENOROUIGUAL Expra {$$ = criaOpr(SIM_MENOROUIGUAL, 2, $1, $3);}
	| Exprr SIM_IGUALIGUAL Expra {$$ = criaOpr(SIM_IGUALIGUAL, 2, $1, $3);}
	| Exprr SIM_DIFERENTE Expra {$$ = criaOpr(SIM_DIFERENTE, 2, $1, $3);}
	| Expra {$$ = $1;}
	;
Expra: Expra SIM_ADICAO Termo {$$ = criaOpr(SIM_ADICAO, 2, $1, $3);}
	| Expra SIM_SUBTRACAO Termo {$$ = criaOpr(SIM_SUBTRACAO, 2, $1, $3);}
	| Termo {$$ = $1;}
	;
Termo: Termo SIM_MULTIPLICACAO Fator {$$ = criaOpr(SIM_MULTIPLICACAO, 2, $1, $3);}
	| Termo SIM_DIVISAO Fator {$$ = criaOpr(SIM_DIVISAO, 2, $1, $3);}
	| Fator {$$ = $1;}
	;
Fator: CONS_INT {$$ = criaInteger($1);}
	| CONS_FLOAT {$$ = criaReal($1);}
	| TID {$$ = criaId($1, 0);}
	| ChamaFuncao {$$ = $1;}
	| SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES {$$ = $2;}
	;
Exprl: Exprl SIM_E Expra {$$ = criaOpr(SIM_E, 2, $1, $3);}
	| Exprl SIM_OU Expra {$$ = criaOpr(SIM_OU, 2, $1, $3);}
	| SIM_NEGACAO Expra {$$ = criaOpr(SIM_NEGACAO, 1, $2);}
	| Expra {$$ = $1;}
	;
%%
#define SIZEOF_TIPONO ((char *)&no->inteiro - (char *)no)

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
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
	no->id.tipo = tipo;
	return no;
}

tipoNo *criaOpr(int opr, int nOps, ...){
	va_list ap;
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeOpr) + (nOps - 1) * sizeof(tipoNo*);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");
	if ((no->opr.op = malloc(nOps * sizeof(tipoNo*))) == NULL)
		yyerror("Sem memória");

	no->type = typeOpr;
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

Item* criaItem(tipoNo *arv){
	Item *i = malloc(sizeof(Item*));
	if (i == NULL){
		printf("Error ao alocar memória para o Item");
		exit(1);
	}
	i->prox = NULL;
	i->arv = arv;
	return i;
}

Declaracao* criaDeclaracao(int tipo, Item *vars){
	Declaracao *d = malloc(sizeof(Declaracao*));
	if (d == NULL){
		printf("Error ao alocar memória para as Declarações");
		exit(1);
	}
	d->tipo = getTipoId(tipo);
	d->vars = vars;
	return d;
}

ListaDecl *criaListaDecl(Declaracao *decl){
	ListaDecl *l = malloc(sizeof(ListaDecl*));
	if (l == NULL){
		printf("Error ao alocar memória para a Lista de Declarações");
		exit(1);
	}
	l->prox = NULL;
	l->decl = decl;
	return l;
}

Bloco* criaBloco(ListaDecl *decl, Item *cmds){
	Bloco* b = malloc(sizeof(Bloco*));
	if (b == NULL){
		printf("Error ao alocar memória para o Bloco");
		exit(1);
	}
	b->decl = decl;
	b->cmds = cmds;
	return b;
}

Funcao* criaFuncao(int tipo, char *nome, Item *prms, Bloco *blc){
	Funcao *f = malloc(sizeof(Funcao*));
	if (f == NULL){
		printf("Error ao alocar memória para a função");
		exit(1);
	}
	f->tipo = getTipoId(tipo);
	f->name = strdup(nome);
	f->syms = NULL;
	f->prms = prms;
	f->blc = blc;
	return f;
}

void AddItem(Item *o, Item *ad){
	while(o->prox)
		o = o->prox;
	o->prox = malloc(sizeof(Item*));
	o = ad;
}

void AddListaDecl(ListaDecl *o, ListaDecl *ad){
	while(o->prox)
		o = o->prox;
	o->prox = malloc(sizeof(ListaDecl*));
	o = ad;
}