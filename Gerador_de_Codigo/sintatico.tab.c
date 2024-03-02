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
#line 1 "sintatico.y"

#include "asm.h"
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
void yyerror(void *s);

extern int yychar;
extern int textBefore;
extern char lineBuffer[2048];
extern void readInputIntoAuxFile();
extern void getLineBuffer();
extern void deleteAuxFile();

extern char wrongToken[32];
extern int wrongTokenLine;
extern int wrongTokenColumn;

int erroAux = 0;
int semanticError = 0;
int CURRENT_TYPE, AUX_CURRENT_TYPE = -1;
int paramsQntd = 0;
int dimensionError = 0;
char bufferAux[128];
char printDimen[1024];
int defineAux = 0;
int dimensionAux = 0;
int funcAux = 0;
int auxLineAssign, auxColumnAssign;
int auxPosFixa = -1;

Function *auxFunctionList = NULL;
int wasThereDeclarations = 0;

void *prototypeParam = NULL;

void **globalHash = NULL;
void **currentHash = NULL;

Program *AST = NULL;
FILE *mipsFile = NULL;
char *mipsPath = NULL;

void printLineError(int line, int column);


#line 123 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MyEOF = 3,                      /* MyEOF  */
  YYSYMBOL_ERRO = 4,                       /* ERRO  */
  YYSYMBOL_NUMBER_SIGN = 5,                /* NUMBER_SIGN  */
  YYSYMBOL_DEFINE = 6,                     /* DEFINE  */
  YYSYMBOL_L_CURLY_BRACKET = 7,            /* L_CURLY_BRACKET  */
  YYSYMBOL_R_CURLY_BRACKET = 8,            /* R_CURLY_BRACKET  */
  YYSYMBOL_L_PAREN = 9,                    /* L_PAREN  */
  YYSYMBOL_R_PAREN = 10,                   /* R_PAREN  */
  YYSYMBOL_L_SQUARE_BRACKET = 11,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 12,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 14,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 17,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 18,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 19,                 /* REMAINDER  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_CHAR = 21,                      /* CHAR  */
  YYSYMBOL_VOID = 22,                      /* VOID  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_PRINTF = 28,                    /* PRINTF  */
  YYSYMBOL_SCANF = 29,                     /* SCANF  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_EXIT = 31,                      /* EXIT  */
  YYSYMBOL_ADD_ASSIGN = 32,                /* ADD_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 33,              /* MINUS_ASSIGN  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_EQUAL = 35,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 36,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 37,                 /* LESS_THAN  */
  YYSYMBOL_LESS_EQUAL = 38,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_THAN = 39,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUAL = 40,             /* GREATER_EQUAL  */
  YYSYMBOL_BITWISE_AND = 41,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 42,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 43,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 44,               /* BITWISE_NOT  */
  YYSYMBOL_LOGICAL_AND = 45,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 46,                /* LOGICAL_OR  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_TERNARY_CONDITIONAL = 48,       /* TERNARY_CONDITIONAL  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_R_SHIFT = 50,                   /* R_SHIFT  */
  YYSYMBOL_L_SHIFT = 51,                   /* L_SHIFT  */
  YYSYMBOL_INC = 52,                       /* INC  */
  YYSYMBOL_DEC = 53,                       /* DEC  */
  YYSYMBOL_NUM_INT = 54,                   /* NUM_INT  */
  YYSYMBOL_NUM_HEXA = 55,                  /* NUM_HEXA  */
  YYSYMBOL_NUM_OCTAL = 56,                 /* NUM_OCTAL  */
  YYSYMBOL_STRING = 57,                    /* STRING  */
  YYSYMBOL_CHARACTER = 58,                 /* CHARACTER  */
  YYSYMBOL_ID = 59,                        /* ID  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Start = 61,                     /* Start  */
  YYSYMBOL_Programa = 62,                  /* Programa  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_DeclaracaoOUFuncao = 64,        /* DeclaracaoOUFuncao  */
  YYSYMBOL_ListaFuncoes = 65,              /* ListaFuncoes  */
  YYSYMBOL_Declaracoes = 66,               /* Declaracoes  */
  YYSYMBOL_Funcao = 67,                    /* Funcao  */
  YYSYMBOL_DeclaraVariaveisFuncao = 68,    /* DeclaraVariaveisFuncao  */
  YYSYMBOL_Ponteiro = 69,                  /* Ponteiro  */
  YYSYMBOL_DeclaraVariaveis = 70,          /* DeclaraVariaveis  */
  YYSYMBOL_BlocoVariaveis = 71,            /* BlocoVariaveis  */
  YYSYMBOL_ExpressaoColchete = 72,         /* ExpressaoColchete  */
  YYSYMBOL_ExpressaoAssign = 73,           /* ExpressaoAssign  */
  YYSYMBOL_RetornoVariavel = 74,           /* RetornoVariavel  */
  YYSYMBOL_DeclaraPrototipos = 75,         /* DeclaraPrototipos  */
  YYSYMBOL_Parametros = 76,                /* Parametros  */
  YYSYMBOL_BlocoParametros = 77,           /* BlocoParametros  */
  YYSYMBOL_RetornaParametros = 78,         /* RetornaParametros  */
  YYSYMBOL_Tipo = 79,                      /* Tipo  */
  YYSYMBOL_Bloco = 80,                     /* Bloco  */
  YYSYMBOL_Comandos = 81,                  /* Comandos  */
  YYSYMBOL_RetornoComandos = 82,           /* RetornoComandos  */
  YYSYMBOL_ListaComandos = 83,             /* ListaComandos  */
  YYSYMBOL_AuxElse = 84,                   /* AuxElse  */
  YYSYMBOL_AuxFor = 85,                    /* AuxFor  */
  YYSYMBOL_AuxPrint = 86,                  /* AuxPrint  */
  YYSYMBOL_Expressao = 87,                 /* Expressao  */
  YYSYMBOL_OpAtrib = 88,                   /* OpAtrib  */
  YYSYMBOL_OpRel = 89,                     /* OpRel  */
  YYSYMBOL_OpMult = 90,                    /* OpMult  */
  YYSYMBOL_OpUnario = 91,                  /* OpUnario  */
  YYSYMBOL_ExpressaoAtribuicao = 92,       /* ExpressaoAtribuicao  */
  YYSYMBOL_ExpressaoCondicional = 93,      /* ExpressaoCondicional  */
  YYSYMBOL_ExpressaoOrLogico = 94,         /* ExpressaoOrLogico  */
  YYSYMBOL_ExpressaoAndLogico = 95,        /* ExpressaoAndLogico  */
  YYSYMBOL_ExpressaoOr = 96,               /* ExpressaoOr  */
  YYSYMBOL_ExpressaoXor = 97,              /* ExpressaoXor  */
  YYSYMBOL_ExpressaoAnd = 98,              /* ExpressaoAnd  */
  YYSYMBOL_ExpressaoIgual = 99,            /* ExpressaoIgual  */
  YYSYMBOL_ExpressaoRelacional = 100,      /* ExpressaoRelacional  */
  YYSYMBOL_ExpressaoShift = 101,           /* ExpressaoShift  */
  YYSYMBOL_ExpressaoAditiva = 102,         /* ExpressaoAditiva  */
  YYSYMBOL_ExpressaoMultiplicativa = 103,  /* ExpressaoMultiplicativa  */
  YYSYMBOL_ExpressaoCast = 104,            /* ExpressaoCast  */
  YYSYMBOL_ExpressaoUnaria = 105,          /* ExpressaoUnaria  */
  YYSYMBOL_ExpressaoPosFixa = 106,         /* ExpressaoPosFixa  */
  YYSYMBOL_PulaExpressaoAtribuicao = 107,  /* PulaExpressaoAtribuicao  */
  YYSYMBOL_AuxPula = 108,                  /* AuxPula  */
  YYSYMBOL_ExpressaoPrimaria = 109,        /* ExpressaoPrimaria  */
  YYSYMBOL_Numero = 110                    /* Numero  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   182,   182,   187,   188,   190,   190,   205,   209,   224,
     231,   233,   259,   271,   273,   302,   303,   305,   309,   311,
     317,   429,   457,   459,   465,   467,   468,   470,   483,   490,
     544,   546,   549,   551,   556,   561,   567,   577,   592,   606,
     608,   614,   620,   626,   632,   644,   650,   656,   662,   666,
     667,   669,   672,   674,   675,   677,   681,   683,   686,   692,
     693,   694,   696,   697,   698,   699,   701,   702,   703,   705,
     706,   707,   708,   709,   710,   712,   713,   719,   720,   727,
     728,   734,   735,   741,   742,   748,   749,   755,   756,   762,
     763,   768,   774,   775,   781,   782,   787,   793,   794,   799,
     805,   806,   812,   813,   825,   826,   831,   836,   842,   843,
     856,   863,   868,   874,   878,   880,   884,   886,   891,   892,
     897,   902,   906,   911,   916
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MyEOF", "ERRO",
  "NUMBER_SIGN", "DEFINE", "L_CURLY_BRACKET", "R_CURLY_BRACKET", "L_PAREN",
  "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "COMMA", "SEMICOLON",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "REMAINDER", "INT", "CHAR",
  "VOID", "DO", "WHILE", "IF", "ELSE", "FOR", "PRINTF", "SCANF", "RETURN",
  "EXIT", "ADD_ASSIGN", "MINUS_ASSIGN", "ASSIGN", "EQUAL", "NOT_EQUAL",
  "LESS_THAN", "LESS_EQUAL", "GREATER_THAN", "GREATER_EQUAL",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LOGICAL_AND",
  "LOGICAL_OR", "NOT", "TERNARY_CONDITIONAL", "COLON", "R_SHIFT",
  "L_SHIFT", "INC", "DEC", "NUM_INT", "NUM_HEXA", "NUM_OCTAL", "STRING",
  "CHARACTER", "ID", "$accept", "Start", "Programa", "$@1",
  "DeclaracaoOUFuncao", "ListaFuncoes", "Declaracoes", "Funcao",
  "DeclaraVariaveisFuncao", "Ponteiro", "DeclaraVariaveis",
  "BlocoVariaveis", "ExpressaoColchete", "ExpressaoAssign",
  "RetornoVariavel", "DeclaraPrototipos", "Parametros", "BlocoParametros",
  "RetornaParametros", "Tipo", "Bloco", "Comandos", "RetornoComandos",
  "ListaComandos", "AuxElse", "AuxFor", "AuxPrint", "Expressao", "OpAtrib",
  "OpRel", "OpMult", "OpUnario", "ExpressaoAtribuicao",
  "ExpressaoCondicional", "ExpressaoOrLogico", "ExpressaoAndLogico",
  "ExpressaoOr", "ExpressaoXor", "ExpressaoAnd", "ExpressaoIgual",
  "ExpressaoRelacional", "ExpressaoShift", "ExpressaoAditiva",
  "ExpressaoMultiplicativa", "ExpressaoCast", "ExpressaoUnaria",
  "ExpressaoPosFixa", "PulaExpressaoAtribuicao", "AuxPula",
  "ExpressaoPrimaria", "Numero", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,  -169,    11,    90,    82,  -169,  -169,  -169,    26,  -169,
    -169,  -169,    82,  -169,  -169,  -169,  -169,    20,   -15,    82,
    -169,    20,    -8,    41,   190,  -169,  -169,    71,  -169,    75,
    -169,  -169,  -169,  -169,  -169,  -169,   209,   209,  -169,  -169,
    -169,  -169,  -169,  -169,    51,   190,  -169,  -169,    69,    38,
      29,    43,    48,    89,   -17,    86,   123,    88,  -169,    76,
      -5,  -169,  -169,    92,   190,    64,    12,    20,    23,   190,
    -169,  -169,   190,  -169,  -169,   190,   190,   190,   190,   190,
     190,   190,   190,  -169,  -169,  -169,  -169,   190,   190,   190,
     190,   190,  -169,  -169,  -169,   190,  -169,  -169,  -169,   190,
     190,   190,  -169,  -169,   108,    20,   128,   190,   110,    92,
    -169,   116,  -169,  -169,    38,   -11,    29,    43,    48,    89,
     -17,   -17,    86,   123,   123,    88,    88,  -169,  -169,   135,
     142,   130,  -169,    96,   146,  -169,    20,  -169,   157,    92,
      20,   190,   190,   190,  -169,  -169,  -169,   146,  -169,   100,
    -169,   157,  -169,   153,   154,   156,   160,   161,   167,   190,
     168,  -169,   175,   157,   131,  -169,  -169,  -169,   135,   149,
     146,   181,   166,   190,   190,   190,   134,   136,   178,    51,
     190,  -169,  -169,   157,  -169,  -169,    92,  -169,  -169,   187,
      33,    52,   183,   189,   195,  -169,    65,  -169,  -169,   190,
     153,   153,   190,   190,   193,   159,   203,    66,  -169,   194,
     205,   208,   213,   163,  -169,   214,   153,  -169,   190,   190,
    -169,  -169,   219,  -169,  -169,   220,  -169,   218,   153,  -169,
    -169
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     0,     1,     2,     3,     0,    33,
      34,    35,    10,     7,     8,    12,    13,    18,     0,    10,
       6,    18,     0,     0,     0,     9,    17,    22,    19,     0,
      71,    72,    70,    69,    74,    73,     0,     0,   122,   123,
     124,   120,   119,   117,    11,     0,    57,    75,    77,    79,
      81,    83,    85,    87,    89,    92,    94,    97,   100,   102,
     104,   108,   118,    30,     0,    24,     0,    18,     0,     0,
     105,   106,     0,   107,   102,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,     0,     0,     0,
       0,     0,    66,    67,    68,     0,    60,    61,    59,     0,
     114,     0,   111,   112,     0,    18,     0,     0,    26,    16,
      27,     0,   121,    58,    80,     0,    82,    84,    86,    88,
      90,    91,    93,    95,    96,    98,    99,   101,    76,   116,
       0,     0,    28,     0,    22,    23,    18,    20,     0,    16,
      18,     0,     0,     0,   113,   110,   109,    22,    21,     0,
      25,     0,    49,     0,     0,     0,     0,     0,     0,    54,
       0,    50,     0,    39,     0,    15,   103,    78,   116,    32,
      22,     0,     0,     0,     0,    54,     0,     0,     0,    53,
       0,    14,    37,    39,    48,   115,    30,    29,    36,     0,
       0,     0,     0,    56,     0,    47,     0,    38,    31,     0,
       0,     0,    54,     0,     0,     0,     0,     0,    41,    52,
       0,    56,     0,     0,    46,     0,     0,    42,    54,     0,
      55,    44,     0,    40,    51,     0,    57,     0,     0,    45,
      43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,  -169,   229,   204,  -169,  -169,    97,    -4,
    -100,    99,  -116,  -169,  -169,  -169,  -169,    53,  -169,   -28,
    -128,    87,    57,  -153,  -169,  -168,    30,   -24,  -169,  -169,
    -169,  -169,   -58,   109,  -169,   177,   180,   176,   179,   191,
      72,   172,    58,    77,   -42,   -21,  -169,  -169,   101,  -169,
    -169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    19,    20,    13,    14,   138,   149,
      15,    23,    65,   108,   137,    16,    66,   104,   187,    17,
     161,   162,   182,   163,   217,   178,   204,   164,    99,    87,
      95,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   130,   144,    61,
      62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    67,    72,    73,   100,    68,   101,   192,     1,   139,
     183,     5,    -5,    22,   113,    70,    71,    26,   148,   109,
      83,    84,    85,    86,    74,   172,   110,    -5,    -5,    -5,
     183,   169,    18,   112,   210,   105,    72,    21,   142,   139,
     106,   128,   129,   200,    24,    68,    72,   102,   103,   135,
     225,    27,   115,   127,    74,    28,    74,    74,    74,    74,
      74,    74,   201,   111,    72,    72,    74,    74,    74,    74,
      74,    78,   208,   209,    74,   206,   215,   131,    72,    72,
      63,   140,    64,    77,    29,   168,    79,     8,   224,    80,
      30,    31,    32,     6,     7,     9,    10,    11,   107,   166,
     230,   133,     9,    10,    11,    92,    93,    94,    96,    97,
      98,   140,     9,    10,    11,    75,    33,    76,   132,    34,
      74,    74,    35,   136,    81,    82,   141,    36,    37,    38,
      39,    40,    41,    42,    43,   179,    88,    89,    90,    91,
     134,    72,   146,    72,    72,   184,   123,   124,   143,   190,
     191,   179,   145,   120,   121,   147,   196,    64,   105,   170,
     151,   226,   186,   173,   151,   174,    29,   125,   126,   175,
     176,   152,    30,    31,    32,   207,   177,   180,   179,   211,
     153,   154,   155,   181,   156,   157,   158,   159,   160,   188,
     189,   193,   195,   194,   179,   211,   199,   202,    33,    29,
     213,    34,   203,   212,    35,    30,    31,    32,   205,    36,
      37,    38,    39,    40,    41,    42,    43,   214,    69,   218,
     216,   219,   222,    25,    30,    31,    32,   221,   223,   227,
     228,    33,   229,    12,    34,   150,   165,    35,   171,   198,
     197,   220,    36,    37,    38,    39,    40,    41,    42,    43,
      33,   167,   114,    34,   117,     0,    35,   116,   118,   122,
       0,    36,    37,    38,    39,    40,    41,    42,    43,   185,
       0,   119
};

static const yytype_int16 yycheck[] =
{
      24,    29,    13,    45,     9,    29,    11,   175,     1,   109,
     163,     0,     5,    17,    72,    36,    37,    21,   134,     7,
      37,    38,    39,    40,    45,   153,    14,    20,    21,    22,
     183,   147,     6,    10,   202,    63,    13,    17,    49,   139,
      64,    99,   100,    10,    59,    69,    13,    52,    53,   107,
     218,    59,    76,    95,    75,    14,    77,    78,    79,    80,
      81,    82,    10,    67,    13,    13,    87,    88,    89,    90,
      91,    42,   200,   201,    95,    10,    10,   101,    13,    13,
       9,   109,    11,    45,     9,   143,    43,     5,   216,    41,
      15,    16,    17,     3,     4,    20,    21,    22,    34,   141,
     228,   105,    20,    21,    22,    17,    18,    19,    32,    33,
      34,   139,    20,    21,    22,    46,    41,    48,    10,    44,
     141,   142,    47,    13,    35,    36,    10,    52,    53,    54,
      55,    56,    57,    58,    59,   159,    50,    51,    15,    16,
      12,    13,    12,    13,    13,    14,    88,    89,    13,   173,
     174,   175,    10,    81,    82,    59,   180,    11,   186,    59,
       7,   219,    13,     9,     7,     9,     9,    90,    91,     9,
       9,    14,    15,    16,    17,   199,     9,     9,   202,   203,
      23,    24,    25,     8,    27,    28,    29,    30,    31,     8,
      24,    57,    14,    57,   218,   219,     9,    14,    41,     9,
      41,    44,    13,    10,    47,    15,    16,    17,    13,    52,
      53,    54,    55,    56,    57,    58,    59,    14,     9,    14,
      26,    13,    59,    19,    15,    16,    17,    14,    14,    10,
      10,    41,    14,     4,    44,   136,   139,    47,   151,   186,
     183,   211,    52,    53,    54,    55,    56,    57,    58,    59,
      41,   142,    75,    44,    78,    -1,    47,    77,    79,    87,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,   168,
      -1,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    61,    62,    63,     0,     3,     4,     5,    20,
      21,    22,    64,    66,    67,    70,    75,    79,     6,    64,
      65,    17,    69,    71,    59,    65,    69,    59,    14,     9,
      15,    16,    17,    41,    44,    47,    52,    53,    54,    55,
      56,    57,    58,    59,    87,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   109,   110,     9,    11,    72,    76,    79,    87,     9,
     105,   105,    13,   104,   105,    46,    48,    45,    42,    43,
      41,    35,    36,    37,    38,    39,    40,    89,    50,    51,
      15,    16,    17,    18,    19,    90,    32,    33,    34,    88,
       9,    11,    52,    53,    77,    79,    87,    34,    73,     7,
      14,    69,    10,    92,    95,    87,    96,    97,    98,    99,
     100,   100,   101,   102,   102,   103,   103,   104,    92,    92,
     107,    87,    10,    69,    12,    92,    13,    74,    68,    70,
      79,    10,    49,    13,   108,    10,    12,    59,    72,    69,
      71,     7,    14,    23,    24,    25,    27,    28,    29,    30,
      31,    80,    81,    83,    87,    68,   104,    93,    92,    72,
      59,    81,    80,     9,     9,     9,     9,     9,    85,    87,
       9,     8,    82,    83,    14,   108,    13,    78,     8,    24,
      87,    87,    85,    57,    57,    14,    87,    82,    77,     9,
      10,    10,    14,    13,    86,    13,    10,    87,    80,    80,
      85,    87,    10,    41,    14,    10,    26,    84,    14,    13,
      86,    14,    59,    14,    80,    85,    92,    10,    10,    14,
      80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    63,    62,    64,    64,    65,
      65,    66,    66,    66,    67,    68,    68,    69,    69,    70,
      71,    72,    72,    73,    73,    74,    74,    75,    76,    77,
      77,    78,    78,    79,    79,    79,    80,    81,    82,    82,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   101,   101,   101,   102,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   107,   107,   108,   108,   109,   109,   109,
     109,   109,   110,   110,   110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     3,     1,     1,     2,
       0,     4,     1,     1,     8,     2,     0,     2,     0,     3,
       5,     4,     0,     2,     0,     2,     0,     5,     3,     5,
       0,     2,     0,     1,     1,     1,     3,     2,     2,     0,
       7,     5,     6,     9,     6,     8,     5,     3,     2,     1,
       1,     2,     0,     1,     0,     3,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     5,     1,     2,     2,     2,     1,     4,
       4,     2,     2,     2,     0,     3,     0,     1,     1,     1,
       1,     3,     1,     1,     1
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
  case 2: /* Start: Programa MyEOF  */
