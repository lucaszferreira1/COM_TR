/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "expr.y"

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
tipoNo *criaOpr(int opr, Repeticao *rep, int nOps, ...);
void excluirNo(tipoNo *no);
Funcao* criaFuncao(int tipo, char *nome, Item *prms, Bloco *blc);
ListaDecl *criaListaDecl(Declaracao *decl);
Declaracao* criaDeclaracao(int tipo, Item *vars);
Bloco* criaBloco(ListaDecl *decl, Item *cmds);
Item* criaItem(tipoNo *arv);
Repeticao* criaRepeticao(Item *cmds, Item *senao);
void AddListaDecl(ListaDecl *o, ListaDecl *ad);
void AddItem(Item *o, Item *ad);
void AddFuncao(Funcao *f1, Funcao *f2);
void printFuncao(Funcao *f);
void printComandos(Item *cmds);
tipoNo* lookupFunc(char *n);

Funcao *tbl_fun;
Funcao *temp_fun;
Item *tbl_sim;
int tp_sim;
int tp_fun;


#line 112 "expr.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "expr.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SIM_ABREPARENTESES = 3,         /* SIM_ABREPARENTESES  */
  YYSYMBOL_SIM_FECHAPARENTESES = 4,        /* SIM_FECHAPARENTESES  */
  YYSYMBOL_SIM_ABRECHAVES = 5,             /* SIM_ABRECHAVES  */
  YYSYMBOL_SIM_FECHACHAVES = 6,            /* SIM_FECHACHAVES  */
  YYSYMBOL_SIM_VIRGULA = 7,                /* SIM_VIRGULA  */
  YYSYMBOL_SIM_ADICAO = 8,                 /* SIM_ADICAO  */
  YYSYMBOL_SIM_MULTIPLICACAO = 9,          /* SIM_MULTIPLICACAO  */
  YYSYMBOL_SIM_SUBTRACAO = 10,             /* SIM_SUBTRACAO  */
  YYSYMBOL_SIM_DIVISAO = 11,               /* SIM_DIVISAO  */
  YYSYMBOL_SIM_IGUAL = 12,                 /* SIM_IGUAL  */
  YYSYMBOL_SIM_FIM = 13,                   /* SIM_FIM  */
  YYSYMBOL_SIM_IGUALIGUAL = 14,            /* SIM_IGUALIGUAL  */
  YYSYMBOL_SIM_DIFERENTE = 15,             /* SIM_DIFERENTE  */
  YYSYMBOL_SIM_MAIORQUE = 16,              /* SIM_MAIORQUE  */
  YYSYMBOL_SIM_MENORQUE = 17,              /* SIM_MENORQUE  */
  YYSYMBOL_SIM_MAIOROUIGUAL = 18,          /* SIM_MAIOROUIGUAL  */
  YYSYMBOL_SIM_MENOROUIGUAL = 19,          /* SIM_MENOROUIGUAL  */
  YYSYMBOL_SIM_E = 20,                     /* SIM_E  */
  YYSYMBOL_SIM_OU = 21,                    /* SIM_OU  */
  YYSYMBOL_SIM_NEGACAO = 22,               /* SIM_NEGACAO  */
  YYSYMBOL_COM_RETORNO = 23,               /* COM_RETORNO  */
  YYSYMBOL_COM_SE = 24,                    /* COM_SE  */
  YYSYMBOL_COM_SENAO = 25,                 /* COM_SENAO  */
  YYSYMBOL_COM_ENQUANTO = 26,              /* COM_ENQUANTO  */
  YYSYMBOL_COM_IMPRIME = 27,               /* COM_IMPRIME  */
  YYSYMBOL_COM_LER = 28,                   /* COM_LER  */
  YYSYMBOL_TIPO_VOID = 29,                 /* TIPO_VOID  */
  YYSYMBOL_TIPO_INT = 30,                  /* TIPO_INT  */
  YYSYMBOL_TIPO_STRING = 31,               /* TIPO_STRING  */
  YYSYMBOL_TIPO_FLOAT = 32,                /* TIPO_FLOAT  */
  YYSYMBOL_TID = 33,                       /* TID  */
  YYSYMBOL_CONS_INT = 34,                  /* CONS_INT  */
  YYSYMBOL_CONS_LITERAL = 35,              /* CONS_LITERAL  */
  YYSYMBOL_CONS_FLOAT = 36,                /* CONS_FLOAT  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_Programa = 38,                  /* Programa  */
  YYSYMBOL_Main = 39,                      /* Main  */
  YYSYMBOL_ListaFuncoes = 40,              /* ListaFuncoes  */
  YYSYMBOL_Funcao = 41,                    /* Funcao  */
  YYSYMBOL_TipoRetorno = 42,               /* TipoRetorno  */
  YYSYMBOL_DeclParametros = 43,            /* DeclParametros  */
  YYSYMBOL_Parametro = 44,                 /* Parametro  */
  YYSYMBOL_BlocoPrincipal = 45,            /* BlocoPrincipal  */
  YYSYMBOL_Declaracoes = 46,               /* Declaracoes  */
  YYSYMBOL_Declaracao = 47,                /* Declaracao  */
  YYSYMBOL_Tipo = 48,                      /* Tipo  */
  YYSYMBOL_ListaId = 49,                   /* ListaId  */
  YYSYMBOL_Bloco = 50,                     /* Bloco  */
  YYSYMBOL_ListaCmd = 51,                  /* ListaCmd  */
  YYSYMBOL_Comando = 52,                   /* Comando  */
  YYSYMBOL_Retorno = 53,                   /* Retorno  */
  YYSYMBOL_CmdIf = 54,                     /* CmdIf  */
  YYSYMBOL_CmdWhile = 55,                  /* CmdWhile  */
  YYSYMBOL_CmdAtrib = 56,                  /* CmdAtrib  */
  YYSYMBOL_CmdWrite = 57,                  /* CmdWrite  */
  YYSYMBOL_CmdRead = 58,                   /* CmdRead  */
  YYSYMBOL_ChamadaProc = 59,               /* ChamadaProc  */
  YYSYMBOL_ChamaFuncao = 60,               /* ChamaFuncao  */
  YYSYMBOL_ListaParametros = 61,           /* ListaParametros  */
  YYSYMBOL_Expr = 62,                      /* Expr  */
  YYSYMBOL_Exprr = 63,                     /* Exprr  */
  YYSYMBOL_Expra = 64,                     /* Expra  */
  YYSYMBOL_Termo = 65,                     /* Termo  */
  YYSYMBOL_Fator = 66,                     /* Fator  */
  YYSYMBOL_Exprl = 67                      /* Exprl  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   103,   103,   104,   105,   107,   108,   109,   111,   112,
     114,   115,   117,   118,   120,   122,   123,   124,   126,   127,
     129,   131,   132,   133,   135,   136,   138,   140,   141,   143,
     144,   145,   146,   147,   148,   149,   151,   152,   153,   155,
     156,   158,   160,   161,   163,   164,   165,   167,   169,   171,
     172,   174,   175,   176,   177,   180,   181,   182,   184,   185,
     186,   187,   188,   189,   190,   192,   193,   194,   196,   197,
     198,   200,   201,   202,   203,   204,   205,   207,   208,   209,
     210
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SIM_ABREPARENTESES",
  "SIM_FECHAPARENTESES", "SIM_ABRECHAVES", "SIM_FECHACHAVES",
  "SIM_VIRGULA", "SIM_ADICAO", "SIM_MULTIPLICACAO", "SIM_SUBTRACAO",
  "SIM_DIVISAO", "SIM_IGUAL", "SIM_FIM", "SIM_IGUALIGUAL", "SIM_DIFERENTE",
  "SIM_MAIORQUE", "SIM_MENORQUE", "SIM_MAIOROUIGUAL", "SIM_MENOROUIGUAL",
  "SIM_E", "SIM_OU", "SIM_NEGACAO", "COM_RETORNO", "COM_SE", "COM_SENAO",
  "COM_ENQUANTO", "COM_IMPRIME", "COM_LER", "TIPO_VOID", "TIPO_INT",
  "TIPO_STRING", "TIPO_FLOAT", "TID", "CONS_INT", "CONS_LITERAL",
  "CONS_FLOAT", "$accept", "Programa", "Main", "ListaFuncoes", "Funcao",
  "TipoRetorno", "DeclParametros", "Parametro", "BlocoPrincipal",
  "Declaracoes", "Declaracao", "Tipo", "ListaId", "Bloco", "ListaCmd",
  "Comando", "Retorno", "CmdIf", "CmdWhile", "CmdAtrib", "CmdWrite",
  "CmdRead", "ChamadaProc", "ChamaFuncao", "ListaParametros", "Expr",
  "Exprr", "Expra", "Termo", "Fator", "Exprl", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,  -108,  -108,  -108,  -108,  -108,    23,    90,   189,  -108,
      11,  -108,  -108,   167,   117,    90,  -108,   121,    13,   127,
     128,   142,   149,     5,   109,  -108,   124,   120,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,   151,  -108,   172,    79,
      31,  -108,   174,  -108,   160,  -108,  -108,    -4,    75,  -108,
      17,    17,    21,   159,    25,    35,  -108,  -108,   132,  -108,
       6,  -108,  -108,  -108,  -108,    90,    95,  -108,   163,  -108,
     164,    70,  -108,    31,    31,  -108,    31,    31,    31,   171,
     198,    77,    10,   199,   203,   170,   108,     1,   204,  -108,
     147,   205,   112,   197,    69,  -108,   190,  -108,  -108,    90,
     131,  -108,  -108,    31,    31,    31,    31,    31,    31,    75,
      75,  -108,  -108,    70,   217,    31,    31,   217,   211,   212,
     213,   214,    39,  -108,    39,  -108,  -108,  -108,  -108,  -108,
      70,    70,    70,    70,    70,    70,   178,   206,    70,    70,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,   143,   217,  -108,
    -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     4,    11,    21,    22,    23,     0,     0,     5,     7,
       0,    10,     1,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,    28,    35,
      29,    30,    31,    32,    33,    34,     0,     3,     0,     0,
       0,    38,    74,    71,    73,    72,    75,     0,    67,    70,
       0,     0,     0,     0,     0,     0,    16,    18,     0,    25,
       0,    17,    27,    48,     2,     0,     0,    13,     0,    73,
       0,    64,    37,     0,     0,    36,     0,     0,     0,     0,
      57,    64,    55,     0,    73,     0,    64,     0,     0,    50,
      74,     0,    53,    73,     0,    15,     0,    20,     9,     0,
       0,    14,    76,     0,     0,     0,     0,     0,     0,    65,
      66,    68,    69,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,    43,    42,    24,     8,    12,
      62,    63,    58,    59,    60,    61,     0,    39,    77,    78,
      41,    46,    44,    45,    47,    52,    51,     0,     0,    26,
      40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   220,  -108,   221,  -108,  -108,   130,    -3,  -108,
     208,    -6,  -108,  -107,   -22,   -26,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,   -13,     3,   182,   -25,   -15,    30,    36,
     183
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    66,    67,    14,    24,
      25,    11,    60,   137,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    46,    91,    79,    80,    92,    48,    49,
      82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    62,    58,    47,    73,   120,    74,    26,    54,    75,
     140,    36,    38,    96,    36,    70,    40,    55,    26,    97,
      40,   115,   116,    12,    40,    71,    41,    85,    40,    89,
     115,   116,    62,    68,    40,    81,    81,    86,    40,    78,
      94,   150,    40,    78,    17,    36,    42,    43,    44,    45,
      42,    43,    69,    45,    42,    43,    84,    45,    90,    43,
      69,    45,    98,   113,    42,    43,    69,    45,    42,    43,
      93,    45,    90,    43,    69,    45,     1,    73,    73,    74,
      74,   -56,   126,    65,    76,    73,    77,    74,   130,   131,
     132,   133,   134,   135,    68,    13,   128,   -80,   -80,    99,
     138,   139,   100,   109,   110,     2,     3,     4,     5,     3,
       4,     5,   111,   112,   147,    56,    73,    37,    74,   124,
      73,    62,    74,    36,    39,   145,    61,   146,   -80,   -80,
      50,    51,    18,    19,    36,    20,    21,    22,    95,     3,
       4,     5,    23,    18,    19,    52,    20,    21,    22,   149,
      54,   -54,    53,    23,   122,    18,    19,    59,    20,    21,
      22,     3,     4,     5,    63,    23,    18,    19,   102,    20,
      21,    22,    64,    72,   119,   114,    23,    54,   103,   104,
     105,   106,   107,   108,   103,   104,   105,   106,   107,   108,
      18,    19,    88,    20,    21,    22,   101,     3,     4,     5,
      23,    18,    19,   117,    20,    21,    22,   118,   121,   123,
     125,    23,   103,   104,   105,   106,   107,   108,     2,     3,
       4,     5,   136,   127,   141,   142,   143,   144,    15,    16,
     129,   148,    57,    83,     0,    87
};

static const yytype_int16 yycheck[] =
{
      13,    27,    24,    18,     8,     4,    10,    13,     3,    13,
     117,    24,    15,     7,    27,    40,     3,    12,    24,    13,
       3,    20,    21,     0,     3,    40,    13,    52,     3,     4,
      20,    21,    58,    39,     3,    50,    51,    52,     3,    22,
      55,   148,     3,    22,    33,    58,    33,    34,    35,    36,
      33,    34,    35,    36,    33,    34,    35,    36,    33,    34,
      35,    36,    65,    78,    33,    34,    35,    36,    33,    34,
      35,    36,    33,    34,    35,    36,     0,     8,     8,    10,
      10,     4,    13,     4,     9,     8,    11,    10,   103,   104,
     105,   106,   107,   108,   100,     5,    99,    20,    21,     4,
     115,   116,     7,    73,    74,    29,    30,    31,    32,    30,
      31,    32,    76,    77,   136,     6,     8,     0,    10,     7,
       8,   147,    10,   136,     3,   122,     6,   124,    20,    21,
       3,     3,    23,    24,   147,    26,    27,    28,     6,    30,
      31,    32,    33,    23,    24,     3,    26,    27,    28,     6,
       3,     4,     3,    33,     7,    23,    24,    33,    26,    27,
      28,    30,    31,    32,    13,    33,    23,    24,     4,    26,
      27,    28,     0,    13,     4,     4,    33,     3,    14,    15,
      16,    17,    18,    19,    14,    15,    16,    17,    18,    19,
      23,    24,    33,    26,    27,    28,    33,    30,    31,    32,
      33,    23,    24,     4,    26,    27,    28,     4,     4,     4,
      13,    33,    14,    15,    16,    17,    18,    19,    29,    30,
      31,    32,     5,    33,    13,    13,    13,    13,     8,     8,
     100,    25,    24,    51,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,    29,    30,    31,    32,    38,    39,    40,    41,
      42,    48,     0,     5,    45,    39,    41,    33,    23,    24,
      26,    27,    28,    33,    46,    47,    48,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,    45,     3,
       3,    13,    33,    34,    35,    36,    60,    64,    65,    66,
       3,     3,     3,     3,     3,    12,     6,    47,    51,    33,
      49,     6,    52,    13,     0,     4,    43,    44,    48,    35,
      63,    64,    13,     8,    10,    13,     9,    11,    22,    62,
      63,    64,    67,    62,    35,    63,    64,    67,    33,     4,
      33,    61,    64,    35,    64,     6,     7,    13,    45,     4,
       7,    33,     4,    14,    15,    16,    17,    18,    19,    65,
      65,    66,    66,    64,     4,    20,    21,     4,     4,     4,
       4,     4,     7,     4,     7,    13,    13,    33,    45,    44,
      64,    64,    64,    64,    64,    64,     5,    50,    64,    64,
      50,    13,    13,    13,    13,    61,    61,    51,    25,     6,
      50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    38,    39,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    45,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    56,    56,    57,    57,    57,    58,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     1,     0,     2,     1,     6,     5,
       1,     1,     3,     1,     2,     4,     3,     3,     2,     1,
       3,     1,     1,     1,     3,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     5,
       7,     5,     4,     4,     5,     5,     5,     5,     2,     4,
       3,     3,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     2,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Programa: ListaFuncoes Main BlocoPrincipal $end  */
