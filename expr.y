%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tipoNo.h"

#define TAM_TABELA_SIMBOLOS 50

int yyerror(const char *);
int yylex();

tipoNo *criaInteger(int);
tipoNo *criaReal(float val);
tipoNo *criaString(char *str);
tipoNo *criaId(char *name);
tipoNo *criaOpr(int opr, int nOps, ...);
void excluirNo(tipoNo *no);
int ex(tipoNo *no);

int sym[TAM_TABELA_SIMBOLOS];
int lastPos = 0;

%}

%union {
	float real;
	int integer;
	char *string;
	char *id;
	tipoNo *nPtr;
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

%type <nPtr> Expr Expra Exprl Exprr Termo Fator ListaFuncoes Funcao TipoRetorno Tipo DeclParametros Parametro Declaracoes Declaracao ListaId Bloco ListaCmd Comando CmdIf CmdWhile CmdAtrib CmdWrite CmdRead ChamadaProc Retorno ListaParametros
%type <id> ChamaFuncao

%%
Programa: ListaFuncoes BlocoPrincipal YYEOF
	| BlocoPrincipal YYEOF
	| YYEOF {exit(0);}
	;
ListaFuncoes: ListaFuncoes Funcao {$$ = $2;}
	| Funcao {$$ = $1;}
	;
Funcao: TipoRetorno TID SIM_ABREPARENTESES DeclParametros SIM_FECHAPARENTESES BlocoPrincipal
	| TipoRetorno TID SIM_ABREPARENTESES SIM_FECHAPARENTESES BlocoPrincipal
	;
TipoRetorno: Tipo {$$ = $1;}
	| TIPO_VOID {$$ = TIPO_VOID;}
	;
DeclParametros: DeclParametros SIM_VIRGULA Parametro {$$ = $3;}
	| Parametro {$$ = $1;}
	;
Parametro: Tipo TID {$$ = criaOpr(TID, 2, $1, criaId($2));}
	;
BlocoPrincipal: SIM_ABRECHAVES Declaracoes ListaCmd SIM_FECHACHAVES
	| SIM_ABRECHAVES Declaracoes SIM_FECHACHAVES
	| SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES
	| SIM_ABRECHAVES SIM_FECHACHAVES
	;
Declaracoes: Declaracoes Declaracao {$$ = $2;}
	| Declaracao {$$ = $1;}
	;
Declaracao: Tipo ListaId SIM_FIM
	;
Tipo: TIPO_INT {$$ = TIPO_INT;}
	| TIPO_STRING {$$ = TIPO_STRING;}
	| TIPO_FLOAT {$$ = TIPO_FLOAT;}
	;
ListaId: ListaId SIM_VIRGULA TID {$$ = criaId($3);}
	| TID {$$ = criaId($1);}
	;
Bloco: SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES {$$ = $2;}
	| SIM_ABRECHAVES SIM_FECHACHAVES
	;
ListaCmd: ListaCmd Comando {$$ = $2;}
	| Comando {$$ = $1;}
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
CmdAtrib: TID SIM_IGUAL Expra SIM_FIM {$$ = criaOpr(SIM_IGUAL, 2, criaId($1), $3);}
	| TID SIM_IGUAL CONS_LITERAL SIM_FIM {$$ = criaOpr(SIM_IGUAL, 2, criaId($1), criaString($3));}
	;
CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_IMPRIME, 1, $3);}
	| COM_IMPRIME SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_IMPRIME, 1, $3);}
	| COM_IMPRIME SIM_ABREPARENTESES CONS_LITERAL SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_IMPRIME, 1, criaString($3));}
	;
CmdRead: COM_LER SIM_ABREPARENTESES TID SIM_FECHAPARENTESES SIM_FIM {criaOpr(COM_LER, 1, criaId($3));}
	;
ChamadaProc: ChamaFuncao SIM_FIM {$$ = $1;}
	;
ChamaFuncao: TID SIM_ABREPARENTESES ListaParametros SIM_FECHAPARENTESES
	| TID SIM_ABREPARENTESES SIM_FECHAPARENTESES
	;
ListaParametros: ListaParametros SIM_VIRGULA Expra {$$ = $3;}
	| ListaParametros SIM_VIRGULA TID {$$ = criaId($3);}
	| Expra {$$ = $1;}
	| TID {$$ = criaId($1);}
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
	| TID {$$ = criaId($1);}
	| ChamaFuncao {$$ = criaId($1);}
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
	strcpy(no->string.str, str);
	return no;
}

tipoNo *criaId(char *name){
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeId);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");
	
	no->type = typeId;
	strcpy(no->id.name, name);
	no->id.i = lastPos;
	lastPos++;
	return no;
}

tipoNo *criaOpr(int opr, int nOps, ...){
	va_list ap;
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeOpr) + (nOps - 1) * sizeof(tipoNo*);
	if ((no = malloc(tam_no)) == NULL)
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