#line 182 "sintatico.y"
                      { 
        AST = (yyvsp[-1].prog);
        erroAux = 0; 
        return 0; 
    }
#line 1407 "sintatico.tab.c"
    break;

  case 3: /* Start: Programa ERRO  */
#line 187 "sintatico.y"
                    { erroAux = 1; return 0; }
#line 1413 "sintatico.tab.c"
    break;

  case 4: /* Start: error  */
#line 188 "sintatico.y"
            { erroAux = 1; return 0; }
#line 1419 "sintatico.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 190 "sintatico.y"
          { 
        void **hash = createHash();
        globalHash = hash;
        // printf("criou hash global %p\n", globalHash);
    }
#line 1429 "sintatico.tab.c"
    break;

  case 6: /* Programa: $@1 DeclaracaoOUFuncao ListaFuncoes  */
#line 195 "sintatico.y"
                                    {
        Program *aux = NULL;
        if (wasThereDeclarations == 1) {
            aux = createProgram(globalHash, auxFunctionList, NULL); // $2 should be a list of functions, therefore Function *
        } else {
            aux = createProgram(globalHash, (yyvsp[-1].func), NULL);
        }
        (yyval.prog) = aux; 
    }
#line 1443 "sintatico.tab.c"
    break;

  case 7: /* DeclaracaoOUFuncao: Declaracoes  */