#line 103 "expr.y"
                                                 {AddFuncao((yyvsp[-3].funcao), criaFuncao(TIPO_INT, "main", NULL, (yyvsp[-1].bloco)));printFuncao((yyvsp[-3].funcao));}
#line 1559 "expr.tab.c"
    break;

  case 3: /* Programa: Main BlocoPrincipal $end  */
#line 104 "expr.y"
                                    {printFuncao(criaFuncao(285, "main", NULL, (yyvsp[-1].bloco)));}
#line 1565 "expr.tab.c"
    break;

  case 4: /* Programa: $end  */
#line 105 "expr.y"
                {exit(0);}
#line 1571 "expr.tab.c"
    break;

  case 5: /* Main: %empty  */
#line 107 "expr.y"
      {lookupFunc("main");}
#line 1577 "expr.tab.c"
    break;

  case 6: /* ListaFuncoes: ListaFuncoes Funcao  */
#line 108 "expr.y"
                                  {AddFuncao((yyvsp[-1].funcao), (yyvsp[0].funcao));(yyval.funcao) = (yyvsp[-1].funcao);}
#line 1583 "expr.tab.c"
    break;

  case 7: /* ListaFuncoes: Funcao  */
#line 109 "expr.y"
                 {(yyval.funcao) = (yyvsp[0].funcao);}
