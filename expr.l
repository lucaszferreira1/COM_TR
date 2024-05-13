%option noyywrap

%{
#include "expr.tab.h"
#include <stdlib.h>
#include <string.h>
%}

delim [ \t]
num [0-9]

id [a-zA-Z_][a-zA-Z0-9_]*
int {num}+
string \"([^"\n]|\"\")+\"
float {num}+"."{num}*

ws	{delim}+


%%
{ws}	{}

"main" {return FUN_MAIN;}

"void" {return TIPO_VOID;}
"int" {return TIPO_INT;}
"string" {return TIPO_STRING;}
"float" {return TIPO_FLOAT;}

{int} {yylval.integer = atoi(yytext); return CONS_INT;}
{string} {yylval.string = strdup(yytext); return CONS_LITERAL;}
{float} {yylval.real = atof(yytext); return CONS_FLOAT;}

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
";"	{return SIM_FIM;}

{id} {yylval.string = strdup(yytext); return TID;}
%%