#line 205 "sintatico.y"
                                { /* inserir na hash global o que quer que apareça aqui */
        wasThereDeclarations = 1;
        (yyval.func) = NULL;
    }
#line 1452 "sintatico.tab.c"
    break;

  case 8: /* DeclaracaoOUFuncao: Funcao  */
#line 209 "sintatico.y"
             { 
        if (!auxFunctionList) {
            auxFunctionList = (yyvsp[0].func);
        } else {
            // auxFunctionList->next = $1;
            Function *aux = auxFunctionList;
            while (auxFunctionList->next) {
                auxFunctionList = auxFunctionList->next;
            }
            auxFunctionList->next = (yyvsp[0].func);
            auxFunctionList = aux;
        }
        (yyval.func) = (yyvsp[0].func);  // should return a list of functions
    }
#line 1471 "sintatico.tab.c"
    break;

  case 9: /* ListaFuncoes: DeclaracaoOUFuncao ListaFuncoes  */
#line 224 "sintatico.y"
                                              { 
        if ((yyvsp[-1].func)) {  // se for uma funcao e nao uma declaracao
            (yyval.func) = auxFunctionList;
        } else {
            // printf("chegaaaa %p %p\n", $1, auxFunctionList);
        }
    }
#line 1483 "sintatico.tab.c"
    break;

  case 10: /* ListaFuncoes: %empty  */
#line 231 "sintatico.y"
      { (yyval.func) = NULL; }
#line 1489 "sintatico.tab.c"
    break;

  case 11: /* Declaracoes: NUMBER_SIGN DEFINE ID Expressao  */
