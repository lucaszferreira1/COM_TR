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
%token TAPAR TFPAR TACHA TFCHA 
// Virgula ,
%token TVIR
// Operadores aritmeticos + * - /
%token TADD TMUL TSUB TDIV
// Igual =
%token TEQU 
// Ponto e virgula ;
%token TFIM 
// Operadores relacionais == != > < >= <=
%token TEQQ TDIF TGTH TLTH TGTE TLTE 
// Operadores logicos && ||
%token TAND TOR 


%token TID
%token CRETURN
%token TVOID TINT TLITERAL TSTRING TFLOAT
%token CIF CELSE
%token CWHILE
%token CPRINT CREAD

%%
Programa: ListaFuncoes BlocoPrincipal
	| BlocoPrincipal
	;
ListaFuncoes: ListaFuncoes Funcao
	| Funcao
	;
Funcao: TipoRetorno TID TAPAR DeclParametros TFPAR BlocoPrincipal
	| TipoRetorno TID TAPAR TFPAR BlocoPrincipal
	;
TipoRetorno: Tipo
	| TVOID
	;
DeclParametros: DeclParametros TVIR Parametro
	| Parametro
	;
Parametro: Tipo TID
	;
BlocoPrincipal: TACHA Declaracoes ListaCmd TFCHA
	| TACHA Declaracao TFCHA
	;
Declaracoes: Declaracoes Declaracao
	| Declaracao
	;
Declaracao: Tipo ListaId TFIM
	;
Tipo: TINT
	| TSTRING
	| TFLOAT
	;
ListaId: ListaId TVIR TID
	| TID
	;
Bloco: TACHA ListaCmd TFCHA
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
Retorno: CRETURN Expra TFIM
	| CRETURN TLITERAL TFIM
	| CRETURN TFIM
	;
CmdIf: CIF TAPAR Exprl TFPAR Bloco
	| CIF TAPAR Exprl TFPAR Bloco CELSE Bloco
	;
CmdWhile: CWHILE TAPAR Exprl TFPAR Bloco
	;
CmdAtrib: TID TEQU Expra TFIM
	| TID TEQU TLITERAL TFIM
	;
CmdWrite: CPRINT TAPAR Expra TFPAR TFIM
	| CPRINT TAPAR TLITERAL TFPAR TFIM
	;
CmdRead: CREAD TAPAR TID TFPAR TFIM
	;
ChamadaProc: ChamaFuncao TFIM
	;
ChamaFuncao: TID TAPAR ListaParametros TFPAR
	| TID TAPAR TFPAR
	;
ListaParametros: ListaParametros TVIR Expra
	| ListaParametros TVIR TLITERAL
	| Expra
	| TLITERAL
	;

Linha :Expra TFIM {printf("Resultado:%lf\n", $1);exit(0);}
	| Exprr TFIM {if ($1 != 0) printf("True"); else printf("False"); exit(0);}
	| Exprl TFIM {if ($1 != 0) printf("True"); else printf("False"); exit(0);}
	;
Expra: Expra TADD Termo {$$ = $1 + $3;}
	| Expra TSUB Termo {$$ = $1 - $3;}
	| Termo
	;
Termo: Termo TMUL Fator {$$ = $1 * $3;}
	| Termo TDIV Fator {$$ = $1 / $3;}
	| Fator
	;
Fator: TNUM 
	| TAPAR Expra TFPAR {$$ = $2;}
	;
Exprr: Expra TEQQ Expra {$$ = $1 == $3;}
	| Expra TDIF Expra {$$ = $1 != $3;}
	| Expra TGTH Expra {$$ = $1 > $3;}
	| Expra TLTH Expra {$$ = $1 < $3;}
	| Expra TGTE Expra {$$ = $1 >= $3;}
	| Expra TLTE Expra {$$ = $1 <= $3;}
	| Expra
Exprl: Exprr TAND Exprr {$$ = $1 && $3;}
	| Exprr TOR Exprr {$$ = $1 || $3;}
%%

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
} 		 

