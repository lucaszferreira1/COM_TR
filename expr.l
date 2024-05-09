%option noyywrap

%{
#define YYSTYPE double
#include "expr.tab.h"
#include <stdlib.h>
#include <string.h>
%}


delim	[ \t]
num [0-9]
char [a-zA-Z]

id [a-zA-Z_][a-zA-Z0-9_]*
int {num}+
string \"([^"\n]|\"\")+\"
float {int}+"."{num}*

ws	{delim}+


%%
{ws}	{}

"void" {return TIPO_VOID;}
{id} {yylval.string = strdup(yytext); return TID;}
{int} {yylval.int = atoi(yytext); return TIPO_INT;}
{string} {yylval.string = strdup(yytext + 1); return TIPO_STRING;}
{float} {yylval.float = atof(yytext); return TIPO_FLOAT;}

"return" {return COM_RETORNO;}
"if" {return COM_SE;}
"else" {return COM_SENAO;}
"while" {return COM_ENQUANTO;}
"print" {return COM_IMPRIME;}
"read" {return COM_LER;}

"+"	{return SIM_ADICAO;}
"-"	{return SIM_SUBTRACAO;}
"*"	{return SIM_MULTIPLICACAO;}
"/"	{return SIM_DIVISAO;}
"("	{return SIM_ABREPARENTESES;}
")"	{return SIM_FECHAPARENTESES;}
"{" {return SIM_ABRECHAVES;}
"}" {return SIM_FECHACHAVES;}
"=" {return SIM_IGUAL;}
"==" {return SIM_IGUALIGUAL;}
"!=" {return SIM_DIFERENTE;}
">" {return SIM_MAIORQUE;}
"<" {return SIM_MENORQUE;}
">=" {return SIM_MAIOROUIGUAL;}
"<=" {return SIM_MENOROUIGUAL;}
"!" {return SIM_NEGACAO;}
"&&" {return SIM_E;}
"and" {return SIM_E;}
"||" {return SIM_OU;}
"or" {return SIM_OU;}
"," {return SIM_VIRGULA;}
\n	{return SIM_FIM;}
<<EOF>> {return TFIM;}

%%