#line 233 "sintatico.y"
                                             { /* Adicionar isso na hash */
        // printf("\ntipo da expressao do define %s %d\n", $3.valor, $4->type);
        if ((yyvsp[0].expr)->value->type == STRING) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: string type is not compatible with define", (yyvsp[0].expr)->value->line, (yyvsp[0].expr)->value->column);
            printLineError((yyvsp[0].expr)->value->line, (yyvsp[0].expr)->value->column);
            if (currentHash) freeHash(currentHash);
            if (globalHash) freeHash(globalHash);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }

        if (!lookForValueInHash(globalHash, (yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, INT, &textBefore, &semanticError)) {
            void *node = insertHash(globalHash, (yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, INT, 0);
            setKind(node, VAR);
            setIsConstant(node);
            defineAux = 1;
            // printf("expressao do define %d %p %p\n", $4->type, $4->left, $4->right);
            ResultExpression *result = evalExpression((yyvsp[0].expr), globalHash, NULL, NULL);
            defineAux = 0;
            // printf("\nresult do define %s %d %d\n", $3.valor, result->typeVar, result->assign);
            setGlobalIntVariable((yyvsp[-1].token).valor, result->assign, result->registerType, result->registerNumber);
            setAssign(node, result->assign);
        }
    }
#line 1520 "sintatico.tab.c"
    break;

  case 12: /* Declaracoes: DeclaraVariaveis  */
#line 259 "sintatico.y"
                       {
        if (strlen(printDimen) > 0) {
            printf("%s", printDimen);
            printLineError((yyvsp[0].token).line, (yyvsp[0].token).column);
            if (currentHash) freeHash(currentHash);
            // if (globalHash) freeHash(globalHash);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        currentHash = NULL;
    }
#line 1537 "sintatico.tab.c"
    break;

  case 13: /* Declaracoes: DeclaraPrototipos  */
#line 271 "sintatico.y"
                        { }
#line 1543 "sintatico.tab.c"
    break;

  case 14: /* Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET  */
#line 273 "sintatico.y"
                                                                                                    {
        // printf(">>>>> function name %s\n", $3.valor);
        // vendo se a funcao ja foi declarada
        if (!lookForPrototypeInHash(globalHash, (yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, (yyvsp[-7].token).type, (yyvsp[-4].param), paramsQntd, &textBefore, &semanticError)) {
            if (!lookForValueInHash(globalHash, (yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, (yyvsp[-7].token).type, &textBefore, &semanticError)) {
                void *node = insertHash(globalHash, (yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, (yyvsp[-7].token).type, (yyvsp[-6].ptr));
                setKind(node, FUNCTION);
                setQntdParams(node, paramsQntd);
                setParam(node, (yyvsp[-4].param));
            } 
        }
        if (strlen(printDimen) > 0) {
            printf("%s", printDimen);
            printLineError((yyvsp[-2].token).line, (yyvsp[-2].token).column);
            if (currentHash) freeHash(currentHash);
            if (globalHash) freeHash(globalHash);
            traverseAST(AST);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        Function *func = createFunction(currentHash, (yyvsp[-7].token).type, (yyvsp[-6].ptr), (yyvsp[-5].token).valor, (yyvsp[-1].cmd), NULL);
        // printf("\ncriou funcao %s %p comando %p\n", $3.valor, func, $7);
        paramsQntd = 0;
        currentHash = NULL;
        funcAux = 0;
        (yyval.func) = func;
    }
#line 1576 "sintatico.tab.c"
    break;

  case 15: /* DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao  */
#line 302 "sintatico.y"
                                                                { /* descendo para colocar na hash da funcao */ }
#line 1582 "sintatico.tab.c"
    break;

  case 16: /* DeclaraVariaveisFuncao: %empty  */
#line 303 "sintatico.y"
      { }
#line 1588 "sintatico.tab.c"
    break;

  case 17: /* Ponteiro: MULTIPLY Ponteiro  */
#line 305 "sintatico.y"
                            {
        int ptr = (yyvsp[0].ptr) + 1;
        (yyval.ptr) = ptr;
    }
#line 1597 "sintatico.tab.c"
    break;

  case 18: /* Ponteiro: %empty  */
#line 309 "sintatico.y"
      { (yyval.ptr) = 0; }
#line 1603 "sintatico.tab.c"
    break;

  case 19: /* DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON  */
#line 311 "sintatico.y"
                                                {
        CURRENT_TYPE = (yyvsp[-2].token).type;
        // printf("o que acontece aqui %d\n", $1.type);
        (yyval.token) = (yyvsp[-1].token);  // retornando id da declaracao
    }
#line 1613 "sintatico.tab.c"
    break;

  case 20: /* BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel  */
#line 317 "sintatico.y"
                                                                              {
        if (!currentHash) {
            if (!currentHash && funcAux) {  // hash da funcao
                void **hash = createHash();
                currentHash = hash;
            } else {
                currentHash = globalHash;
            }
        } 
        // printf("\n==> variavel %s tipo %d (%d) %d || linha %d\n", $2.valor, CURRENT_TYPE, AUX_CURRENT_TYPE, $1, $2.line);
        if (CURRENT_TYPE == 277 && (yyvsp[-4].ptr) == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: variable '%s' declared void", (yyvsp[-3].token).line, (yyvsp[-3].token).column, (yyvsp[-3].token).valor);
            printLineError((yyvsp[-3].token).line, (yyvsp[-3].token).column);
            if (currentHash) freeHash(currentHash);
            if (globalHash) freeHash(globalHash);
            traverseAST(AST);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        // considerar o ponteiro, dimensoes e atribuicao se existirem
        if (!lookForValueInHash(currentHash, (yyvsp[-3].token).valor, (yyvsp[-3].token).line, (yyvsp[-3].token).column, CURRENT_TYPE, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, (yyvsp[-3].token).valor, (yyvsp[-3].token).line, (yyvsp[-3].token).column, CURRENT_TYPE, (yyvsp[-4].ptr));
            // printf("\n----- %s %p node %p \n\n", $2.valor, $3, node);
            if (!(yyvsp[-2].dim)) {
                setKind(node, VAR);
            } else {
                // printf("Declaring vector %s %d\n", $2.valor, $3->size);
                int count = 0;
                Dimension *aux = (yyvsp[-2].dim);
                while (aux) {
                    count = count + aux->size;
                    aux = aux->next;
                }
                int s = printDeclareArray(mipsFile, (yyvsp[-3].token).valor, count);
                setSRegisterInHash(node, s);
                setKind(node, VECTOR);
            }

            if (dimensionError != 0) {
                // printf("dimension error\n");
                if (textBefore) printf("\n");
                strcpy(printDimen, "error:semantic:");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", (yyvsp[-3].token).line);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ":");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", (yyvsp[-3].token).column);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ": size of array '");
                strcat(printDimen, (yyvsp[-3].token).valor);
                if (dimensionError == 1) {
                    strcat(printDimen, "' is zero");
                } else if (dimensionError == 2) {
                    strcat(printDimen, "' is negative");
                }
                (yyval.token) = (yyvsp[-3].token);
            }
            setDimensions(node, (yyvsp[-2].dim));

            if ((yyvsp[-1].expr)) {
                setHashExpr(node, (yyvsp[-1].expr), auxLineAssign, auxColumnAssign);
                // printf("node no bison %s tipo = %d  := (%d %p) (%p) in hash %p\n", $2.valor, ((HashNode*)node)->typeVar, $4->type, $4, node, currentHash);
                // ResultExpression *result = evalExpression($4, globalHash, currentHash, NULL);

                // int assignType, assignPointer = result->pointer;
                // // printf("\nassignType %d %d\n", result->typeVar, result->assign);
                // if (result->typeVar == CHAR || result->typeVar == CHARACTER) {
                //     assignType = CHAR;
                // } else if (result->typeVar == INT || result->typeVar == NUM_INT) {
                //     assignType = INT;
                // } else if (result->typeVar == STRING) {
                //     assignType = CHAR;
                //     assignPointer = 1;
                // } else {
                //     assignType = VOID;
                // }
                // if (result->typeVar == VOID && result->pointer == 0) {
                //     if (textBefore) printf("\n");
                //     printf("error:semantic:%d:%d: void value not ignored as it ought to be", auxLineAssign, auxColumnAssign);
                //     printLineError(auxLineAssign, auxColumnAssign);
                //     if (currentHash) freeHash(currentHash);
                //     // if (globalHash) freeHash(globalHash);
                //     deleteMipsFileOnError(mipsFile, mipsPath);
                //     deleteAuxFile();
                //     exit(0);
                // }

                // if (((CURRENT_TYPE == CHAR || CURRENT_TYPE == CHARACTER) && assignType == CHAR) 
                //     || ((CURRENT_TYPE == INT || CURRENT_TYPE == NUM_INT) && assignType == INT)) { // tipos iguais mas ponteiros diferentes
                //     if ($1 != assignPointer) {
                //         if (textBefore) printf("\n");
                //         char *type1 = getExactType(CURRENT_TYPE, $1);
                //         char *type2 = getExactType(assignType, assignPointer);
                //         printf("error:semantic:%d:%d: incompatible types in initialization when assigning to type '%s' from type '%s'", auxLineAssign, auxColumnAssign, type1, type2);
                //         printLineError(auxLineAssign, auxColumnAssign);
                //         if (currentHash) freeHash(currentHash);
                //         // if (globalHash) freeHash(globalHash);
                //         deleteMipsFileOnError(mipsFile, mipsPath);
                //         deleteAuxFile();
                //         exit(1);
                //     }
                // }
                // int regS = printAssignment(mipsFile, result->registerType, result->registerNumber);
                // setSRegisterInHash(node, regS); 
                // setAssign(node, result->assign);
            }
        }
    }
#line 1729 "sintatico.tab.c"
    break;

  case 21: /* ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete  */
#line 429 "sintatico.y"
                                                                                 {
        ResultExpression *result = NULL;
        dimensionAux = 1;
        if ((yyvsp[-2].expr)) result = evalExpression((yyvsp[-2].expr), globalHash, currentHash, NULL);
        if (result) {
            // printf("result->assign %d %d\n", result->assign, result->typeVar);
            if ((result->typeVar != NUM_INT && result->typeVar != INT) || result->pointer != 0) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: array subscript is not an integer", (yyvsp[-3].token).line, (yyvsp[-3].token).column);
                printLineError((yyvsp[-3].token).line, (yyvsp[-3].token).column);
                if (currentHash) freeHash(currentHash);
                // if (globalHash) freeHash(globalHash);
                deleteMipsFileOnError(mipsFile, mipsPath);
                deleteAuxFile();
                exit(1);
            }
            if (result->assign == 0) {
                dimensionError = 1;
            } else if (result->assign < 0) {
                dimensionError = 2;
            }   
            freeRegister(result->registerType, result->registerNumber);
        }
        dimensionAux = 0;
        Dimension *aux = createDimension(result->assign);
        aux->next = (yyvsp[0].dim);
        (yyval.dim) = aux;
    }
#line 1762 "sintatico.tab.c"
    break;

  case 22: /* ExpressaoColchete: %empty  */
#line 457 "sintatico.y"
      { (yyval.dim) = NULL; }
#line 1768 "sintatico.tab.c"
    break;

  case 23: /* ExpressaoAssign: ASSIGN ExpressaoAtribuicao  */
#line 459 "sintatico.y"
                                            { 
        (yyvsp[0].expr)->assign = ASSIGN;
        auxLineAssign = (yyvsp[-1].token).line;
        auxColumnAssign = (yyvsp[-1].token).column;
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1779 "sintatico.tab.c"
    break;

  case 24: /* ExpressaoAssign: %empty  */
#line 465 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1785 "sintatico.tab.c"
    break;

  case 25: /* RetornoVariavel: COMMA BlocoVariaveis  */
#line 467 "sintatico.y"
                                      { if (AUX_CURRENT_TYPE == 0) AUX_CURRENT_TYPE = CURRENT_TYPE; (yyval.token) = (yyvsp[0].token); }
#line 1791 "sintatico.tab.c"
    break;

  case 26: /* RetornoVariavel: %empty  */
#line 468 "sintatico.y"
      { }
#line 1797 "sintatico.tab.c"
    break;

  case 27: /* DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON  */
#line 470 "sintatico.y"
                                                         { 
        // colocar na hash global e ver se bate com as funcoes ?
        void *node = insertHash(globalHash, (yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-4].token).type, (yyvsp[-3].ptr));
        setKind(node, FUNCTION);
        setPrototype(node);
        setQntdParams(node, paramsQntd);
        setParam(node, (yyvsp[-1].param));
        prototypeParam = NULL;
        paramsQntd = 0;
        free(currentHash);
        currentHash = NULL;
    }
#line 1814 "sintatico.tab.c"
    break;

  case 28: /* Parametros: L_PAREN BlocoParametros R_PAREN  */
#line 483 "sintatico.y"
                                            {
        funcAux = 1;
        // printf("parametros %p x %p\n", $2, prototypeParam);
        (yyval.param) = (yyvsp[-1].param);
        // $$ = prototypeParam;
    }
#line 1825 "sintatico.tab.c"
    break;

  case 29: /* BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros  */
#line 490 "sintatico.y"
                                                                      {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }
        if ((yyvsp[-4].token).type == 277 && (yyvsp[-3].ptr) == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: parameter '%s' declared void", (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-2].token).valor);
            printLineError((yyvsp[-2].token).line, (yyvsp[-2].token).column);
            if (currentHash) freeHash(currentHash);
            // traverseAST(AST);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        paramsQntd++;
        Param *aux = createParam((yyvsp[-4].token).type, (yyvsp[-2].token).valor, (yyvsp[-3].ptr), (yyvsp[-2].token).line, (yyvsp[-2].token).column+1, (yyvsp[0].param));
        // printf("tipo param %p %d %s %p\n", aux, aux->type, aux->identifier, aux->next);
        if (!prototypeParam) prototypeParam = aux;

        if (!lookForValueInHash(currentHash, (yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-4].token).type, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, (yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-4].token).type, (yyvsp[-3].ptr));
            setQntdParams(node, paramsQntd);
            
            if (dimensionError != 0) {
                if (textBefore) printf("\n");
                strcpy(printDimen, "error:semantic:");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", (yyvsp[-2].token).line);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ":");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", (yyvsp[-2].token).column);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ": size of array '");
                strcat(printDimen, (yyvsp[-2].token).valor);
                if (dimensionError == 1) {
                    strcat(printDimen, "' is zero");
                } else if (dimensionError == 2) {
                    strcat(printDimen, "' is negative");
                }
            }
            if (!(yyvsp[-1].dim)) {
                setKind(node, VAR);
                aux->kindParam = VAR; 
            } else {
                setKind(node, VECTOR);
                aux->kindParam = VECTOR;
            }
            setDimensions(node, (yyvsp[-1].dim));
        }

        (yyval.param) = aux;
    }
