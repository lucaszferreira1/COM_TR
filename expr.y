%{
#define YYSTYPE double
#include <stdio.h>
#include <stdlib.h>

int yyerror(const char *);
int yylex();
%}

%define parse.error verbose

%token TNUM

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
// Operadores logicos && ||
%token SIM_E SIM_OU 

// ID
%token TID
// Tipos void, int, literal, string e float
%token TIPO_VOID TIPO_INT TIPO_STRING TIPO_FLOAT

// Comandos
// Return 
%token COM_RETORNO
// If e Else
%token COM_SE COM_SENAO
// While
%token COM_ENQUANTO
// Print e Read
%token COM_IMPRIME COM_LER

%%
Programa: ListaFuncoes BlocoPrincipal
	| BlocoPrincipal
	;
ListaFuncoes: ListaFuncoes Funcao
	| Funcao
	;
Funcao: TipoRetorno TID SIM_ABREPARENTESES DeclParametros SIM_FECHAPARENTESES BlocoPrincipal
	| TipoRetorno TID SIM_ABREPARENTESES SIM_FECHAPARENTESES BlocoPrincipal
	;
TipoRetorno: Tipo
	| TIPO_VOID
	;
DeclParametros: DeclParametros SIM_VIRGULA Parametro
	| Parametro
	;
Parametro: Tipo TID
	;
BlocoPrincipal: SIM_ABRECHAVES Declaracoes ListaCmd SIM_FECHACHAVES
	| SIM_ABRECHAVES Declaracao SIM_FECHACHAVES
	;
Declaracoes: Declaracoes Declaracao
	| Declaracao
	;
Declaracao: Tipo ListaId SIM_FIM
	;
Tipo: TIPO_INT
	| TIPO_STRING
	| TIPO_FLOAT
	;
ListaId: ListaId SIM_VIRGULA TID
	| TID
	;
Bloco: SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES
	;
ListaCmd: ListaCmd Comando
	| Comando
	;
Comando: CmdIf
	| CmdWhile
	| CmdAtrib
	| CmdWrite
	| CmdRead
	| ChamadaProc
	| Retorno
	;
Retorno: COM_RETORNO Expra SIM_FIM
	| COM_RETORNO TIPO_STRING SIM_FIM
	| COM_RETORNO SIM_FIM
	;
CmdIf: COM_SE SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES Bloco
	| COM_SE SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES Bloco COM_SENAO Bloco
	;
CmdWhile: COM_ENQUANTO SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES Bloco
	;
CmdAtrib: TID SIM_IGUAL Expra SIM_FIM
	| TID SIM_IGUAL TIPO_STRING SIM_FIM
	;
CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Expra SIM_FECHAPARENTESES SIM_FIM
	| COM_IMPRIME SIM_ABREPARENTESES TIPO_STRING SIM_FECHAPARENTESES SIM_FIM
	;
CmdRead: COM_LER SIM_ABREPARENTESES TID SIM_FECHAPARENTESES SIM_FIM
	;
ChamadaProc: ChamaFuncao SIM_FIM
	;
ChamaFuncao: TID SIM_ABREPARENTESES ListaParametros SIM_FECHAPARENTESES
	| TID SIM_ABREPARENTESES SIM_FECHAPARENTESES
	;
ListaParametros: ListaParametros SIM_VIRGULA Expra
	| ListaParametros SIM_VIRGULA TIPO_STRING
	| Expra
	| TIPO_STRING
	;

Linha :Expra SIM_FIM {printf("Resultado:%lf\n", $1);exit(0);}
	| Exprr SIM_FIM {if ($1 != 0) printf("True"); else printf("False"); exit(0);}
	| Exprl SIM_FIM {if ($1 != 0) printf("True"); else printf("False"); exit(0);}
	;
Expra: Expra SIM_ADICAO Termo {$$ = $1 + $3;}
	| Expra SIM_SUBTRACAO Termo {$$ = $1 - $3;}
	| Termo
	;
Termo: Termo SIM_MULTIPLICACAO FaSIM_OU {$$ = $1 * $3;}
	| Termo SIM_DIVISAO FaSIM_OU {$$ = $1 / $3;}
	| FaSIM_OU
	;
FaSIM_OU: TNUM
	| SIM_ABREPARENTESES Expra SIM_FECHAPARENTESES {$$ = $2;}
	;
Exprr: Expra SIM_IGUALIGUAL Expra {$$ = $1 == $3;}
	| Expra SIM_DIFERENTE Expra {$$ = $1 != $3;}
	| Expra SIM_MAIORQUE Expra {$$ = $1 > $3;}
	| Expra SIM_MENORQUE Expra {$$ = $1 < $3;}
	| Expra SIM_MAIOROUIGUAL Expra {$$ = $1 >= $3;}
	| Expra SIM_MENOROUIGUAL Expra {$$ = $1 <= $3;}
	| Expra
Exprl: Exprr SIM_E Exprr {$$ = $1 && $3;}
	| Exprr SIM_OU Exprr {$$ = $1 || $3;}
%%

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
} 		 

