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
    FUN_MAIN = 258,                /* FUN_MAIN  */
    SIM_ABREPARENTESES = 259,      /* SIM_ABREPARENTESES  */
    SIM_FECHAPARENTESES = 260,     /* SIM_FECHAPARENTESES  */
    SIM_ABRECHAVES = 261,          /* SIM_ABRECHAVES  */
    SIM_FECHACHAVES = 262,         /* SIM_FECHACHAVES  */
    SIM_VIRGULA = 263,             /* SIM_VIRGULA  */
    SIM_ADICAO = 264,              /* SIM_ADICAO  */
    SIM_MULTIPLICACAO = 265,       /* SIM_MULTIPLICACAO  */
    SIM_SUBTRACAO = 266,           /* SIM_SUBTRACAO  */
    SIM_DIVISAO = 267,             /* SIM_DIVISAO  */
    SIM_IGUAL = 268,               /* SIM_IGUAL  */
    SIM_FIM = 269,                 /* SIM_FIM  */
    SIM_IGUALIGUAL = 270,          /* SIM_IGUALIGUAL  */
    SIM_DIFERENTE = 271,           /* SIM_DIFERENTE  */
    SIM_MAIORQUE = 272,            /* SIM_MAIORQUE  */
    SIM_MENORQUE = 273,            /* SIM_MENORQUE  */
    SIM_MAIOROUIGUAL = 274,        /* SIM_MAIOROUIGUAL  */
    SIM_MENOROUIGUAL = 275,        /* SIM_MENOROUIGUAL  */
    SIM_E = 276,                   /* SIM_E  */
    SIM_OU = 277,                  /* SIM_OU  */
    SIM_NEGACAO = 278,             /* SIM_NEGACAO  */
    COM_RETORNO = 279,             /* COM_RETORNO  */
    COM_SE = 280,                  /* COM_SE  */
    COM_SENAO = 281,               /* COM_SENAO  */
    COM_ENQUANTO = 282,            /* COM_ENQUANTO  */
    COM_IMPRIME = 283,             /* COM_IMPRIME  */
    COM_LER = 284,                 /* COM_LER  */
    TIPO_VOID = 285,               /* TIPO_VOID  */
    TIPO_INT = 286,                /* TIPO_INT  */
    TIPO_STRING = 287,             /* TIPO_STRING  */
    TIPO_FLOAT = 288,              /* TIPO_FLOAT  */
    TID = 289,                     /* TID  */
    CONS_INT = 290,                /* CONS_INT  */
    CONS_LITERAL = 291,            /* CONS_LITERAL  */
    CONS_FLOAT = 292               /* CONS_FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "expr.y"

	float real;
	int integer;
	char *string;
	char *id;

#line 108 "expr.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_EXPR_TAB_H_INCLUDED  */