#line 1884 "sintatico.tab.c"
    break;

  case 30: /* BlocoParametros: %empty  */
#line 544 "sintatico.y"
      { (yyval.param) = NULL; }
#line 1890 "sintatico.tab.c"
    break;

  case 31: /* RetornaParametros: COMMA BlocoParametros  */
#line 546 "sintatico.y"
                                         { 
        (yyval.param) = (yyvsp[0].param);
    }
#line 1898 "sintatico.tab.c"
    break;

  case 32: /* RetornaParametros: %empty  */
#line 549 "sintatico.y"
      { (yyval.param) = NULL; }
#line 1904 "sintatico.tab.c"
    break;

  case 33: /* Tipo: INT  */
#line 551 "sintatico.y"
          {
        AUX_CURRENT_TYPE = CURRENT_TYPE;
        CURRENT_TYPE = INT; 
        (yyval.token) = yylval.token; 
    }
#line 1914 "sintatico.tab.c"
    break;

  case 34: /* Tipo: CHAR  */
#line 556 "sintatico.y"
           { 
        AUX_CURRENT_TYPE = CURRENT_TYPE;
        CURRENT_TYPE = CHAR;
        (yyval.token) = yylval.token;
    }
#line 1924 "sintatico.tab.c"
    break;

  case 35: /* Tipo: VOID  */
#line 561 "sintatico.y"
           {
        AUX_CURRENT_TYPE = CURRENT_TYPE;
        CURRENT_TYPE = VOID;
        (yyval.token) = yylval.token;
    }
#line 1934 "sintatico.tab.c"
    break;

  case 36: /* Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET  */
#line 567 "sintatico.y"
                                                { 
    Command *aux = (yyvsp[-1].cmd);
        // while (aux) {
        //     printf("1..comando %p\n", aux);
            aux = aux->next;
        // }
        // printf("comando %p\n", aux);
        (yyval.cmd) = (yyvsp[-1].cmd); 
    }
#line 1948 "sintatico.tab.c"
    break;

  case 37: /* Comandos: ListaComandos RetornoComandos  */
#line 577 "sintatico.y"
                                        {
        // Command *aux = $1;
        // while ($1) {
        //     if ($1->next == NULL) {
        //         printf("2 comando %p %p\n", $1, $2);
        //         $1->next = $2;
        //         break;
        //     }
        //     $1 = $1->next;
        // }
        // $1 = aux;
        (yyvsp[-1].cmd)->next = (yyvsp[0].cmd);
        (yyval.cmd) = (yyvsp[-1].cmd);
    }
#line 1967 "sintatico.tab.c"
    break;

  case 38: /* RetornoComandos: ListaComandos RetornoComandos  */
#line 592 "sintatico.y"
                                               { 
        // Command *aux = $1;
        // while ($1) {
        //     if ($1->next == NULL) {
        //         printf("\n1 comando %p %p\n", $1, $2);
        //         $1->next = $2;
        //         break;
        //     }
        //     $1 = $1->next;
        // }
        // $1 = aux;
        (yyvsp[-1].cmd)->next = (yyvsp[0].cmd);
        (yyval.cmd) = (yyvsp[-1].cmd);
    }