#line 1589 "expr.tab.c"
    break;

  case 8: /* Funcao: TipoRetorno TID SIM_ABREPARENTESES DeclParametros SIM_FECHAPARENTESES BlocoPrincipal  */
#line 111 "expr.y"
                                                                                             {(yyval.funcao) = criaFuncao((yyvsp[-5].integer), (yyvsp[-4].id), (yyvsp[-2].item), (yyvsp[0].bloco));}
#line 1595 "expr.tab.c"
    break;

  case 9: /* Funcao: TipoRetorno TID SIM_ABREPARENTESES SIM_FECHAPARENTESES BlocoPrincipal  */
#line 112 "expr.y"
                                                                                {(yyval.funcao) = criaFuncao((yyvsp[-4].integer), (yyvsp[-3].id), NULL, (yyvsp[0].bloco));}
#line 1601 "expr.tab.c"
    break;

  case 10: /* TipoRetorno: Tipo  */
#line 114 "expr.y"
                  {tp_fun = (yyvsp[0].integer);(yyval.integer) = (yyvsp[0].integer);}
#line 1607 "expr.tab.c"
    break;

  case 11: /* TipoRetorno: TIPO_VOID  */
#line 115 "expr.y"
                    {tp_fun = TIPO_VOID;(yyval.integer) = TIPO_VOID;}
#line 1613 "expr.tab.c"
    break;

  case 12: /* DeclParametros: DeclParametros SIM_VIRGULA Parametro  */
#line 117 "expr.y"
                                                     {AddItem(temp_fun->prms, criaItem((yyvsp[0].nPtr)));AddItem((yyvsp[-2].item), criaItem((yyvsp[0].nPtr)));(yyval.item) = (yyvsp[-2].item);}
#line 1619 "expr.tab.c"
    break;

  case 13: /* DeclParametros: Parametro  */
#line 118 "expr.y"
                    {temp_fun->prms = criaItem((yyvsp[0].nPtr));(yyval.item) = criaItem((yyvsp[0].nPtr));}
#line 1625 "expr.tab.c"
    break;

  case 14: /* Parametro: Tipo TID  */
#line 120 "expr.y"
                    {(yyval.nPtr) = criaId((yyvsp[0].id), (yyvsp[-1].integer));}
#line 1631 "expr.tab.c"
    break;

  case 15: /* BlocoPrincipal: SIM_ABRECHAVES Declaracoes ListaCmd SIM_FECHACHAVES  */
#line 122 "expr.y"
                                                                    {(yyval.bloco) = criaBloco((yyvsp[-2].listadecl), (yyvsp[-1].item));}
#line 1637 "expr.tab.c"
    break;

  case 16: /* BlocoPrincipal: SIM_ABRECHAVES Declaracoes SIM_FECHACHAVES  */
#line 123 "expr.y"
                                                     {(yyval.bloco) = criaBloco((yyvsp[-1].listadecl), NULL);}
#line 1643 "expr.tab.c"
    break;

  case 17: /* BlocoPrincipal: SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES  */
#line 124 "expr.y"
                                                  {(yyval.bloco) = criaBloco(NULL, (yyvsp[-1].item));}
#line 1649 "expr.tab.c"
    break;

  case 18: /* Declaracoes: Declaracoes Declaracao  */
#line 126 "expr.y"
                                    {AddListaDecl((yyvsp[-1].listadecl), criaListaDecl((yyvsp[0].declaracao)));(yyval.listadecl) = (yyvsp[-1].listadecl);}
#line 1655 "expr.tab.c"
    break;

  case 19: /* Declaracoes: Declaracao  */
#line 127 "expr.y"
                     {(yyval.listadecl) = criaListaDecl((yyvsp[0].declaracao));}
#line 1661 "expr.tab.c"
    break;

  case 20: /* Declaracao: Tipo ListaId SIM_FIM  */
#line 129 "expr.y"
                                 {(yyval.declaracao) = criaDeclaracao((yyvsp[-2].integer), (yyvsp[-1].item));}
#line 1667 "expr.tab.c"
    break;

  case 21: /* Tipo: TIPO_INT  */
#line 131 "expr.y"
               {tp_sim = TIPO_INT;(yyval.integer) = TIPO_INT;}
#line 1673 "expr.tab.c"
    break;

  case 22: /* Tipo: TIPO_STRING  */
#line 132 "expr.y"
                      {tp_sim = TIPO_STRING;(yyval.integer) = TIPO_STRING;}
#line 1679 "expr.tab.c"
    break;

  case 23: /* Tipo: TIPO_FLOAT  */
#line 133 "expr.y"
                     {tp_sim = TIPO_FLOAT;(yyval.integer) = TIPO_FLOAT;}
#line 1685 "expr.tab.c"
    break;

  case 24: /* ListaId: ListaId SIM_VIRGULA TID  */
#line 135 "expr.y"
                                 {AddItem((yyvsp[-2].item), criaItem(criaId((yyvsp[0].id), 2)));(yyval.item) = (yyvsp[-2].item);}
#line 1691 "expr.tab.c"
    break;

  case 25: /* ListaId: TID  */
#line 136 "expr.y"
              {(yyval.item) = criaItem(criaId((yyvsp[0].id), 2));}
#line 1697 "expr.tab.c"
    break;

  case 26: /* Bloco: SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES  */
#line 138 "expr.y"
                                               {(yyval.item) = (yyvsp[-1].item);}
#line 1703 "expr.tab.c"
    break;

  case 27: /* ListaCmd: ListaCmd Comando  */
#line 140 "expr.y"
                           {AddItem((yyvsp[-1].item), criaItem((yyvsp[0].nPtr))); (yyval.item) = (yyvsp[-1].item);}
#line 1709 "expr.tab.c"
    break;

  case 28: /* ListaCmd: Comando  */
#line 141 "expr.y"
                  {(yyval.item) = criaItem((yyvsp[0].nPtr));}
#line 1715 "expr.tab.c"
    break;

  case 29: /* Comando: CmdIf  */
