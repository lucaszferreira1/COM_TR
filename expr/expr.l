%option noyywrap

%{
#define YYSTYPE double
#include "expr.tab.h"
#include <stdlib.h>
%}


delim	[ \t]
ws	{delim}+
digito	[0-9]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
char .
string {char}

%%
{ws}	{}

"return" {return CRETURN;}
"void" {return TVOID;}
"int" {return TINT;}
"literal" {return TLITERAL;}
"string" {return TSTRING;}
"float" {return TFLOAT;}
"if" {return CIF;}
"else" {return CELSE;}
"while" {return CWHILE;}
"print" {return CPRINT;}
"read" {return CREAD;}

"+"	{return TADD;}
"-"	{return TSUB;}
"*"	{return TMUL;}
"/"	{return TDIV;}
"("	{return TAPAR;}
")"	{return TFPAR;}
"=" {return TEQU;}
"==" {return TEQQ;}
"!=" {return TDIF;}
">" {return TGTH;}
"<" {return TLTH;}
">=" {return TGTE;}
"<=" {return TLTE;}
"&&" {return TAND;}
"and" {return TAND;}
"||" {return TOR;}
"or" {return TOR;}
"," {return TVIR;}
\n	{return TFIM;}
{num}	{yylval=atof(yytext); return TNUM;} 
