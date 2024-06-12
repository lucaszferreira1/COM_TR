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

Item *tbl_fun;
Item *tbl_sim;
int tp_sim;


#line 109 "expr.tab.c"

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
  YYSYMBOL_ListaFuncoes = 39,              /* ListaFuncoes  */
  YYSYMBOL_Funcao = 40,                    /* Funcao  */
  YYSYMBOL_TipoRetorno = 41,               /* TipoRetorno  */
  YYSYMBOL_DeclParametros = 42,            /* DeclParametros  */
  YYSYMBOL_Parametro = 43,                 /* Parametro  */
  YYSYMBOL_BlocoPrincipal = 44,            /* BlocoPrincipal  */
  YYSYMBOL_Declaracoes = 45,               /* Declaracoes  */
  YYSYMBOL_Declaracao = 46,                /* Declaracao  */
  YYSYMBOL_Tipo = 47,                      /* Tipo  */
  YYSYMBOL_ListaId = 48,                   /* ListaId  */
  YYSYMBOL_Bloco = 49,                     /* Bloco  */
  YYSYMBOL_ListaCmd = 50,                  /* ListaCmd  */
  YYSYMBOL_Comando = 51,                   /* Comando  */
  YYSYMBOL_Retorno = 52,                   /* Retorno  */
  YYSYMBOL_CmdIf = 53,                     /* CmdIf  */
  YYSYMBOL_CmdWhile = 54,                  /* CmdWhile  */
  YYSYMBOL_CmdAtrib = 55,                  /* CmdAtrib  */
  YYSYMBOL_CmdWrite = 56,                  /* CmdWrite  */
  YYSYMBOL_CmdRead = 57,                   /* CmdRead  */
  YYSYMBOL_ChamadaProc = 58,               /* ChamadaProc  */
  YYSYMBOL_ChamaFuncao = 59,               /* ChamaFuncao  */
  YYSYMBOL_ListaParametros = 60,           /* ListaParametros  */
  YYSYMBOL_Expr = 61,                      /* Expr  */
  YYSYMBOL_Exprr = 62,                     /* Exprr  */
  YYSYMBOL_Expra = 63,                     /* Expra  */
  YYSYMBOL_Termo = 64,                     /* Termo  */
  YYSYMBOL_Fator = 65,                     /* Fator  */
  YYSYMBOL_Exprl = 66                      /* Exprl  */
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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

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
       0,   100,   100,   101,   102,   104,   105,   107,   108,   110,
     111,   113,   114,   116,   118,   119,   120,   121,   123,   124,
     126,   128,   129,   130,   132,   133,   135,   136,   138,   139,
     141,   142,   143,   144,   145,   146,   147,   149,   150,   151,
     153,   154,   156,   158,   159,   161,   162,   163,   165,   167,
     169,   170,   172,   173,   174,   175,   178,   179,   180,   182,
     183,   184,   185,   186,   187,   188,   190,   191,   192,   194,
     195,   196,   198,   199,   200,   201,   202,   204,   205,   206,
     207
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
  "CONS_FLOAT", "$accept", "Programa", "ListaFuncoes", "Funcao",
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

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,  -106,   105,  -106,  -106,  -106,  -106,    60,   171,  -106,
      46,    87,  -106,  -106,    12,    13,    30,    96,   111,    25,
     119,  -106,    74,   133,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,   114,  -106,  -106,   134,   145,  -106,    28,  -106,
     151,  -106,   142,  -106,  -106,     4,   211,  -106,    33,    33,
      16,   125,    23,    40,  -106,  -106,   147,  -106,    97,  -106,
    -106,  -106,  -106,    64,   104,   188,  -106,    28,    28,  -106,
      28,    28,    28,   159,   197,     3,   -11,   164,   165,   191,
     157,    77,   175,  -106,   109,   179,    70,   149,    22,  -106,
     154,  -106,   183,   102,  -106,   193,  -106,    28,    28,    28,
      28,    28,    28,   211,   211,  -106,  -106,   188,   192,    28,
      28,   192,   208,   214,   215,   216,    69,  -106,    69,  -106,
    -106,  -106,  -106,   183,   187,  -106,   188,   188,   188,   188,
     188,   188,   158,   199,   188,   188,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,   166,   192,  -106,  -106
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,    10,    21,    22,    23,     0,     0,     6,
       0,     0,     9,    17,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,    29,    36,    30,    31,    32,    33,
      34,    35,     0,     1,     5,     0,     0,     3,     0,    39,
      74,    72,     0,    73,    75,     0,    68,    71,     0,     0,
       0,     0,     0,     0,    15,    18,     0,    25,     0,    16,
      28,    49,     2,     0,     0,    65,    38,     0,     0,    37,
       0,     0,     0,     0,    58,    65,    56,     0,     0,     0,
      65,     0,     0,    51,    74,     0,    54,     0,     0,    14,
       0,    20,     0,     0,    12,     0,    76,     0,     0,     0,
       0,     0,     0,    66,    67,    69,    70,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    44,
      43,    24,     8,     0,     0,    13,    63,    64,    59,    60,
      61,    62,     0,    40,    77,    78,    42,    47,    45,    46,
      48,    53,    52,     7,    11,    27,     0,     0,    26,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,  -106,   196,  -106,  -106,   106,    -6,  -106,   212,
       2,  -106,  -105,   -17,   -22,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,    -2,   107,   182,   -30,    -9,    73,     0,   184
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    93,    94,    11,    20,    21,
      12,    58,   133,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    44,    85,    73,    74,    86,    46,    47,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    60,    35,    56,    22,    45,   136,   -57,    64,   109,
     110,    67,    67,    68,    68,    38,    48,    69,    32,    38,
      79,    32,    22,   -80,   -80,    39,    38,    83,    52,    65,
      67,    38,    68,    49,    60,   120,    38,    53,    72,    75,
      75,    80,   149,    38,    88,    40,    41,    42,    43,    40,
      41,    78,    43,     1,    32,    72,    84,    41,     2,    43,
      33,    40,    41,   107,    43,    95,    40,    41,    92,    43,
     105,   106,    38,    40,    41,    87,    43,   118,    67,    36,
      68,   114,     3,     4,     5,     6,   122,    37,   126,   127,
     128,   129,   130,   131,     4,     5,     6,   109,   110,    50,
     134,   135,    84,    41,    90,    43,   123,    57,    96,   124,
      91,    13,    52,   -55,    51,   146,   116,   143,    97,    98,
      99,   100,   101,   102,    60,    54,    95,    61,    14,    15,
      32,    16,    17,    18,    62,     4,     5,     6,    19,    59,
     103,   104,    14,    15,    32,    16,    17,    18,    63,     4,
       5,     6,    19,    89,    52,    66,    14,    15,    82,    16,
      17,    18,   119,   108,   145,    67,    19,    68,   111,   112,
      14,    15,   148,    16,    17,    18,     2,   -80,   -80,   115,
      19,    14,    15,   117,    16,    17,    18,   121,     2,    14,
      15,    19,    16,    17,    18,   113,    67,   132,    68,    19,
       3,     4,     5,     6,    34,    97,    98,    99,   100,   101,
     102,    97,    98,    99,   100,   101,   102,     4,     5,     6,
      70,   137,    71,   141,   147,   142,   125,   138,   139,   140,
     144,    77,    55,     0,    81
};