#line 143 "expr.y"
               {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1721 "expr.tab.c"
    break;

  case 30: /* Comando: CmdWhile  */
#line 144 "expr.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1727 "expr.tab.c"
    break;

  case 31: /* Comando: CmdAtrib  */
#line 145 "expr.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1733 "expr.tab.c"
    break;

  case 32: /* Comando: CmdWrite  */
#line 146 "expr.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1739 "expr.tab.c"
    break;

  case 33: /* Comando: CmdRead  */
#line 147 "expr.y"
                  {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1745 "expr.tab.c"
    break;

  case 34: /* Comando: ChamadaProc  */
#line 148 "expr.y"
                      {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1751 "expr.tab.c"
    break;

  case 35: /* Comando: Retorno  */
#line 149 "expr.y"
                  {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1757 "expr.tab.c"
    break;

  case 36: /* Retorno: COM_RETORNO Expra SIM_FIM  */
#line 151 "expr.y"
                                   {(yyval.nPtr) = criaOpr(COM_RETORNO, NULL, 1, (yyvsp[-1].nPtr));}
#line 1763 "expr.tab.c"
    break;

  case 37: /* Retorno: COM_RETORNO CONS_LITERAL SIM_FIM  */
#line 152 "expr.y"
                                           {(yyval.nPtr) = criaOpr(COM_RETORNO, NULL, 1, criaString((yyvsp[-1].string)));}
#line 1769 "expr.tab.c"
    break;

  case 38: /* Retorno: COM_RETORNO SIM_FIM  */
#line 153 "expr.y"
                              {(yyval.nPtr) = criaOpr(COM_RETORNO, NULL, 0);}
#line 1775 "expr.tab.c"
    break;

  case 39: /* CmdIf: COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco  */
#line 155 "expr.y"
                                                                {(yyval.nPtr) = criaOpr(COM_SE, criaRepeticao((yyvsp[0].item), NULL), 1, (yyvsp[-2].nPtr));}
#line 1781 "expr.tab.c"
    break;

  case 40: /* CmdIf: COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco COM_SENAO Bloco  */
#line 156 "expr.y"
                                                                                   {(yyval.nPtr) = criaOpr(COM_SENAO, criaRepeticao((yyvsp[-2].item), (yyvsp[0].item)), 1, (yyvsp[-4].nPtr));}
#line 1787 "expr.tab.c"
    break;

  case 41: /* CmdWhile: COM_ENQUANTO SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco  */
#line 158 "expr.y"
                                                                         {(yyval.nPtr) = criaOpr(COM_ENQUANTO, criaRepeticao((yyvsp[0].item), NULL), 1, (yyvsp[-2].nPtr));}
#line 1793 "expr.tab.c"
    break;

  case 42: /* CmdAtrib: TID SIM_IGUAL Expra SIM_FIM  */
#line 160 "expr.y"
                                      {(yyval.nPtr) = criaOpr(SIM_IGUAL, NULL, 2, criaId((yyvsp[-3].id), 0), (yyvsp[-1].nPtr));}
#line 1799 "expr.tab.c"
    break;

  case 43: /* CmdAtrib: TID SIM_IGUAL CONS_LITERAL SIM_FIM  */
#line 161 "expr.y"
                                             {(yyval.nPtr) = criaOpr(SIM_IGUAL, NULL, 2, criaId((yyvsp[-3].id), 0), criaString((yyvsp[-1].string)));}
#line 1805 "expr.tab.c"
    break;

  case 44: /* CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES SIM_FIM  */
#line 163 "expr.y"
                                                                           {(yyval.nPtr) = criaOpr(COM_IMPRIME, NULL, 1, (yyvsp[-2].nPtr));}
#line 1811 "expr.tab.c"
    break;

  case 45: /* CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES SIM_FIM  */
#line 164 "expr.y"
                                                                           {(yyval.nPtr) = criaOpr(COM_IMPRIME, NULL, 1, (yyvsp[-2].nPtr));}
#line 1817 "expr.tab.c"
    break;

  case 46: /* CmdWrite: COM_IMPRIME SIM_ABREPARENTESES CONS_LITERAL SIM_FECHAPARENTESES SIM_FIM  */
#line 165 "expr.y"
                                                                                  {(yyval.nPtr) = criaOpr(COM_IMPRIME, NULL, 1, criaString((yyvsp[-2].string)));}
#line 1823 "expr.tab.c"
    break;

  case 47: /* CmdRead: COM_LER SIM_ABREPARENTESES TID SIM_FECHAPARENTESES SIM_FIM  */
#line 167 "expr.y"
                                                                    {(yyval.nPtr) = criaOpr(COM_LER, NULL, 1, criaId((yyvsp[-2].id), 0));}
#line 1829 "expr.tab.c"
    break;

  case 48: /* ChamadaProc: ChamaFuncao SIM_FIM  */
#line 169 "expr.y"
                                 {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1835 "expr.tab.c"
    break;

  case 49: /* ChamaFuncao: TID SIM_ABREPARENTESES ListaParametros SIM_FECHAPARENTESES  */
#line 171 "expr.y"
                                                                        {(yyval.nPtr) = criaOpr(1, NULL, 2, criaId((yyvsp[-3].id), 1), (yyvsp[-1].nPtr));}
#line 1841 "expr.tab.c"
    break;

  case 50: /* ChamaFuncao: TID SIM_ABREPARENTESES SIM_FECHAPARENTESES  */
#line 172 "expr.y"
                                                     {(yyval.nPtr) = criaOpr(1, NULL, 1, criaId((yyvsp[-2].id), 1));}
#line 1847 "expr.tab.c"
    break;

  case 51: /* ListaParametros: Expra SIM_VIRGULA ListaParametros  */
#line 174 "expr.y"
                                                   {(yyval.nPtr) = criaOpr(2, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1853 "expr.tab.c"
    break;

  case 52: /* ListaParametros: TID SIM_VIRGULA ListaParametros  */
#line 175 "expr.y"
                                          {(yyval.nPtr) = criaOpr(2, NULL, 2, criaId((yyvsp[-2].id), 0), (yyvsp[0].nPtr));}
#line 1859 "expr.tab.c"
    break;

  case 53: /* ListaParametros: Expra  */
#line 176 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1865 "expr.tab.c"
    break;

  case 54: /* ListaParametros: TID  */
#line 177 "expr.y"
              {(yyval.nPtr) = criaId((yyvsp[0].id), 0);}
#line 1871 "expr.tab.c"
    break;

  case 55: /* Expr: Exprl  */
#line 180 "expr.y"
            {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1877 "expr.tab.c"
    break;

  case 56: /* Expr: Expra  */
#line 181 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1883 "expr.tab.c"
    break;

  case 57: /* Expr: Exprr  */
#line 182 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1889 "expr.tab.c"
    break;

  case 58: /* Exprr: Exprr SIM_MAIORQUE Expra  */
#line 184 "expr.y"
                                {(yyval.nPtr) = criaOpr(SIM_MAIORQUE, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1895 "expr.tab.c"
    break;

  case 59: /* Exprr: Exprr SIM_MENORQUE Expra  */
#line 185 "expr.y"
                                   {(yyval.nPtr) = criaOpr(SIM_MENORQUE, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1901 "expr.tab.c"
    break;

  case 60: /* Exprr: Exprr SIM_MAIOROUIGUAL Expra  */
#line 186 "expr.y"
                                       {(yyval.nPtr) = criaOpr(SIM_MAIOROUIGUAL, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1907 "expr.tab.c"
    break;

  case 61: /* Exprr: Exprr SIM_MENOROUIGUAL Expra  */
#line 187 "expr.y"
                                       {(yyval.nPtr) = criaOpr(SIM_MENOROUIGUAL, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1913 "expr.tab.c"
    break;

  case 62: /* Exprr: Exprr SIM_IGUALIGUAL Expra  */
#line 188 "expr.y"
                                     {(yyval.nPtr) = criaOpr(SIM_IGUALIGUAL, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1919 "expr.tab.c"
    break;

  case 63: /* Exprr: Exprr SIM_DIFERENTE Expra  */
#line 189 "expr.y"
                                    {(yyval.nPtr) = criaOpr(SIM_DIFERENTE, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1925 "expr.tab.c"
    break;

  case 64: /* Exprr: Expra  */
#line 190 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1931 "expr.tab.c"
    break;

  case 65: /* Expra: Expra SIM_ADICAO Termo  */
#line 192 "expr.y"
                              {(yyval.nPtr) = criaOpr(SIM_ADICAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1937 "expr.tab.c"
    break;

  case 66: /* Expra: Expra SIM_SUBTRACAO Termo  */
#line 193 "expr.y"
                                    {(yyval.nPtr) = criaOpr(SIM_SUBTRACAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1943 "expr.tab.c"
    break;

  case 67: /* Expra: Termo  */
#line 194 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1949 "expr.tab.c"
    break;

  case 68: /* Termo: Termo SIM_MULTIPLICACAO Fator  */
#line 196 "expr.y"
                                     {(yyval.nPtr) = criaOpr(SIM_MULTIPLICACAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1955 "expr.tab.c"
    break;

  case 69: /* Termo: Termo SIM_DIVISAO Fator  */
#line 197 "expr.y"
                                  {(yyval.nPtr) = criaOpr(SIM_DIVISAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1961 "expr.tab.c"
    break;

  case 70: /* Termo: Fator  */
#line 198 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1967 "expr.tab.c"
    break;

  case 71: /* Fator: CONS_INT  */
#line 200 "expr.y"
                {(yyval.nPtr) = criaInteger((yyvsp[0].integer));}
#line 1973 "expr.tab.c"
    break;

  case 72: /* Fator: CONS_FLOAT  */
#line 201 "expr.y"
                     {(yyval.nPtr) = criaReal((yyvsp[0].real));}
#line 1979 "expr.tab.c"
    break;

  case 73: /* Fator: CONS_LITERAL  */
#line 202 "expr.y"
                       {(yyval.nPtr) = criaString((yyvsp[0].string));}
#line 1985 "expr.tab.c"
    break;

  case 74: /* Fator: TID  */
#line 203 "expr.y"
              {(yyval.nPtr) = criaId((yyvsp[0].id), 0);}
#line 1991 "expr.tab.c"
    break;

  case 75: /* Fator: ChamaFuncao  */
#line 204 "expr.y"
                      {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1997 "expr.tab.c"
    break;

  case 76: /* Fator: SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES  */
#line 205 "expr.y"
                                                       {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 2003 "expr.tab.c"
    break;

  case 77: /* Exprl: Exprl SIM_E Expra  */
#line 207 "expr.y"
                         {(yyval.nPtr) = criaOpr(SIM_E, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 2009 "expr.tab.c"
    break;

  case 78: /* Exprl: Exprl SIM_OU Expra  */
#line 208 "expr.y"
                             {(yyval.nPtr) = criaOpr(SIM_OU, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 2015 "expr.tab.c"
    break;

  case 79: /* Exprl: SIM_NEGACAO Expra  */
#line 209 "expr.y"
                            {(yyval.nPtr) = criaOpr(SIM_NEGACAO, NULL, 1, (yyvsp[0].nPtr));}
#line 2021 "expr.tab.c"
    break;

  case 80: /* Exprl: Expra  */
#line 210 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2027 "expr.tab.c"
    break;


#line 2031 "expr.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 212 "expr.y"

#define SIZEOF_TIPONO ((char *)&no->inteiro - (char *)no)

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
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

char *getIdTipo(eTipo v){
	if (v == typeInt)
		return "int";
	else if (v == typeFloat)
		return "float";
	else if (v == typeString)
		return "string";
	else if (v == typeVoid)
		return "void";
	else if (v == typeId)
		return "id";
	else if (v == typeOpr)
		return "opr";
}

tipoNo* lookupId(char* n){
	Item *i = tbl_sim;
	while(i != NULL){
		if (!strcmp(i->arv->id.name, n))
			return i->arv;
		i = i->prox;
	}
	printf("Variável %s não foi encontrada.\n", n);
	exit(1);
}

tipoNo* lookupFunc(char* n){
	Funcao *i = tbl_fun;
	int j = 0;
	while(i != NULL){
		j++;
		if (!strcmp(i->no->id.name, n))
			return i->no;
		i = i->prox;
	}
	if (temp_fun == NULL){
		temp_fun = malloc(sizeof(Funcao));
		if (temp_fun == NULL){
			printf("Erro ao alocar memória para a função temporária");
			exit(1);
		}
	}
	if (temp_fun->no == NULL){
		tipoNo *no = malloc(sizeof(tipoNo));
		if (no == NULL){
			printf("Erro ao alocar memória para a função temporária");
			exit(1);
		}
		no->type = typeId;
		no->id.name = n;
		no->id.tipo = getTipoId(tp_fun);
		no->id.i = j;
		temp_fun->no = no;
		temp_fun->prox = NULL;
		return temp_fun->no;
	} else if (!strcmp(temp_fun->no->id.name, n)){
		return temp_fun->no;
	} 
	printf("Função não foi encontrada.\n");
	exit(1);

}

eTipo getTipoOpr(tipoNo *no){
	if (no->type == typeOpr)
		getTipoOpr(no->opr.op[0]);
	else 
		return no->type;
}

void comparaParametros(char* n, Item* prms, tipoNo *op){
	if (prms == NULL && op != NULL){
		printf("Número de parâmetros passados para a função %s excede o número de parâmetros declarados\n", n);
		exit(1);
	} else if(prms != NULL && op == NULL){
		printf("Número de parâmetros passados para a função %s está abaixo do número de parâmetros declarados\n", n);
		exit(1);
	}
	
	while (prms != NULL && op != NULL){
		if (op->type == typeOpr){
			if (op->opr.op[1]->type == typeString){ // String
				if (prms->arv->id.tipo != op->opr.op[1]->type){
					printf("Parâmetros passados para função %s são de tipos diferentes\n", n);
					exit(1);
				}
			}else if (op->opr.op[1]->type == typeId){ // Id
				if (prms->arv->id.tipo != op->opr.op[1]->id.tipo){
					if (op->opr.op[1]->id.tipo == typeString){
						printf("Parâmetros passados para função %s são de tipos diferentes\n", n);
						exit(1);
					} else
						printf("Aviso: Parâmetros passados para função %s são de tipos diferentes\n", n);
				}
			} else {
				if (prms->arv->id.tipo != getTipoOpr(op)){ // Opr
					if (getTipoOpr(op) == typeString){
						printf("Parâmetros passados para função %s são de tipos diferentes\n", n);
						exit(1);
					} else
						printf("Aviso: Parâmetros passados para função %s são de tipos diferentes\n", n);
				}
			}
		} else if (op->type == typeId){
			if (prms->arv->id.tipo != op->id.tipo){ // id
				if (op->id.tipo == typeString){ // string id
					printf("Parâmetros passados para função %s são de tipos diferentes\n", n);
					exit(1);
				} else
					printf("Aviso: Parâmetros passados para função %s são de tipos diferentes\n", n);
			}
		} else {
			if (prms->arv->id.tipo != op->type){ // cons
				if (op->type == typeString){ // string cons
					printf("Parâmetros passados para função %s são de tipos diferentes\n", n);
					exit(1);
				} else if (op->type == typeInt){
					op->type = typeFloat;
					op->real.val = (float)op->inteiro.val;
				} else if (op->type == typeFloat){
					op->type = typeInt;
					op->inteiro.val = (int)op->real.val;
				}
				printf("Aviso: Parâmetros passados para função %s são de tipos diferentes\n", n);
			}
		}
		if (prms->prox != NULL && op->type != typeOpr){ // < nParametros
			printf("Número de parâmetros passados para a função %s está abaixo do número de parâmetros declarados\n", n);
			exit(1);
		} else if (prms->prox == NULL && op->type == typeOpr){ // > nParametros
			if (op->opr.opr == 2){
				printf("Número de parâmetros passados para a função %s excede o número de parâmetros declarados\n", n);
				exit(1);
			}
		}
		prms = prms->prox;
		if (op->type == typeOpr)
			op = op->opr.op[1];
	}
}

int hasFloatInOpr(tipoNo *opr){
	int r1, r2;
	if (opr->type == typeOpr){
		r1 = hasFloatInOpr(opr->opr.op[0]);
		r2 = hasFloatInOpr(opr->opr.op[1]);
		if (r1 != r2)
			return 1;
	} else if (opr->type == typeFloat)
		return 1;
	else if (opr->type == typeId){
		if (opr->id.tipo == typeFloat)
			return 1;
	}
}

void turnIntoFloat(tipoNo *no){
	if (no->type == typeOpr){
		turnIntoFloat(no->opr.op[0]);
		turnIntoFloat(no->opr.op[1]);
	} else if (no->type == typeInt){
		no->type = typeFloat;
		no->real.val = (float)no->inteiro.val;
	}
}

void turnIntoInt(tipoNo *no){
	if (no->type == typeOpr){
		turnIntoInt(no->opr.op[0]);
		turnIntoInt(no->opr.op[1]);
	} else if (no->type == typeFloat){
		no->type = typeInt;
		no->inteiro.val = (int)no->real.val;
	}
}

void detectaFloatInt(tipoNo *no){
	if (no){
		if (hasFloatInOpr(no))
			turnIntoFloat(no);
	}
}

void detectaErros(int opr, tipoNo *no){
	if (no->type == typeOpr){
		if (opr == COM_RETORNO){
			if (no->opr.op[0]){
				if (no->opr.op[0]->type == typeId){
					if (no->opr.op[0]->id.tipo != temp_fun->no->id.tipo){
						printf("Função %s tipo %s está retornando um valor %s\n", temp_fun->no->id.name, getIdTipo(temp_fun->no->id.tipo), getIdTipo(no->opr.op[0]->id.tipo));
						exit(1);
					}
				} else if (no->opr.op[0]->type == typeOpr){
					if (!hasFloatInOpr(no->opr.op[0]) && temp_fun->no->id.tipo == typeFloat){
						printf("Função %s tipo float está retornando um valor int\n", temp_fun->no->id.name);
						exit(1);
					} else if (hasFloatInOpr(no->opr.op[0]) && temp_fun->no->id.tipo == typeInt){
						printf("Função %s tipo int está retornando um valor float\n", temp_fun->no->id.name);
						exit(1);
					}
				} else {
					if (temp_fun->no != NULL){
						if (no->opr.op[0]->type != temp_fun->no->id.tipo){
							printf("Função %s tipo %s está retornando um valor %s\n", temp_fun->no->id.name, getIdTipo(temp_fun->no->id.tipo), getIdTipo(no->opr.op[0]->type));
							exit(1);
						}
					}
				}
			} else { // Void
				if (temp_fun->no->id.tipo != typeVoid){
					printf("Função %s tipo void está retornando um valor\n", temp_fun->no->id.name);
					exit(1);
				}
			}
		} else if (opr == SIM_IGUAL){
			if (no->opr.op[1]->type == typeOpr){ // Operação
				if (no->opr.op[1]->opr.opr == 1){ // Chama Função
					if (no->opr.op[0]->id.tipo == typeString && no->opr.op[1]->opr.op[0]->id.tipo != typeString){
						printf("Retorno da função %s tipo %s sendo atribuído a tipo %s\n", no->opr.op[1]->opr.op[0]->id.name, getIdTipo(no->opr.op[1]->opr.op[0]->id.tipo), getIdTipo(no->opr.op[0]->id.tipo));
						exit(1); 
					} else if (no->opr.op[0]->id.tipo != no->opr.op[1]->opr.op[0]->id.tipo){
						printf("Aviso: Retorno da função %s tipo %s sendo atribuído a tipo %s\n", no->opr.op[1]->opr.op[0]->id.name, getIdTipo(no->opr.op[1]->opr.op[0]->id.tipo), getIdTipo(no->opr.op[0]->id.tipo));
					}
				} else if (hasFloatInOpr(no->opr.op[1]) && no->opr.op[0]->id.tipo == typeInt){
					printf("Aviso: Tipo float sendo atribuído a tipo int\n");
				} else if (!hasFloatInOpr(no->opr.op[1]) && no->opr.op[1]->id.tipo == typeFloat){
					printf("Aviso: Tipo int sendo atribuído a tipo float\n");
				}
			} else if (no->opr.op[1]->type == typeString){
				if (no->opr.op[0]->id.tipo != typeString){
					printf("Não é possível atribuir %s à %s\n", getIdTipo(no->opr.op[1]->type), getIdTipo(no->opr.op[0]->id.tipo));
					exit(1);
				}
			} else {
				if (no->opr.op[0]->id.tipo == typeInt && no->opr.op[1]->type == typeFloat){
					no->opr.op[1]->type = typeInt;
					no->opr.op[1]->inteiro.val = (int)no->opr.op[1]->real.val;
					printf("Aviso:Tipo float sendo atribuído a tipo int\n");
				} else if (no->opr.op[0]->id.tipo == typeFloat && no->opr.op[1]->type == typeInt){
					no->opr.op[1]->type = typeFloat;
					no->opr.op[1]->real.val = (float)no->opr.op[1]->inteiro.val;
					printf("Aviso:Tipo int sendo atribuído a tipo float\n");
				} else if (no->opr.op[0]->id.tipo != no->opr.op[1]->type){
					printf("Tipo %s sendo atribuído a tipo %s\n", getIdTipo(no->opr.op[1]->id.tipo), getIdTipo(no->opr.op[0]->id.tipo));
					exit(1);
				}
			}
		} else if (opr == SIM_E || opr == SIM_OU){
			if (no->opr.op[0]->type == typeId && no->opr.op[1]->type == typeId){
				if ((no->opr.op[0]->id.tipo == typeString && no->opr.op[1]->id.tipo != typeString) || (no->opr.op[0]->id.tipo != typeString && no->opr.op[1]->id.tipo == typeString)){
					printf("Os dois operandos de operações relacionais devem ser de tipos iguais\n");
					exit(1);
				}
			} else if (no->opr.op[0]->type == typeId){
				if (no->opr.op[0]->id.tipo == typeInt && no->opr.op[1]->type == typeFloat){
					no->opr.op[1]->type = typeInt;
					no->opr.op[1]->inteiro.val = (int)no->opr.op[1]->real.val;
					printf("Aviso:Tipo float sendo comparado com tipo int\n");
				} else if (no->opr.op[0]->id.tipo == typeFloat && no->opr.op[1]->type == typeInt){
					no->opr.op[1]->type = typeFloat;
					no->opr.op[1]->real.val = (float)no->opr.op[1]->inteiro.val;
					printf("Aviso:Tipo int sendo comparado com tipo float\n");
				} else if (no->opr.op[1]->type == typeOpr){
					if (hasFloatInOpr(no->opr.op[1]) && no->opr.op[0]->id.tipo == typeInt){
						turnIntoInt(no->opr.op[1]);
						printf("Aviso:Tipo float sendo comparado com tipo int\n");
					} else if (!hasFloatInOpr(no->opr.op[1]) && no->opr.op[0]->id.tipo == typeFloat){
						turnIntoFloat(no->opr.op[1]);
						printf("Aviso:Tipo int sendo comparado com tipo float\n");
					}
				} else if (no->opr.op[0]->id.tipo != no->opr.op[1]->type){
					printf("Os dois operandos de operações relacionais devem ser de tipos iguais\n");
					exit(1);
				}
			} else if (no->opr.op[1]->type == typeId){
				if (no->opr.op[1]->id.tipo == typeInt && no->opr.op[0]->type == typeFloat){
					no->opr.op[0]->type = typeInt;
					no->opr.op[0]->inteiro.val = (int)no->opr.op[0]->real.val;
					printf("Aviso:Tipo float sendo comparado com tipo int\n");
				} else if (no->opr.op[1]->id.tipo == typeFloat && no->opr.op[0]->type == typeInt){
					no->opr.op[0]->type = typeFloat;
					no->opr.op[0]->real.val = (float)no->opr.op[0]->inteiro.val;
					printf("Aviso:Tipo int sendo comparado com tipo float\n");
				} else if (no->opr.op[0]->type == typeOpr){
					if (hasFloatInOpr(no->opr.op[0]) && no->opr.op[1]->id.tipo == typeInt){
						turnIntoInt(no->opr.op[0]);
						printf("Aviso:Tipo float sendo comparado com tipo int\n");
					} else if (!hasFloatInOpr(no->opr.op[0]) && no->opr.op[1]->id.tipo == typeFloat){
						turnIntoFloat(no->opr.op[0]);
						printf("Aviso:Tipo int sendo comparado com tipo float\n");
					}
				} else if (no->opr.op[1]->id.tipo != no->opr.op[0]->type){
					printf("Os dois operandos de operações relacionais devem ser de tipos iguais\n");
					exit(1);
				}
			} else{
				if (no->opr.op[0]->type == typeOpr && no->opr.op[1]->type != typeOpr){
					if ((hasFloatInOpr(no->opr.op[0]) && no->opr.op[1]->type != typeFloat) || (!hasFloatInOpr(no->opr.op[0]) && no->opr.op[1]->type == typeFloat)){
						printf("Os dois operandos de operações relacionais devem ser de tipos iguais\n");
						exit(1);
					}
				} else if (no->opr.op[1]->type == typeOpr && no->opr.op[0]->type != typeOpr){
					if ((hasFloatInOpr(no->opr.op[1]) && no->opr.op[0]->type != typeFloat) || (!hasFloatInOpr(no->opr.op[1]) && no->opr.op[0]->type == typeFloat)){
						printf("Os dois operandos de operações relacionais devem ser de tipos iguais\n");
						exit(1);
					}
				} else if (no->opr.op[0]->type == typeOpr && no->opr.op[1]->type == typeOpr){
					if ((hasFloatInOpr(no->opr.op[0]) && !hasFloatInOpr(no->opr.op[1])) || (!hasFloatInOpr(no->opr.op[0]) && hasFloatInOpr(no->opr.op[1]))){
						printf("Os dois operandos de operações relacionais devem ser de tipos iguais\n");
						exit(1);
					}
				}else if (no->opr.op[0]->type != no->opr.op[1]->type){
					if (no->opr.op[0]->type == typeInt && no->opr.op[1]->type == typeFloat){
						no->opr.op[1]->type = typeInt;
						no->opr.op[1]->inteiro.val = (int)no->opr.op[1]->real.val;
						printf("Aviso:Tipo float sendo atribuído a tipo int\n");
					} else if (no->opr.op[0]->type == typeFloat && no->opr.op[1]->type == typeInt){
						no->opr.op[1]->type = typeFloat;
						no->opr.op[1]->real.val = (float)no->opr.op[1]->inteiro.val;
						printf("Aviso:Tipo int sendo atribuído a tipo float\n");
					}
				} 
			}
		} else if (opr == SIM_ADICAO || opr == SIM_SUBTRACAO || opr == SIM_MULTIPLICACAO || opr == SIM_DIVISAO || opr == SIM_IGUALIGUAL || opr == SIM_DIFERENTE || opr == SIM_MAIORQUE || opr == SIM_MENORQUE || opr == SIM_MAIOROUIGUAL || opr == SIM_MENOROUIGUAL){
			if (no->opr.op[0]->id.tipo == typeString){
				printf("Strings só podem ser usadas em expressões relacionais\n");
				exit(1);
			} else if (no->opr.op[1] != NULL){
				if (no->opr.op[1]->type == typeId){
					if (no->opr.op[1]->id.tipo == typeString){
						printf("Strings só podem ser usadas em expressões relacionais\n");
						exit(1);
					}
				} else if (no->opr.op[1]->type == typeString){
					printf("Strings só podem ser usadas em expressões relacionais\n");
					exit(1);
				}
			}
			detectaFloatInt(no);
		} else if (opr = 1){
			if (no->opr.op[0]->type == typeId){
				if (temp_fun->no){
					if (!strcmp(no->opr.op[0]->id.name, temp_fun->no->id.name)) // Recursiva
						comparaParametros(temp_fun->no->id.name, temp_fun->prms, no->opr.op[1]);
				} else {
					Funcao *i = tbl_fun;
					while(i != NULL){
						if (!strcmp(i->no->id.name, no->opr.op[0]->id.name)){
							comparaParametros(no->opr.op[0]->id.name, i->prms, no->opr.op[1]);					
							break;
						}
						i = i->prox;
					}
				}
			}
		}
	}
}

int inFila(Item *f, char *name){
	while(f){
		if (!strcmp(f->arv->id.name, name))
			return 1;
		f = f->prox;
	}
	return 0;
}

int inFilaFunc(Funcao* f, char *name){
	while(f){
		if (!strcmp(f->no->id.name, name))
			return 1;
		f = f->prox;
	}
	return 0;
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
	no->id.tipo = getTipoId(tipo);
	if (tipo == 0){
		no = lookupId(name);
	}else if (tipo == 1){
		no = lookupFunc(name);
	} else {
		no->id.tipo = getTipoId(tp_sim);
		if (tbl_sim == NULL){
			tbl_sim = criaItem(no);
		}else{
			if (!inFila(tbl_sim, no->id.name) && !inFilaFunc(tbl_fun, no->id.name)){
				AddItem(tbl_sim, criaItem(no));
			} else {
				printf("Variável %s já foi declarada anteriormente\n", name);
				exit(1);
			}
		}
	}
	return no;
}

tipoNo *criaOpr(int opr, Repeticao *rep, int nOps, ...){
	va_list ap;
	tipoNo *no;
	size_t tam_no = SIZEOF_TIPONO + sizeof(typeOpr) + (nOps - 1) * sizeof(tipoNo*);
	if ((no = malloc(tam_no)) == NULL)
		yyerror("Sem memória");
	if ((no->opr.op = malloc(nOps * sizeof(tipoNo*))) == NULL)
		yyerror("Sem memória");
	if ((no->opr.rep = malloc(sizeof(Repeticao))) == NULL)
		yyerror("Sem memória");

	no->type = typeOpr;
	no->opr.rep = rep;
	no->opr.opr = opr;
	no->opr.nOps = nOps;
	va_start(ap, nOps);
	for (int i=0;i<nOps;i++){
		no->opr.op[i] = va_arg(ap, tipoNo*);
	}
	va_end(ap);
	
	detectaErros(opr, no);

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

void excluirItem(Item *i){
	if (!i)
		return;
	excluirNo(i->arv);
	if (i->prox != NULL)
		excluirItem(i->prox);
	free(i);
}

void excluirTempFunc(Funcao *f){
	if (f == NULL)
		return;
	if (f->prox != NULL)
		excluirTempFunc(f->prox);
	excluirNo(f->no);
	excluirItem(f->prms);
}

Item* criaItem(tipoNo *arv){
	if (temp_fun == NULL){
		temp_fun = malloc(sizeof(Funcao));
		if (temp_fun == NULL){
			printf("Erro ao alocar memória para a função temporária");
			exit(1);
		}
	}
	Item *i = malloc(sizeof(Item));
	if (i == NULL){
		printf("Error ao alocar memória para o Item");
		exit(1);
	}
	
	i->prox = NULL;
	i->arv = arv;
	return i;
}

Repeticao* criaRepeticao(Item *cmds, Item *senao){
	Repeticao *r = malloc(sizeof(Repeticao));
	if (r == NULL){
		printf("Error ao alocar memória para a Repetição");
		exit(1);
	}
	r->cmds = cmds;
	r->senao = senao;
	return r;
}

Declaracao* criaDeclaracao(int tipo, Item *vars){
	Declaracao *d = malloc(sizeof(Declaracao));
	if (d == NULL){
		printf("Error ao alocar memória para as Declarações");
		exit(1);
	}
	d->tipo = getTipoId(tipo);
	d->vars = vars;
	Item *var = d->vars;
	while (var != NULL){
		var->arv->type = typeId;
		var->arv->id.tipo = getTipoId(tipo);
		var = var->prox;
	}
	return d;
}

ListaDecl *criaListaDecl(Declaracao *decl){
	ListaDecl *l = malloc(sizeof(ListaDecl));
	if (l == NULL){
		printf("Error ao alocar memória para a Lista de Declarações");
		exit(1);
	}
	l->prox = NULL;
	l->decl = decl;
	return l;
}

Bloco* criaBloco(ListaDecl *decl, Item *cmds){
	Bloco* b = malloc(sizeof(Bloco));
	if (b == NULL){
		printf("Error ao alocar memória para o Bloco");
		exit(1);
	}
	b->decl = decl;
	b->cmds = cmds;
	return b;
}

Funcao* criaFuncao(int tipo, char *nome, Item *prms, Bloco *blc){
	Funcao *f = malloc(sizeof(Funcao));
	if (f == NULL){
		printf("Error ao alocar memória para a função\n");
		exit(1);
	}
	tipoNo *n = malloc(sizeof(tipoNo));
	if (n == NULL){
		printf("Error ao alocar memória para a função\n");
		exit(1);
	}
	n->type = typeId;
	n->id.tipo = getTipoId(tipo);
	n->id.name = strdup(nome);
	f->no = n;
	f->syms = tbl_sim;
	tbl_sim = NULL;
	f->no->id.i = 0;
	f->prms = prms;
	f->blc = blc;
	if (inFilaFunc(tbl_fun, nome)){
		printf("Função %s já foi declarada anteriormente\n", nome);
		exit(1);
	}
	temp_fun = NULL;
	if (tbl_fun == NULL)
		tbl_fun = f;
	else
		AddFuncao(tbl_fun, f);
	return f;
}

void AddItem(Item *o, Item *ad){
	while(o->prox)
		o = o->prox;
	o->prox = malloc(sizeof(Item));
	if (o->prox == NULL){
		printf("Erro ao alocar memória para o próximo item\n");
		exit(1);
	}
	if (o->arv->type == typeId && ad->arv->type == typeId)
		ad->arv->id.i = o->arv->id.i + 1;
	o->prox = ad;
}

void AddListaDecl(ListaDecl *o, ListaDecl *ad){
	while(o->prox != NULL)
		o = o->prox;
	o->prox = malloc(sizeof(ListaDecl));
	if (o->prox == NULL){
		printf("Erro ao alocar memória para a próxima Lista de Declarações\n");
		exit(1);
	}
	o->prox = ad;
}

void AddFuncao(Funcao *f1, Funcao *f2){
	while(f1->prox != NULL){
		if (f1->no->id.name == f2->no->id.name){
			printf("Função %s já foi declarada anteriormente\n", f2->no->id.name);
		}
		f1 = f1->prox;
	}
	f1->prox = malloc(sizeof(Funcao));
	if (f1->prox == NULL){
		printf("Erro ao alocar memória para a próxima função\n");
		exit(1);
	}
	f2->no->id.i = f1->no->id.i + 1;
	f1->prox = f2;
	f2->prox = NULL;
}

void printParametros(Item *prms){
	printf("%s ", getIdTipo(prms->arv->id.tipo));
	printf("%s", prms->arv->id.name);

	if (prms->prox != NULL){
		printf(", ");
		printParametros(prms->prox);
	}
}

void printVariaveis(Item *vars){
	printf("%s", vars->arv->id.name);

	if (vars->prox != NULL){
		printf(", ");
		printVariaveis(vars->prox);
	}
}

void printDeclaracao(Declaracao *decl){
	printf("%s ", getIdTipo(decl->tipo));
	printVariaveis(decl->vars);
	printf(";\n");
}

void printDeclaracoes(ListaDecl *decl){
	printDeclaracao(decl->decl);
	if (decl->prox != NULL)
		printDeclaracoes(decl->prox);
}

void printNo(tipoNo *cmd){
	switch(cmd->type){
		case typeInt:
			printf("%d", cmd->inteiro.val);
			break;
		case typeFloat:
			printf("%f", cmd->real.val);
			break;
		case typeString:
			printf("%s", cmd->string.str);
			break;
		case typeId:
			printf("%s", cmd->id.name);
			break;
		case typeOpr:
			switch(cmd->opr.opr){
				case 1: // Chama Função
					printNo(cmd->opr.op[0]);
					printf("(");
					if (cmd->opr.op[1])
						printNo(cmd->opr.op[1]);
					printf(")");
					break;
				case 2: // Parâmetros da Função
					printNo(cmd->opr.op[0]);
					if (cmd->opr.op[1]){
						printf(", ");
						printNo(cmd->opr.op[1]);
					}
					break;
				case SIM_ADICAO:
					printNo(cmd->opr.op[0]);
					printf("+");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MULTIPLICACAO:
					printNo(cmd->opr.op[0]);
					printf("*");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_SUBTRACAO:
					printNo(cmd->opr.op[0]);
					printf("-");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_DIVISAO:
					printNo(cmd->opr.op[0]);
					printf("/");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_IGUAL:
					printNo(cmd->opr.op[0]);
					printf("=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_IGUALIGUAL:
					printNo(cmd->opr.op[0]);
					printf("==");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_DIFERENTE:
					printNo(cmd->opr.op[0]);
					printf("!=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MAIORQUE:
					printNo(cmd->opr.op[0]);
					printf(">");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MENORQUE:
					printNo(cmd->opr.op[0]);
					printf("<");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MAIOROUIGUAL:
					printNo(cmd->opr.op[0]);
					printf(">=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MENOROUIGUAL:
					printNo(cmd->opr.op[0]);
					printf("<=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_E:
					printNo(cmd->opr.op[0]);
					printf("&&");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_OU:
					printNo(cmd->opr.op[0]);
					printf("||");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_NEGACAO:
					printf("!");
					printNo(cmd->opr.op[0]);
					break;
				case COM_RETORNO:
					printf("return ");
					printNo(cmd->opr.op[0]);
					break;
				case COM_SE:
					printf("if(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					break;
				case COM_SENAO:
					printf("if(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					printf("else{\n");
					printComandos(cmd->opr.rep->senao);
					printf("}");
					break;
				case COM_ENQUANTO:
					printf("while(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					break;
				case COM_IMPRIME:
					printf("print(");
					printNo(cmd->opr.op[0]);
					printf(")");
					break;
				case COM_LER:
					printf("read(");
					printNo(cmd->opr.op[0]);
					printf(")");
					break;
			}
			break;
	}
}

void printComandos(Item *cmds){
	printNo(cmds->arv);
	printf(";\n");
	if (cmds->prox != NULL)
		printComandos(cmds->prox);
}

void printBloco(Bloco *blc){
	printf("{\n");
	if (blc->decl)
		printDeclaracoes(blc->decl);
	if (blc->cmds)
		printComandos(blc->cmds);
	printf("}\n");
}

void printFuncao(Funcao *f){
	printf("%s ", getIdTipo(f->no->id.tipo));
	printf("%s", f->no->id.name);
	
	printf("(");
	if (f->prms != NULL)
		printParametros(f->prms);
	printf(")");

	if (f->blc != NULL)
		printBloco(f->blc);
	

	printf("\n");
	if (f->prox != NULL)
		printFuncao(f->prox);
}
