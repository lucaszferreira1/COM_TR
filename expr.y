%{
#define YYSTYPE double
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRADAS 10000
#define TAM_MAX_NOME 100

int yyerror(const char *);
int yylex();

typedef enum{
	TID,
	INT,
	FLOAT,
	STRING
} TipoToken;

typedef struct Entrada{
	char name[TAM_MAX_NOME];
	TipoToken tipo;
} Entrada;

typedef struct TabelaEntradas{
	Entrada entradas[MAX_ENTRADAS];
	int count;
} TabelaEntradas;

TabelaEntradas *tabela_entradas;

void symtable_insert(TabelaEntradas *tabela, const char *nome, TipoToken tipo){
	if (tabela.count < MAX_ENTRADAS){
		Entrada *entrada = &tabela->entradas[tabela->count++];
		strncpy(entrada->nome, nome, TAM_MAX_NOME - 1);
		entrada->tipo = tipo;
	}
}

Entrada* symtable_lookup(TabelaEntradas *tabela, const char *nome){
	for (int i=0;i<tabela->count;i++){
		if (strcmp(tabela->entrada[i].nome, nome) == 0){
			return &tabela->entrada[i];
		}
	}
	return NULL;
}

%}

%union {
	int int;
	float float;
	char *string;
	char *id;
}

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

// ID
%token <id>TID
// Tipos void, int, literal, string e float
%token TIPO_VOID TIPO_INT TIPO_STRING TIPO_FLOAT
%token <int>CONS_INT <string>CONS_LITERAL <float>CONS_FLOAT

// Fim do arquivo
%token TFIM

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
	| BlocoPrincipal TFIM
	| TFIM
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
	{symtable_insert(tabela, $2)}
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
	{printf("%s", $2);}
	| COM_IMPRIME SIM_ABREPARENTESES TIPO_STRING SIM_FECHAPARENTESES SIM_FIM
	{printf("%s", $2);}
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
Expra: Expra SIM_ADICAO Termo {$$ = $1 + $3;}
	| Expra SIM_SUBTRACAO Termo {$$ = $1 - $3;}
	| Termo
	;
Termo: Termo SIM_MULTIPLICACAO Fator {$$ = $1 * $3;}
	| Termo SIM_DIVISAO Fator {$$ = $1 / $3;}
	| Fator
	;
Fator: TID
	| SIM_ABREPARENTESES Expra SIM_FECHAPARENTESES {$$ = $2;}
	;
Exprr: Expra SIM_IGUALIGUAL Expra {$$ = $1 == $3;}
	| Expra SIM_DIFERENTE Expra {$$ = $1 != $3;}
	| Expra SIM_MAIORQUE Expra {$$ = $1 > $3;}
	| Expra SIM_MENORQUE Expra {$$ = $1 < $3;}
	| Expra SIM_MAIOROUIGUAL Expra {$$ = $1 >= $3;}
	| Expra SIM_MENOROUIGUAL Expra {$$ = $1 <= $3;}
	| Expra
Exprl: SIM_NEGACAO Exprl {$$ = !$2;}
	| Exprl SIM_E Exprl {$$ = $1 && $3;}
	| Exprl SIM_OU Exprl {$$ = $1 || $3;}
	| Exprr
%%

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
} 		 