static const yytype_int16 yycheck[] =
{
       2,    23,     8,    20,     2,    14,   111,     4,    38,    20,
      21,     8,     8,    10,    10,     3,     3,    13,    20,     3,
      50,    23,    20,    20,    21,    13,     3,     4,     3,    38,
       8,     3,    10,     3,    56,    13,     3,    12,    22,    48,
      49,    50,   147,     3,    53,    33,    34,    35,    36,    33,
      34,    35,    36,     0,    56,    22,    33,    34,     5,    36,
       0,    33,    34,    72,    36,    63,    33,    34,     4,    36,
      70,    71,     3,    33,    34,    35,    36,     7,     8,    33,
      10,     4,    29,    30,    31,    32,    92,     0,    97,    98,
      99,   100,   101,   102,    30,    31,    32,    20,    21,     3,
     109,   110,    33,    34,     7,    36,     4,    33,     4,     7,
      13,     6,     3,     4,     3,   132,     7,   123,    14,    15,
      16,    17,    18,    19,   146,     6,   124,    13,    23,    24,
     132,    26,    27,    28,     0,    30,    31,    32,    33,     6,
      67,    68,    23,    24,   146,    26,    27,    28,     3,    30,
      31,    32,    33,     6,     3,    13,    23,    24,    33,    26,
      27,    28,    13,     4,     6,     8,    33,    10,     4,     4,
      23,    24,     6,    26,    27,    28,     5,    20,    21,     4,
      33,    23,    24,     4,    26,    27,    28,    33,     5,    23,
      24,    33,    26,    27,    28,     4,     8,     5,    10,    33,
      29,    30,    31,    32,     8,    14,    15,    16,    17,    18,
      19,    14,    15,    16,    17,    18,    19,    30,    31,    32,
       9,    13,    11,   116,    25,   118,    33,    13,    13,    13,
     124,    49,    20,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     0,     5,    29,    30,    31,    32,    38,    39,    40,
      41,    44,    47,     6,    23,    24,    26,    27,    28,    33,
      45,    46,    47,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,    40,    44,    33,     0,     3,    13,
      33,    34,    35,    36,    59,    63,    64,    65,     3,     3,
       3,     3,     3,    12,     6,    46,    50,    33,    48,     6,
      51,    13,     0,     3,    62,    63,    13,     8,    10,    13,
       9,    11,    22,    61,    62,    63,    66,    61,    35,    62,
      63,    66,    33,     4,    33,    60,    63,    35,    63,     6,
       7,    13,     4,    42,    43,    47,     4,    14,    15,    16,
      17,    18,    19,    64,    64,    65,    65,    63,     4,    20,
      21,     4,     4,     4,     4,     4,     7,     4,     7,    13,
      13,    33,    44,     4,     7,    33,    63,    63,    63,    63,
      63,    63,     5,    49,    63,    63,    49,    13,    13,    13,
      13,    60,    60,    44,    43,     6,    50,    25,     6,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    38,    39,    39,    40,    40,    41,
      41,    42,    42,    43,    44,    44,    44,    44,    45,    45,
      46,    47,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      53,    53,    54,    55,    55,    56,    56,    56,    57,    58,
      59,    59,    60,    60,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    64,
      64,    64,    65,    65,    65,    65,    65,    66,    66,    66,
      66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     1,     6,     5,     1,
       1,     3,     1,     2,     4,     3,     3,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       5,     7,     5,     4,     4,     5,     5,     5,     5,     2,
       4,     3,     3,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     2,
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
  case 2: /* Programa: ListaFuncoes BlocoPrincipal $end  */
#line 100 "expr.y"
                                            {AddFuncao((yyvsp[-2].funcao), criaFuncao(TIPO_INT, "main", NULL, (yyvsp[-1].bloco)));printFuncao((yyvsp[-2].funcao));}
#line 1550 "expr.tab.c"
    break;

  case 3: /* Programa: BlocoPrincipal $end  */
#line 101 "expr.y"
                               {printFuncao(criaFuncao(285, "main", NULL, (yyvsp[-1].bloco)));}
#line 1556 "expr.tab.c"
    break;

  case 4: /* Programa: $end  */
#line 102 "expr.y"
                {exit(0);}
#line 1562 "expr.tab.c"
    break;

  case 5: /* ListaFuncoes: ListaFuncoes Funcao  */
#line 104 "expr.y"
                                  {AddFuncao((yyvsp[-1].funcao), (yyvsp[0].funcao));(yyval.funcao) = (yyvsp[-1].funcao);}
#line 1568 "expr.tab.c"
    break;

  case 6: /* ListaFuncoes: Funcao  */
#line 105 "expr.y"
                 {(yyval.funcao) = (yyvsp[0].funcao);}
#line 1574 "expr.tab.c"
    break;

  case 7: /* Funcao: TipoRetorno TID SIM_ABREPARENTESES DeclParametros SIM_FECHAPARENTESES BlocoPrincipal  */
#line 107 "expr.y"
                                                                                             {(yyval.funcao) = criaFuncao((yyvsp[-5].integer), (yyvsp[-4].id), (yyvsp[-2].item), (yyvsp[0].bloco));}
#line 1580 "expr.tab.c"
    break;

  case 8: /* Funcao: TipoRetorno TID SIM_ABREPARENTESES SIM_FECHAPARENTESES BlocoPrincipal  */
#line 108 "expr.y"
                                                                                {(yyval.funcao) = criaFuncao((yyvsp[-4].integer), (yyvsp[-3].id), NULL, (yyvsp[0].bloco));}
#line 1586 "expr.tab.c"
    break;

  case 9: /* TipoRetorno: Tipo  */
#line 110 "expr.y"
                  {(yyval.integer) = (yyvsp[0].integer);}
#line 1592 "expr.tab.c"
    break;

  case 10: /* TipoRetorno: TIPO_VOID  */
#line 111 "expr.y"
                    {(yyval.integer) = TIPO_VOID;}
#line 1598 "expr.tab.c"
    break;

  case 11: /* DeclParametros: DeclParametros SIM_VIRGULA Parametro  */
#line 113 "expr.y"
                                                     {AddItem((yyvsp[-2].item), criaItem((yyvsp[0].nPtr)));(yyval.item) = (yyvsp[-2].item);}
#line 1604 "expr.tab.c"
    break;

  case 12: /* DeclParametros: Parametro  */
#line 114 "expr.y"
                    {(yyval.item) = criaItem((yyvsp[0].nPtr));}
#line 1610 "expr.tab.c"
    break;

  case 13: /* Parametro: Tipo TID  */
#line 116 "expr.y"
                    {(yyval.nPtr) = criaId((yyvsp[0].id), (yyvsp[-1].integer));}
#line 1616 "expr.tab.c"
    break;

  case 14: /* BlocoPrincipal: SIM_ABRECHAVES Declaracoes ListaCmd SIM_FECHACHAVES  */
#line 118 "expr.y"
                                                                    {(yyval.bloco) = criaBloco((yyvsp[-2].listadecl), (yyvsp[-1].item));}
#line 1622 "expr.tab.c"
    break;

  case 15: /* BlocoPrincipal: SIM_ABRECHAVES Declaracoes SIM_FECHACHAVES  */
#line 119 "expr.y"
                                                     {(yyval.bloco) = criaBloco((yyvsp[-1].listadecl), NULL);}
#line 1628 "expr.tab.c"
    break;

  case 16: /* BlocoPrincipal: SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES  */
#line 120 "expr.y"
                                                  {(yyval.bloco) = criaBloco(NULL, (yyvsp[-1].item));}
#line 1634 "expr.tab.c"
    break;

  case 17: /* BlocoPrincipal: SIM_ABRECHAVES SIM_FECHACHAVES  */
#line 121 "expr.y"
                                         {(yyval.bloco) = NULL;}
#line 1640 "expr.tab.c"
    break;

  case 18: /* Declaracoes: Declaracoes Declaracao  */
#line 123 "expr.y"
                                    {AddListaDecl((yyvsp[-1].listadecl), criaListaDecl((yyvsp[0].declaracao)));(yyval.listadecl) = (yyvsp[-1].listadecl);}
#line 1646 "expr.tab.c"
    break;

  case 19: /* Declaracoes: Declaracao  */
#line 124 "expr.y"
                     {(yyval.listadecl) = criaListaDecl((yyvsp[0].declaracao));}
#line 1652 "expr.tab.c"
    break;

  case 20: /* Declaracao: Tipo ListaId SIM_FIM  */
#line 126 "expr.y"
                                 {(yyval.declaracao) = criaDeclaracao((yyvsp[-2].integer), (yyvsp[-1].item));}
#line 1658 "expr.tab.c"
    break;

  case 21: /* Tipo: TIPO_INT  */
#line 128 "expr.y"
               {tp_sim = TIPO_INT;(yyval.integer) = TIPO_INT;}
#line 1664 "expr.tab.c"
    break;

  case 22: /* Tipo: TIPO_STRING  */
#line 129 "expr.y"
                      {tp_sim = TIPO_STRING;(yyval.integer) = TIPO_STRING;}
#line 1670 "expr.tab.c"
    break;

  case 23: /* Tipo: TIPO_FLOAT  */
#line 130 "expr.y"
                     {tp_sim = TIPO_FLOAT;(yyval.integer) = TIPO_FLOAT;}
#line 1676 "expr.tab.c"
    break;

  case 24: /* ListaId: ListaId SIM_VIRGULA TID  */
#line 132 "expr.y"
                                 {AddItem((yyvsp[-2].item), criaItem(criaId((yyvsp[0].id), 2)));(yyval.item) = (yyvsp[-2].item);}
#line 1682 "expr.tab.c"
    break;

  case 25: /* ListaId: TID  */
#line 133 "expr.y"
              {(yyval.item) = criaItem(criaId((yyvsp[0].id), 2));}
#line 1688 "expr.tab.c"
    break;

  case 26: /* Bloco: SIM_ABRECHAVES ListaCmd SIM_FECHACHAVES  */
#line 135 "expr.y"
                                               {(yyval.item) = (yyvsp[-1].item);}
#line 1694 "expr.tab.c"
    break;

  case 27: /* Bloco: SIM_ABRECHAVES SIM_FECHACHAVES  */
#line 136 "expr.y"
                                         {(yyval.item) = NULL;}
#line 1700 "expr.tab.c"
    break;

  case 28: /* ListaCmd: ListaCmd Comando  */
#line 138 "expr.y"
                           {(yyvsp[-1].item)->prox = criaItem((yyvsp[0].nPtr)); (yyval.item) = (yyvsp[-1].item);}
#line 1706 "expr.tab.c"
    break;

  case 29: /* ListaCmd: Comando  */
#line 139 "expr.y"
                  {(yyval.item) = criaItem((yyvsp[0].nPtr));}
#line 1712 "expr.tab.c"
    break;

  case 30: /* Comando: CmdIf  */
#line 141 "expr.y"
               {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1718 "expr.tab.c"
    break;

  case 31: /* Comando: CmdWhile  */
#line 142 "expr.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1724 "expr.tab.c"
    break;

  case 32: /* Comando: CmdAtrib  */
#line 143 "expr.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1730 "expr.tab.c"
    break;

  case 33: /* Comando: CmdWrite  */
#line 144 "expr.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1736 "expr.tab.c"
    break;

  case 34: /* Comando: CmdRead  */
#line 145 "expr.y"
                  {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1742 "expr.tab.c"
    break;

  case 35: /* Comando: ChamadaProc  */
#line 146 "expr.y"
                      {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1748 "expr.tab.c"
    break;

  case 36: /* Comando: Retorno  */
#line 147 "expr.y"
                  {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1754 "expr.tab.c"
    break;

  case 37: /* Retorno: COM_RETORNO Expra SIM_FIM  */
#line 149 "expr.y"
                                   {(yyval.nPtr) = criaOpr(COM_RETORNO, NULL, 1, (yyvsp[-1].nPtr));}
#line 1760 "expr.tab.c"
    break;

  case 38: /* Retorno: COM_RETORNO CONS_LITERAL SIM_FIM  */
#line 150 "expr.y"
                                           {(yyval.nPtr) = criaOpr(COM_RETORNO, NULL, 1, criaString((yyvsp[-1].string)));}
#line 1766 "expr.tab.c"
    break;

  case 39: /* Retorno: COM_RETORNO SIM_FIM  */
#line 151 "expr.y"
                              {(yyval.nPtr) = criaOpr(COM_RETORNO, NULL, 0);}
#line 1772 "expr.tab.c"
    break;

  case 40: /* CmdIf: COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco  */
#line 153 "expr.y"
                                                                {(yyval.nPtr) = criaOpr(COM_SE, criaRepeticao((yyvsp[0].item), NULL), 1, (yyvsp[-2].nPtr));}
#line 1778 "expr.tab.c"
    break;

  case 41: /* CmdIf: COM_SE SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco COM_SENAO Bloco  */
#line 154 "expr.y"
                                                                                   {(yyval.nPtr) = criaOpr(COM_SENAO, criaRepeticao((yyvsp[-2].item), (yyvsp[0].item)), 1, (yyvsp[-4].nPtr));}
#line 1784 "expr.tab.c"
    break;

  case 42: /* CmdWhile: COM_ENQUANTO SIM_ABREPARENTESES Expr SIM_FECHAPARENTESES Bloco  */
#line 156 "expr.y"
                                                                         {(yyval.nPtr) = criaOpr(COM_ENQUANTO, criaRepeticao((yyvsp[0].item), NULL), 1, (yyvsp[-2].nPtr));}
#line 1790 "expr.tab.c"
    break;

  case 43: /* CmdAtrib: TID SIM_IGUAL Expra SIM_FIM  */
#line 158 "expr.y"
                                      {(yyval.nPtr) = criaOpr(SIM_IGUAL, NULL, 2, criaId((yyvsp[-3].id), 0), (yyvsp[-1].nPtr));}
#line 1796 "expr.tab.c"
    break;

  case 44: /* CmdAtrib: TID SIM_IGUAL CONS_LITERAL SIM_FIM  */
#line 159 "expr.y"
                                             {(yyval.nPtr) = criaOpr(SIM_IGUAL, NULL, 2, criaId((yyvsp[-3].id), 0), criaString((yyvsp[-1].string)));}
#line 1802 "expr.tab.c"
    break;

  case 45: /* CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES SIM_FIM  */
#line 161 "expr.y"
                                                                           {(yyval.nPtr) = criaOpr(COM_IMPRIME, NULL, 1, (yyvsp[-2].nPtr));}
#line 1808 "expr.tab.c"
    break;

  case 46: /* CmdWrite: COM_IMPRIME SIM_ABREPARENTESES Exprl SIM_FECHAPARENTESES SIM_FIM  */
#line 162 "expr.y"
                                                                           {(yyval.nPtr) = criaOpr(COM_IMPRIME, NULL, 1, (yyvsp[-2].nPtr));}
#line 1814 "expr.tab.c"
    break;

  case 47: /* CmdWrite: COM_IMPRIME SIM_ABREPARENTESES CONS_LITERAL SIM_FECHAPARENTESES SIM_FIM  */
#line 163 "expr.y"
                                                                                  {(yyval.nPtr) = criaOpr(COM_IMPRIME, NULL, 1, criaString((yyvsp[-2].string)));}
#line 1820 "expr.tab.c"
    break;

  case 48: /* CmdRead: COM_LER SIM_ABREPARENTESES TID SIM_FECHAPARENTESES SIM_FIM  */
#line 165 "expr.y"
                                                                    {(yyval.nPtr) = criaOpr(COM_LER, NULL, 1, criaId((yyvsp[-2].id), 0));}
#line 1826 "expr.tab.c"
    break;

  case 49: /* ChamadaProc: ChamaFuncao SIM_FIM  */
#line 167 "expr.y"
                                 {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1832 "expr.tab.c"
    break;

  case 50: /* ChamaFuncao: TID SIM_ABREPARENTESES ListaParametros SIM_FECHAPARENTESES  */
#line 169 "expr.y"
                                                                        {(yyval.nPtr) = criaOpr(1, NULL, 2, criaId((yyvsp[-3].id), 1), (yyvsp[-1].nPtr));}
#line 1838 "expr.tab.c"
    break;

  case 51: /* ChamaFuncao: TID SIM_ABREPARENTESES SIM_FECHAPARENTESES  */
#line 170 "expr.y"
                                                     {(yyval.nPtr) = criaOpr(1, NULL, 1, criaId((yyvsp[-2].id), 1));}
#line 1844 "expr.tab.c"
    break;

  case 52: /* ListaParametros: Expra SIM_VIRGULA ListaParametros  */
#line 172 "expr.y"
                                                   {(yyval.nPtr) = criaOpr(2, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1850 "expr.tab.c"
    break;

  case 53: /* ListaParametros: TID SIM_VIRGULA ListaParametros  */
#line 173 "expr.y"
                                          {(yyval.nPtr) = criaOpr(2, NULL, 2, criaId((yyvsp[-2].id), 0), (yyvsp[0].nPtr));}
#line 1856 "expr.tab.c"
    break;

  case 54: /* ListaParametros: Expra  */
#line 174 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1862 "expr.tab.c"
    break;

  case 55: /* ListaParametros: TID  */
#line 175 "expr.y"
              {(yyval.nPtr) = criaId((yyvsp[0].id), 0);}
#line 1868 "expr.tab.c"
    break;

  case 56: /* Expr: Exprl  */
#line 178 "expr.y"
            {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1874 "expr.tab.c"
    break;

  case 57: /* Expr: Expra  */
#line 179 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1880 "expr.tab.c"
    break;

  case 58: /* Expr: Exprr  */
#line 180 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1886 "expr.tab.c"
    break;

  case 59: /* Exprr: Exprr SIM_MAIORQUE Expra  */
#line 182 "expr.y"
                                {(yyval.nPtr) = criaOpr(SIM_MAIORQUE, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1892 "expr.tab.c"
    break;

  case 60: /* Exprr: Exprr SIM_MENORQUE Expra  */
#line 183 "expr.y"
                                   {(yyval.nPtr) = criaOpr(SIM_MENORQUE, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1898 "expr.tab.c"
    break;

  case 61: /* Exprr: Exprr SIM_MAIOROUIGUAL Expra  */
#line 184 "expr.y"
                                       {(yyval.nPtr) = criaOpr(SIM_MAIOROUIGUAL, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1904 "expr.tab.c"
    break;

  case 62: /* Exprr: Exprr SIM_MENOROUIGUAL Expra  */
#line 185 "expr.y"
                                       {(yyval.nPtr) = criaOpr(SIM_MENOROUIGUAL, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1910 "expr.tab.c"
    break;

  case 63: /* Exprr: Exprr SIM_IGUALIGUAL Expra  */
#line 186 "expr.y"
                                     {(yyval.nPtr) = criaOpr(SIM_IGUALIGUAL, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1916 "expr.tab.c"
    break;

  case 64: /* Exprr: Exprr SIM_DIFERENTE Expra  */
#line 187 "expr.y"
                                    {(yyval.nPtr) = criaOpr(SIM_DIFERENTE, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1922 "expr.tab.c"
    break;

  case 65: /* Exprr: Expra  */
#line 188 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1928 "expr.tab.c"
    break;

  case 66: /* Expra: Expra SIM_ADICAO Termo  */
#line 190 "expr.y"
                              {(yyval.nPtr) = criaOpr(SIM_ADICAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1934 "expr.tab.c"
    break;

  case 67: /* Expra: Expra SIM_SUBTRACAO Termo  */
#line 191 "expr.y"
                                    {(yyval.nPtr) = criaOpr(SIM_SUBTRACAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1940 "expr.tab.c"
    break;

  case 68: /* Expra: Termo  */
#line 192 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1946 "expr.tab.c"
    break;

  case 69: /* Termo: Termo SIM_MULTIPLICACAO Fator  */
#line 194 "expr.y"
                                     {(yyval.nPtr) = criaOpr(SIM_MULTIPLICACAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1952 "expr.tab.c"
    break;

  case 70: /* Termo: Termo SIM_DIVISAO Fator  */
#line 195 "expr.y"
                                  {(yyval.nPtr) = criaOpr(SIM_DIVISAO, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1958 "expr.tab.c"
    break;

  case 71: /* Termo: Fator  */
#line 196 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1964 "expr.tab.c"
    break;

  case 72: /* Fator: CONS_INT  */
#line 198 "expr.y"
                {(yyval.nPtr) = criaInteger((yyvsp[0].integer));}
#line 1970 "expr.tab.c"
    break;

  case 73: /* Fator: CONS_FLOAT  */
#line 199 "expr.y"
                     {(yyval.nPtr) = criaReal((yyvsp[0].real));}
#line 1976 "expr.tab.c"
    break;

  case 74: /* Fator: TID  */
#line 200 "expr.y"
              {(yyval.nPtr) = criaId((yyvsp[0].id), 0);}
#line 1982 "expr.tab.c"
    break;

  case 75: /* Fator: ChamaFuncao  */
#line 201 "expr.y"
                      {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1988 "expr.tab.c"
    break;

  case 76: /* Fator: SIM_ABREPARENTESES Exprr SIM_FECHAPARENTESES  */
#line 202 "expr.y"
                                                       {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1994 "expr.tab.c"
    break;

  case 77: /* Exprl: Exprl SIM_E Expra  */
#line 204 "expr.y"
                         {(yyval.nPtr) = criaOpr(SIM_E, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 2000 "expr.tab.c"
    break;

  case 78: /* Exprl: Exprl SIM_OU Expra  */
#line 205 "expr.y"
                             {(yyval.nPtr) = criaOpr(SIM_OU, NULL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 2006 "expr.tab.c"
    break;

  case 79: /* Exprl: SIM_NEGACAO Expra  */
#line 206 "expr.y"
                            {(yyval.nPtr) = criaOpr(SIM_NEGACAO, NULL, 1, (yyvsp[0].nPtr));}
#line 2012 "expr.tab.c"
    break;

  case 80: /* Exprl: Expra  */
#line 207 "expr.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2018 "expr.tab.c"
    break;


#line 2022 "expr.tab.c"

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

#line 209 "expr.y"

#define SIZEOF_TIPONO ((char *)&no->inteiro - (char *)no)

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
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
	Item *i = tbl_fun;
	while(i != NULL){
		if (!strcmp(i->arv->id.name, n))
			return i->arv;
		i = i->prox;
	}
	printf("Função %s não foi encontrada.\n", n);
	exit(1);
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

int inFila(Item *f, char *name){
	while(f){
		if (!strcmp(f->arv->id.name, name))
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
			if (!inFila(tbl_sim, no->id.name)){
				AddItem(tbl_sim, criaItem(no));
			} else {
				printf("Variável %s já foi declarada anteriormente", name);
				exit(1);
			}
		}
	} 
	printf("%d %s %s\n", no->id.i, getIdTipo(no->id.tipo), no->id.name);
	
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
	
	if (opr == SIM_IGUAL){
		if (no->opr.op[1]->type == typeOpr){ // Operação
			if (no->opr.op[1]->opr.opr == 1){ // Chama Função
				if (no->opr.op[0]->id.tipo != no->opr.op[1]->opr.op[0]->id.tipo){
					printf("Retorno %s da função %s não pode ser atribuído à variável %s a qual tem tipo %s\n", getIdTipo(no->opr.op[1]->opr.op[0]->id.tipo), no->opr.op[1]->opr.op[0]->id.name, no->opr.op[0]->id.name, getIdTipo(no->opr.op[0]->id.tipo)); 
					exit(1);
				}
			}
		} else if (no->opr.op[0]->id.tipo == typeString || no->opr.op[1]->id.tipo == typeString){
			printf("Não é possível atribuir %s á %s", getIdTipo(no->opr.op[1]->id.tipo), getIdTipo(no->opr.op[0]->id.tipo));
			exit(1);
		} else if (no->opr.op[0]->id.tipo != no->opr.op[1]->id.tipo){
			printf("Aviso:Tipo %s sendo atribuído a tipo %s\n", getIdTipo(no->opr.op[1]->id.tipo), getIdTipo(no->opr.op[0]->id.tipo));
		}
	} else if (opr == SIM_E || opr == SIM_OU){
		if ((no->opr.op[0]->id.tipo == typeString && no->opr.op[1]->id.tipo != typeString) || (no->opr.op[0]->id.tipo != typeString && no->opr.op[1]->id.tipo == typeString)){
			printf("Os dois operandos de operações relacionais devem ser strings\n");
			exit(1);
		}
	} else if (opr == SIM_ADICAO || opr == SIM_SUBTRACAO || opr == SIM_MULTIPLICACAO || opr == SIM_DIVISAO || opr == SIM_IGUALIGUAL || opr == SIM_DIFERENTE || opr == SIM_MAIORQUE || opr == SIM_MENORQUE || opr == SIM_MAIOROUIGUAL || opr == SIM_MENOROUIGUAL){
		if (no->opr.op[0]->id.tipo == typeString){
			printf("Strings só podem ser usadas em expressões relacionais\n");
			exit(1);
		} else if (no->opr.op[1] != NULL){
			if (no->opr.op[1]->id.tipo == typeString){
				printf("Strings só podem ser usadas em expressões relacionais\n");
				exit(1);
			}
		}
		if (no->opr.op[0]->type == typeInt && no->opr.op[1]->type == typeFloat){
			no->opr.op[0]->type = typeFloat;
			no->opr.op[0]->real.val = (float)no->opr.op[0]->inteiro.val;
		} else if (no->opr.op[0]->type == typeFloat && no->opr.op[1]->type == typeInt){
			no->opr.op[1]->type = typeFloat;
			no->opr.op[1]->real.val = (float)no->opr.op[1]->inteiro.val;
		}
	}

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

Item* criaItem(tipoNo *arv){
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
		printf("Error ao alocar memória para a função");
		exit(1);
	}
	if (tbl_fun == NULL){
		tbl_fun = criaItem(criaId(nome, tipo));
		tbl_fun->arv->id.i = 0;
	} else{
		if (!inFila(tbl_fun, nome)){
			AddItem(tbl_fun, criaItem(criaId(nome, tipo)));
		} else{
			printf("Função %s já foi declarada anteriormente", nome);
			exit(1);
		}
	}
	f->tipo = getTipoId(tipo);
	f->name = strdup(nome);
	f->syms = tbl_sim;
	tbl_sim = NULL;
	f->i = 0;
	f->prms = prms;
	f->blc = blc;
	return f;
}

void AddItem(Item *o, Item *ad){
	while(o->prox)
		o = o->prox;
	o->prox = malloc(sizeof(Item));
	if (o->prox == NULL){
		printf("Erro ao alocar memória para o próximo item");
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
		printf("Erro ao alocar memória para a próxima Lista de Declarações");
		exit(1);
	}
	o->prox = ad;
}

void AddFuncao(Funcao *f1, Funcao *f2){
	while(f1->prox != NULL)
		f1 = f1->prox;
	f1->prox = malloc(sizeof(Funcao));
	if (f1->prox == NULL){
		printf("Erro ao alocar memória para a próxima função");
		exit(1);
	}
	f2->i = f1->i + 1;
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
	printf("%s ", getIdTipo(f->tipo));
	printf("%s", f->name);
	
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
