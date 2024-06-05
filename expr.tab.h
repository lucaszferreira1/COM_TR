/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_EXPR_TAB_H_INCLUDED
# define YY_YY_EXPR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SIM_ABREPARENTESES = 258,      /* SIM_ABREPARENTESES  */
    SIM_FECHAPARENTESES = 259,     /* SIM_FECHAPARENTESES  */
    SIM_ABRECHAVES = 260,          /* SIM_ABRECHAVES  */
    SIM_FECHACHAVES = 261,         /* SIM_FECHACHAVES  */
    SIM_VIRGULA = 262,             /* SIM_VIRGULA  */
    SIM_ADICAO = 263,              /* SIM_ADICAO  */
    SIM_MULTIPLICACAO = 264,       /* SIM_MULTIPLICACAO  */
    SIM_SUBTRACAO = 265,           /* SIM_SUBTRACAO  */
    SIM_DIVISAO = 266,             /* SIM_DIVISAO  */
    SIM_IGUAL = 267,               /* SIM_IGUAL  */
    SIM_FIM = 268,                 /* SIM_FIM  */
    SIM_IGUALIGUAL = 269,          /* SIM_IGUALIGUAL  */
    SIM_DIFERENTE = 270,           /* SIM_DIFERENTE  */
    SIM_MAIORQUE = 271,            /* SIM_MAIORQUE  */
    SIM_MENORQUE = 272,            /* SIM_MENORQUE  */
    SIM_MAIOROUIGUAL = 273,        /* SIM_MAIOROUIGUAL  */
    SIM_MENOROUIGUAL = 274,        /* SIM_MENOROUIGUAL  */
    SIM_E = 275,                   /* SIM_E  */
    SIM_OU = 276,                  /* SIM_OU  */
    SIM_NEGACAO = 277,             /* SIM_NEGACAO  */
    COM_RETORNO = 278,             /* COM_RETORNO  */
    COM_SE = 279,                  /* COM_SE  */
    COM_SENAO = 280,               /* COM_SENAO  */
    COM_ENQUANTO = 281,            /* COM_ENQUANTO  */
    COM_IMPRIME = 282,             /* COM_IMPRIME  */
    COM_LER = 283,                 /* COM_LER  */
    TIPO_VOID = 284,               /* TIPO_VOID  */
    TIPO_INT = 285,                /* TIPO_INT  */
    TIPO_STRING = 286,             /* TIPO_STRING  */
    TIPO_FLOAT = 287,              /* TIPO_FLOAT  */
    TID = 288,                     /* TID  */
    CONS_INT = 289,                /* CONS_INT  */
    CONS_LITERAL = 290,            /* CONS_LITERAL  */
    CONS_FLOAT = 291               /* CONS_FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
#include "tipoNo.h"
union YYSTYPE
{
#line 33 "expr.y"

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

#line 113 "expr.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_EXPR_TAB_H_INCLUDED  */