#line 1986 "sintatico.tab.c"
    break;

  case 39: /* RetornoComandos: %empty  */
#line 606 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 1992 "sintatico.tab.c"
    break;

  case 40: /* ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON  */
#line 608 "sintatico.y"
                                                                  {
        AuxToken *auxToken = createAuxToken((yyvsp[-6].token).valor, (yyvsp[-6].token).line, (yyvsp[-6].token).column, DO);
        Command *aux = createDoWhileStatement((yyvsp[-2].expr), (yyvsp[-5].cmd), NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux;
    }
#line 2003 "sintatico.tab.c"
    break;

  case 41: /* ListaComandos: WHILE L_PAREN Expressao R_PAREN Bloco  */
#line 614 "sintatico.y"
                                            {
        AuxToken *auxToken = createAuxToken((yyvsp[-4].token).valor, (yyvsp[-4].token).line, (yyvsp[-4].token).column, WHILE);
        Command *aux = createWhileStatement((yyvsp[-2].expr), (yyvsp[0].cmd), NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux;
    }
#line 2014 "sintatico.tab.c"
    break;

  case 42: /* ListaComandos: IF L_PAREN Expressao R_PAREN Bloco AuxElse  */
#line 620 "sintatico.y"
                                                 {
        AuxToken *auxToken = createAuxToken((yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, IF);
        Command *aux = createIfStatement((yyvsp[-3].expr), (yyvsp[-1].cmd), (yyvsp[0].cmd), NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux;
    }
#line 2025 "sintatico.tab.c"
    break;

  case 43: /* ListaComandos: FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco  */
#line 626 "sintatico.y"
                                                                         {
        AuxToken *auxToken = createAuxToken((yyvsp[-8].token).valor, (yyvsp[-8].token).line, (yyvsp[-8].token).column, FOR);
        Command *aux = createForStatement((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].cmd), NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux;
    }
#line 2036 "sintatico.tab.c"
    break;

  case 44: /* ListaComandos: PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON  */
#line 632 "sintatico.y"
                                                       {
        // Expression *t = $4;
        // while (t) {
        //     ResultExpression *asss = evalExpression(t, globalHash, currentHash, AST);
        //     printf("eval %p = %d\n", asss, asss ? asss->assign : -666);
        //     t = t->nextPrint;
        // }
        AuxToken *auxToken = createAuxToken((yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, PRINTF);
        Command *aux = createPrintStatement((yyvsp[-3].token).valor, (yyvsp[-2].expr), NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux;
    }
#line 2053 "sintatico.tab.c"
    break;

  case 45: /* ListaComandos: SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON  */
#line 644 "sintatico.y"
                                                                  {
        AuxToken *auxToken = createAuxToken((yyvsp[-7].token).valor, (yyvsp[-7].token).line, (yyvsp[-7].token).column, SCANF);
        Command *aux = createScanStatement((yyvsp[-5].token).valor, (yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux;
    }
#line 2064 "sintatico.tab.c"
    break;

  case 46: /* ListaComandos: EXIT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 650 "sintatico.y"
                                               {
        AuxToken *auxToken = createAuxToken((yyvsp[-4].token).valor, (yyvsp[-4].token).line, (yyvsp[-4].token).column, EXIT);
        Command *aux = createExitStatement((yyvsp[-2].expr), NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux; 
    }
#line 2075 "sintatico.tab.c"
    break;

  case 47: /* ListaComandos: RETURN AuxFor SEMICOLON  */
#line 656 "sintatico.y"
                              {
        AuxToken *auxToken = createAuxToken((yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, RETURN);
        Command *aux = createReturnStatement((yyvsp[-1].expr), NULL);
        aux->auxToken = auxToken;
        (yyval.cmd) = aux;
    }
#line 2086 "sintatico.tab.c"
    break;

  case 48: /* ListaComandos: Expressao SEMICOLON  */
#line 662 "sintatico.y"
                          {
        Command *aux = createCommandExpression((yyvsp[-1].expr), NULL);
        (yyval.cmd) = aux;
    }
#line 2095 "sintatico.tab.c"
    break;

  case 49: /* ListaComandos: SEMICOLON  */
#line 666 "sintatico.y"
                { }
#line 2101 "sintatico.tab.c"
    break;

  case 50: /* ListaComandos: Bloco  */
#line 667 "sintatico.y"
            { (yyval.cmd) = (yyvsp[0].cmd); }
#line 2107 "sintatico.tab.c"
    break;

  case 51: /* AuxElse: ELSE Bloco  */
#line 669 "sintatico.y"
                    {
        (yyval.cmd) = (yyvsp[0].cmd);
    }
#line 2115 "sintatico.tab.c"
    break;

  case 52: /* AuxElse: %empty  */
#line 672 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 2121 "sintatico.tab.c"
    break;

  case 53: /* AuxFor: Expressao  */
#line 674 "sintatico.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 2127 "sintatico.tab.c"
    break;

  case 54: /* AuxFor: %empty  */
#line 675 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2133 "sintatico.tab.c"
    break;

  case 55: /* AuxPrint: COMMA Expressao AuxPrint  */
#line 677 "sintatico.y"
                                   { // da conflito de reduce mas paciencia
        (yyvsp[-1].expr)->nextPrint = (yyvsp[0].expr);
        (yyval.expr) = (yyvsp[-1].expr); 
    }
#line 2142 "sintatico.tab.c"
    break;

  case 56: /* AuxPrint: %empty  */
#line 681 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2148 "sintatico.tab.c"
    break;

  case 57: /* Expressao: ExpressaoAtribuicao  */
#line 683 "sintatico.y"
                               {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2156 "sintatico.tab.c"
    break;

  case 58: /* Expressao: Expressao COMMA ExpressaoAtribuicao  */
#line 686 "sintatico.y"
                                          { // o gerador do conflito aqui
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, COMMA);
        Expression *aux = createExpression(LISTA_EXP, COMMA, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2166 "sintatico.tab.c"
    break;

  case 59: /* OpAtrib: ASSIGN  */
#line 692 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 2172 "sintatico.tab.c"
    break;

  case 60: /* OpAtrib: ADD_ASSIGN  */
#line 693 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 2178 "sintatico.tab.c"
    break;

  case 61: /* OpAtrib: MINUS_ASSIGN  */
#line 694 "sintatico.y"
                   { (yyval.token) = yylval.token; }
#line 2184 "sintatico.tab.c"
    break;

  case 62: /* OpRel: LESS_THAN  */
#line 696 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 2190 "sintatico.tab.c"
    break;

  case 63: /* OpRel: LESS_EQUAL  */
#line 697 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 2196 "sintatico.tab.c"
    break;

  case 64: /* OpRel: GREATER_THAN  */
#line 698 "sintatico.y"
                   { (yyval.token) = yylval.token; }
#line 2202 "sintatico.tab.c"
    break;

  case 65: /* OpRel: GREATER_EQUAL  */
#line 699 "sintatico.y"
                    { (yyval.token) = yylval.token; }
#line 2208 "sintatico.tab.c"
    break;

  case 66: /* OpMult: MULTIPLY  */
#line 701 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 2214 "sintatico.tab.c"
    break;

  case 67: /* OpMult: DIVIDE  */
#line 702 "sintatico.y"
             { (yyval.token) = yylval.token; }
#line 2220 "sintatico.tab.c"
    break;

  case 68: /* OpMult: REMAINDER  */
#line 703 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 2226 "sintatico.tab.c"
    break;

  case 69: /* OpUnario: BITWISE_AND  */
#line 705 "sintatico.y"
                      { (yyval.token) = yylval.token; }
#line 2232 "sintatico.tab.c"
    break;

  case 70: /* OpUnario: MULTIPLY  */
#line 706 "sintatico.y"
               { (yyval.token) = yylval.token; }
#line 2238 "sintatico.tab.c"
    break;

  case 71: /* OpUnario: PLUS  */
#line 707 "sintatico.y"
           { (yyval.token) = yylval.token; }
#line 2244 "sintatico.tab.c"
    break;

  case 72: /* OpUnario: MINUS  */
#line 708 "sintatico.y"
            { (yyval.token) = yylval.token; }
#line 2250 "sintatico.tab.c"
    break;

  case 73: /* OpUnario: NOT  */
#line 709 "sintatico.y"
          { (yyval.token) = yylval.token; }
#line 2256 "sintatico.tab.c"
    break;

  case 74: /* OpUnario: BITWISE_NOT  */
#line 710 "sintatico.y"
                  { (yyval.token) = yylval.token; }
#line 2262 "sintatico.tab.c"
    break;

  case 75: /* ExpressaoAtribuicao: ExpressaoCondicional  */
#line 712 "sintatico.y"
                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2268 "sintatico.tab.c"
    break;

  case 76: /* ExpressaoAtribuicao: ExpressaoUnaria OpAtrib ExpressaoAtribuicao  */
#line 713 "sintatico.y"
                                                  {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, (yyvsp[-1].token).type);
        Expression *aux = createExpression(ATRIBUICAO, (yyvsp[-1].token).type, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2278 "sintatico.tab.c"
    break;

  case 77: /* ExpressaoCondicional: ExpressaoOrLogico  */
#line 719 "sintatico.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2284 "sintatico.tab.c"
    break;

  case 78: /* ExpressaoCondicional: ExpressaoOrLogico TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional  */
#line 720 "sintatico.y"
                                                                                 {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, (yyvsp[-1].token).type);
        Expression *aux = createExpression(TERNARY, TERNARY_CONDITIONAL, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        aux->ternary = (yyvsp[-4].expr);
        (yyval.expr) = aux;
    }
#line 2295 "sintatico.tab.c"
    break;

  case 79: /* ExpressaoOrLogico: ExpressaoAndLogico  */
#line 727 "sintatico.y"
                                      { (yyval.expr) = (yyvsp[0].expr); }
#line 2301 "sintatico.tab.c"
    break;

  case 80: /* ExpressaoOrLogico: ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico  */
#line 728 "sintatico.y"
                                                      {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, LOGICAL_OR);
        Expression *aux = createExpression(OR_LOGICO, LOGICAL_OR, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2311 "sintatico.tab.c"
    break;

  case 81: /* ExpressaoAndLogico: ExpressaoOr  */
#line 734 "sintatico.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2317 "sintatico.tab.c"
    break;

  case 82: /* ExpressaoAndLogico: ExpressaoAndLogico LOGICAL_AND ExpressaoOr  */
#line 735 "sintatico.y"
                                                 {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, LOGICAL_AND);
        Expression *aux = createExpression(AND_LOGICO, LOGICAL_AND, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2327 "sintatico.tab.c"
    break;

  case 83: /* ExpressaoOr: ExpressaoXor  */
#line 741 "sintatico.y"
                          { (yyval.expr) = (yyvsp[0].expr);}
#line 2333 "sintatico.tab.c"
    break;

  case 84: /* ExpressaoOr: ExpressaoOr BITWISE_OR ExpressaoXor  */
#line 742 "sintatico.y"
                                          {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, BITWISE_OR);
        Expression *aux = createExpression(OR_BIT, BITWISE_OR, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2343 "sintatico.tab.c"
    break;

  case 85: /* ExpressaoXor: ExpressaoAnd  */
#line 748 "sintatico.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 2349 "sintatico.tab.c"
    break;

  case 86: /* ExpressaoXor: ExpressaoXor BITWISE_XOR ExpressaoAnd  */
#line 749 "sintatico.y"
                                            {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, BITWISE_XOR);
        Expression *aux = createExpression(XOR_BIT, BITWISE_XOR, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2359 "sintatico.tab.c"
    break;

  case 87: /* ExpressaoAnd: ExpressaoIgual  */
#line 755 "sintatico.y"
                             { (yyval.expr) = (yyvsp[0].expr); }
#line 2365 "sintatico.tab.c"
    break;

  case 88: /* ExpressaoAnd: ExpressaoAnd BITWISE_AND ExpressaoIgual  */
#line 756 "sintatico.y"
                                              {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, BITWISE_AND);
        Expression *aux = createExpression(AND_BIT, BITWISE_AND, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2375 "sintatico.tab.c"
    break;

  case 89: /* ExpressaoIgual: ExpressaoRelacional  */
#line 762 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2381 "sintatico.tab.c"
    break;

  case 90: /* ExpressaoIgual: ExpressaoIgual EQUAL ExpressaoRelacional  */
#line 763 "sintatico.y"
                                               {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, EQUAL);
        Expression *aux = createExpression(RELACIONAL, EQUAL, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2391 "sintatico.tab.c"
    break;

  case 91: /* ExpressaoIgual: ExpressaoIgual NOT_EQUAL ExpressaoRelacional  */
#line 768 "sintatico.y"
                                                   {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, NOT_EQUAL);
        Expression *aux = createExpression(RELACIONAL, NOT_EQUAL, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2401 "sintatico.tab.c"
    break;

  case 92: /* ExpressaoRelacional: ExpressaoShift  */
#line 774 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2407 "sintatico.tab.c"
    break;

  case 93: /* ExpressaoRelacional: ExpressaoRelacional OpRel ExpressaoShift  */
#line 775 "sintatico.y"
                                               {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, (yyvsp[-1].token).type);
        Expression *aux = createExpression(RELACIONAL, (yyvsp[-1].token).type, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2417 "sintatico.tab.c"
    break;

  case 94: /* ExpressaoShift: ExpressaoAditiva  */
#line 781 "sintatico.y"
                                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2423 "sintatico.tab.c"
    break;

  case 95: /* ExpressaoShift: ExpressaoShift R_SHIFT ExpressaoAditiva  */
#line 782 "sintatico.y"
                                              {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, R_SHIFT);
        Expression *aux = createExpression(SHIFT, R_SHIFT, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2433 "sintatico.tab.c"
    break;

  case 96: /* ExpressaoShift: ExpressaoShift L_SHIFT ExpressaoAditiva  */
#line 787 "sintatico.y"
                                              {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, L_SHIFT);
        Expression *aux = createExpression(SHIFT, L_SHIFT, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2443 "sintatico.tab.c"
    break;

  case 97: /* ExpressaoAditiva: ExpressaoMultiplicativa  */
#line 793 "sintatico.y"
                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2449 "sintatico.tab.c"
    break;

  case 98: /* ExpressaoAditiva: ExpressaoAditiva PLUS ExpressaoMultiplicativa  */
#line 794 "sintatico.y"
                                                    { 
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, PLUS);
        Expression *aux = createExpression(ADITIVIVA, PLUS, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2459 "sintatico.tab.c"
    break;

  case 99: /* ExpressaoAditiva: ExpressaoAditiva MINUS ExpressaoMultiplicativa  */
#line 799 "sintatico.y"
                                                     { 
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, MINUS);
        Expression *aux = createExpression(ADITIVIVA, MINUS, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2469 "sintatico.tab.c"
    break;

  case 100: /* ExpressaoMultiplicativa: ExpressaoCast  */
#line 805 "sintatico.y"
                                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2475 "sintatico.tab.c"
    break;

  case 101: /* ExpressaoMultiplicativa: ExpressaoMultiplicativa OpMult ExpressaoCast  */
#line 806 "sintatico.y"
                                                   {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, (yyvsp[-1].token).type);
        Expression *aux = createExpression(MULTIPLICATIVA, (yyvsp[-1].token).type, auxToken, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2485 "sintatico.tab.c"
    break;

  case 102: /* ExpressaoCast: ExpressaoUnaria  */
#line 812 "sintatico.y"
                               { (yyval.expr) = (yyvsp[0].expr); }
#line 2491 "sintatico.tab.c"
    break;

  case 103: /* ExpressaoCast: L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast  */
#line 813 "sintatico.y"
                                                  {
        AuxToken *auxToken = createAuxToken((yyvsp[-3].token).valor, (yyvsp[-4].token).line, (yyvsp[-4].token).column, (yyvsp[-3].token).type);
        auxToken->pointer = (yyvsp[-2].ptr);
        Expression *aux = createExpression(CASTING, (yyvsp[-3].token).type, auxToken, NULL, (yyvsp[0].expr));
        // printf("tipo atual antes %d %d\n", CURRENT_TYPE, AUX_CURRENT_TYPE);
        CURRENT_TYPE = AUX_CURRENT_TYPE;
        // AUX_CURRENT_TYPE = -1;
        // printf("tipo atual depois %d %d\n", CURRENT_TYPE, AUX_CURRENT_TYPE);
        aux->pointer = (yyvsp[-2].ptr);
        (yyval.expr) = aux;
    }
#line 2507 "sintatico.tab.c"
    break;

  case 104: /* ExpressaoUnaria: ExpressaoPosFixa  */
#line 825 "sintatico.y"
                                  { (yyval.expr) = (yyvsp[0].expr); }
#line 2513 "sintatico.tab.c"
    break;

  case 105: /* ExpressaoUnaria: INC ExpressaoUnaria  */
#line 826 "sintatico.y"
                          {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, INC);
        Expression *aux = createExpression(UNARIA, INC, auxToken, (yyvsp[0].expr), NULL);
        (yyval.expr) = aux;
    }
#line 2523 "sintatico.tab.c"
    break;

  case 106: /* ExpressaoUnaria: DEC ExpressaoUnaria  */
#line 831 "sintatico.y"
                          {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, DEC);
        Expression *aux = createExpression(UNARIA, DEC, auxToken, (yyvsp[0].expr), NULL);
        (yyval.expr) = aux;
    }
#line 2533 "sintatico.tab.c"
    break;

  case 107: /* ExpressaoUnaria: OpUnario ExpressaoCast  */
#line 836 "sintatico.y"
                             {
        AuxToken *auxToken = createAuxToken((yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, (yyvsp[-1].token).type);
        Expression *aux = createExpression(UNARIA, (yyvsp[-1].token).type, auxToken, (yyvsp[0].expr), NULL);
        (yyval.expr) = aux;
    }
#line 2543 "sintatico.tab.c"
    break;

  case 108: /* ExpressaoPosFixa: ExpressaoPrimaria  */
#line 842 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2549 "sintatico.tab.c"
    break;

  case 109: /* ExpressaoPosFixa: ExpressaoPosFixa L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET  */
#line 843 "sintatico.y"
                                                                   {
        AuxToken *auxToken = createAuxToken((yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-2].token).type);
        Dimension *dimen = createDimensionWithExp((yyvsp[-1].expr), auxToken);
        if ((yyvsp[-3].expr)->type != POS_FIXA) {
            auxToken = createAuxToken((yyvsp[-3].expr)->value->valor, (yyvsp[-3].expr)->value->line, (yyvsp[-3].expr)->value->column, (yyvsp[-3].expr)->value->type);
            Expression *aux = createExpression(POS_FIXA, (yyvsp[-2].token).type, auxToken, (yyvsp[-3].expr), NULL);
            setDimensionExpression(aux, dimen);
            (yyval.expr) = aux;
        } else {
            setDimensionExpression((yyvsp[-3].expr), dimen);
            (yyval.expr) = (yyvsp[-3].expr);
        }
    }
#line 2567 "sintatico.tab.c"
    break;

  case 110: /* ExpressaoPosFixa: ExpressaoPosFixa L_PAREN PulaExpressaoAtribuicao R_PAREN  */
#line 856 "sintatico.y"
                                                               {
        // printf("chegou aqui %p %p %p\n", $3, ((ExpParam *)$3)->next, ((ExpParam *)$3)->next->next);
        AuxToken *auxToken = createAuxToken((yyvsp[-3].expr)->value->valor, (yyvsp[-3].expr)->value->line, (yyvsp[-3].expr)->value->column, (yyvsp[-3].expr)->value->type);
        Expression *aux = createExpression(POS_FIXA, (yyvsp[-2].token).type, auxToken, (yyvsp[-3].expr), NULL);
        aux->param = (yyvsp[-1].paramExp);
        (yyval.expr) = aux;
    }
#line 2579 "sintatico.tab.c"
    break;

  case 111: /* ExpressaoPosFixa: ExpressaoPosFixa INC  */
#line 863 "sintatico.y"
                           {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, INC);
        Expression *aux = createExpression(POS_FIXA, INC, auxToken, (yyvsp[-1].expr), NULL);
        (yyval.expr) = aux;
    }
#line 2589 "sintatico.tab.c"
    break;

  case 112: /* ExpressaoPosFixa: ExpressaoPosFixa DEC  */
#line 868 "sintatico.y"
                           {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, DEC);
        Expression *aux = createExpression(POS_FIXA, DEC, auxToken, (yyvsp[-1].expr), NULL);
        (yyval.expr) = aux;
    }
#line 2599 "sintatico.tab.c"
    break;

  case 113: /* PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula  */
#line 874 "sintatico.y"
                                                     { 
        ExpParam *aux = createExpParam((yyvsp[-1].expr), (yyvsp[0].paramExp));
        (yyval.paramExp) = aux;
    }
#line 2608 "sintatico.tab.c"
    break;

  case 114: /* PulaExpressaoAtribuicao: %empty  */
#line 878 "sintatico.y"
      { (yyval.paramExp) = NULL; }
#line 2614 "sintatico.tab.c"
    break;

  case 115: /* AuxPula: COMMA ExpressaoAtribuicao AuxPula  */
#line 880 "sintatico.y"
                                           {
        ExpParam *aux = createExpParam((yyvsp[-1].expr), (yyvsp[0].paramExp));
        (yyval.paramExp) = aux;
    }
#line 2623 "sintatico.tab.c"
    break;

  case 116: /* AuxPula: %empty  */
#line 884 "sintatico.y"
      { (yyval.paramExp) = NULL; }
#line 2629 "sintatico.tab.c"
    break;

  case 117: /* ExpressaoPrimaria: ID  */
#line 886 "sintatico.y"
                      {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, ID);
        Expression *aux = createExpression(PRIMARIA, ID, auxToken, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2639 "sintatico.tab.c"
    break;

  case 118: /* ExpressaoPrimaria: Numero  */
#line 891 "sintatico.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 2645 "sintatico.tab.c"
    break;

  case 119: /* ExpressaoPrimaria: CHARACTER  */
#line 892 "sintatico.y"
                {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, CHARACTER);
        Expression *aux = createExpression(PRIMARIA, CHARACTER, auxToken, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2655 "sintatico.tab.c"
    break;

  case 120: /* ExpressaoPrimaria: STRING  */
#line 897 "sintatico.y"
             {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, STRING);
        Expression *aux = createExpression(PRIMARIA, STRING, auxToken, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2665 "sintatico.tab.c"
    break;

  case 121: /* ExpressaoPrimaria: L_PAREN Expressao R_PAREN  */
#line 902 "sintatico.y"
                                {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2673 "sintatico.tab.c"
    break;

  case 122: /* Numero: NUM_INT  */
#line 906 "sintatico.y"
                {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, NUM_INT);
        Expression *aux = createExpression(NUMEROS, NUM_INT, auxToken, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2683 "sintatico.tab.c"
    break;

  case 123: /* Numero: NUM_HEXA  */
#line 911 "sintatico.y"
               {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, NUM_HEXA);
        Expression *aux = createExpression(NUMEROS, NUM_HEXA, auxToken, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2693 "sintatico.tab.c"
    break;

  case 124: /* Numero: NUM_OCTAL  */
#line 916 "sintatico.y"
                {
        AuxToken *auxToken = createAuxToken((yyvsp[0].token).valor, (yyvsp[0].token).line, (yyvsp[0].token).column, NUM_OCTAL);
        Expression *aux = createExpression(NUMEROS, NUM_OCTAL, auxToken, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2703 "sintatico.tab.c"
    break;


#line 2707 "sintatico.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 922 "sintatico.y"


void yyerror(void *s) {}

void printLineError(int line, int column) {
    getLineBuffer(line);
    printf("\n%s\n", lineBuffer);
    for (int i = 0; i < column - 1; i++) printf(" ");
    printf("^");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        mipsPath = calloc(128, sizeof(char));
        strcpy(mipsPath, "/home/marcotuiio/Compilers/Gerador_de_Codigo/asms/default.asm");
    } else {
        mipsPath = calloc(strlen(argv[argc - 1]) + 1, sizeof(char));
        strcpy(mipsPath, argv[argc - 1]);
    }
    mipsFile = createAsmFile(mipsPath);
    printStart(mipsFile);
    readInputIntoAuxFile();
    yyparse();

    if (erroAux) {
        if (textBefore) printf("\n");
        int localColumn = yylval.token.column;
        if (yychar == 0 || yychar == MyEOF) {
            printf("error:syntax:%d:%d: expected declaration or statement at end of input", yylval.token.line, yylval.token.column);
        
        } else {
            if (strlen(wrongToken) > 0) {
                localColumn = wrongTokenColumn;
                printf("error:syntax:%d:%d: %s", wrongTokenLine, wrongTokenColumn, wrongToken);
            } else {
                printf("error:syntax:%d:%d: %s", yylval.token.line, yylval.token.column, yylval.token.valor);
            }
        }
        printLineError(yylval.token.line, localColumn);
    
    } else {
        traverseAST(AST);  // se tiver erro semantico vai dar exit e free la dentro
        if (textBefore) printf("\n");
        printf("SUCCESSFUL COMPILATION."); // se chegar aqui, compilou com sucesso e nao tem erros semanticos
        printEnd(mipsFile);
    }
    freeAST(AST);
    free(mipsPath);
    deleteAuxFile();
    return 0;
}
