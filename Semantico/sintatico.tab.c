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
extern void getLineBuffer();

extern char wrongToken[32];
extern int wrongTokenLine;
extern int wrongTokenColumn;

int erroAux = 0;
int semanticError = 0;
int CURRENT_TYPE;
int pointerQntd = 0;
int paramsQntd = 0;
int auxPosIncrement;

void *prototypeParam = NULL;


void **globalHash = NULL;
void **currentHash = NULL;

Program *AST = NULL;

void printLineError(int line, int column);


#line 110 "sintatico.tab.c"

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
  YYSYMBOL_AuxCondicional = 94,            /* AuxCondicional  */
  YYSYMBOL_ExpressaoOrLogico = 95,         /* ExpressaoOrLogico  */
  YYSYMBOL_ExpressaoAndLogico = 96,        /* ExpressaoAndLogico  */
  YYSYMBOL_ExpressaoOr = 97,               /* ExpressaoOr  */
  YYSYMBOL_ExpressaoXor = 98,              /* ExpressaoXor  */
  YYSYMBOL_ExpressaoAnd = 99,              /* ExpressaoAnd  */
  YYSYMBOL_ExpressaoIgual = 100,           /* ExpressaoIgual  */
  YYSYMBOL_ExpressaoRelacional = 101,      /* ExpressaoRelacional  */
  YYSYMBOL_ExpressaoShift = 102,           /* ExpressaoShift  */
  YYSYMBOL_ExpressaoAditiva = 103,         /* ExpressaoAditiva  */
  YYSYMBOL_ExpressaoMultiplicativa = 104,  /* ExpressaoMultiplicativa  */
  YYSYMBOL_ExpressaoCast = 105,            /* ExpressaoCast  */
  YYSYMBOL_ExpressaoUnaria = 106,          /* ExpressaoUnaria  */
  YYSYMBOL_ExpressaoPosFixa = 107,         /* ExpressaoPosFixa  */
  YYSYMBOL_AuxPosFixa = 108,               /* AuxPosFixa  */
  YYSYMBOL_PulaExpressaoAtribuicao = 109,  /* PulaExpressaoAtribuicao  */
  YYSYMBOL_AuxPula = 110,                  /* AuxPula  */
  YYSYMBOL_ExpressaoPrimaria = 111,        /* ExpressaoPrimaria  */
  YYSYMBOL_Numero = 112                    /* Numero  */
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
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

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
       0,   169,   169,   174,   175,   177,   177,   186,   190,   194,
     200,   202,   209,   210,   212,   229,   230,   232,   233,   235,
     239,   262,   268,   270,   274,   276,   277,   279,   292,   296,
     323,   325,   328,   330,   334,   338,   343,   345,   350,   354,
     356,   360,   364,   368,   372,   376,   380,   384,   388,   392,
     393,   395,   398,   400,   401,   403,   404,   406,   409,   414,
     415,   416,   418,   419,   420,   421,   423,   424,   425,   427,
     428,   429,   430,   431,   432,   434,   435,   440,   445,   449,
     451,   452,   457,   458,   463,   464,   469,   470,   475,   476,
     481,   482,   486,   491,   492,   497,   498,   502,   507,   508,
     512,   517,   518,   523,   524,   531,   532,   537,   542,   548,
     549,   556,   557,   558,   559,   561,   565,   567,   571,   573,
     577,   578,   582,   586,   590,   594,   598
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
  "ExpressaoCondicional", "AuxCondicional", "ExpressaoOrLogico",
  "ExpressaoAndLogico", "ExpressaoOr", "ExpressaoXor", "ExpressaoAnd",
  "ExpressaoIgual", "ExpressaoRelacional", "ExpressaoShift",
  "ExpressaoAditiva", "ExpressaoMultiplicativa", "ExpressaoCast",
  "ExpressaoUnaria", "ExpressaoPosFixa", "AuxPosFixa",
  "PulaExpressaoAtribuicao", "AuxPula", "ExpressaoPrimaria", "Numero", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,  -159,    23,    98,    74,  -159,  -159,  -159,    26,  -159,
    -159,  -159,    74,  -159,  -159,  -159,  -159,    19,     2,    74,
    -159,    19,    13,    78,   186,  -159,  -159,    33,  -159,   167,
    -159,  -159,  -159,  -159,  -159,  -159,   219,   219,  -159,  -159,
    -159,  -159,  -159,  -159,    64,   186,  -159,  -159,     3,    82,
      81,    62,    87,    68,    48,    57,    94,    -1,  -159,    65,
      -5,  -159,  -159,    60,   186,   101,     8,    19,    14,   186,
    -159,  -159,   186,  -159,  -159,   186,   186,  -159,   186,   186,
     186,   186,   186,   186,  -159,  -159,  -159,  -159,   186,   186,
     186,   186,   186,  -159,  -159,  -159,   186,  -159,  -159,  -159,
     186,   186,   186,  -159,  -159,  -159,   126,    19,    99,   186,
     128,    60,  -159,   137,  -159,  -159,    82,    -6,    81,    62,
      87,    68,    48,    48,    57,    94,    94,    -1,    -1,  -159,
    -159,   135,   139,   102,  -159,    91,   143,  -159,    19,  -159,
     115,    60,    19,   186,   186,   186,  -159,  -159,  -159,   143,
    -159,    96,  -159,   115,  -159,   150,   152,   154,   155,   156,
     157,   186,   166,  -159,   170,   115,   103,  -159,  -159,  -159,
     135,   172,   143,   171,   162,   186,   186,   186,   133,   134,
     178,    64,   186,  -159,  -159,   115,  -159,  -159,    60,  -159,
    -159,   184,    15,    24,   180,   185,   187,  -159,    28,  -159,
    -159,   186,   150,   150,   186,   186,   189,   163,   183,    63,
    -159,   179,   192,    64,   193,   151,  -159,   195,   150,  -159,
     186,  -159,   202,  -159,  -159,   203,   201,   150,  -159,  -159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     0,     1,     2,     3,     0,    33,
      34,    35,    10,     7,     8,    12,    13,    18,     0,    10,
       6,    18,     0,     0,     0,     9,    17,    22,    19,     0,
      71,    72,    70,    69,    74,    73,     0,     0,   124,   125,
     126,   122,   121,   119,    11,     0,    57,    75,    79,    80,
      82,    84,    86,    88,    90,    93,    95,    98,   101,   103,
     105,   109,   120,    30,     0,    24,     0,    18,     0,     0,
     106,   107,     0,   108,   103,     0,     0,    77,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,     0,     0,
       0,     0,     0,    66,    67,    68,     0,    60,    61,    59,
       0,   116,     0,   113,   114,   110,     0,    18,     0,     0,
      26,    16,    27,     0,   123,    58,    81,     0,    83,    85,
      87,    89,    91,    92,    94,    96,    97,    99,   100,   102,
      76,   118,     0,     0,    28,     0,    22,    23,    18,    20,
       0,    16,    18,     0,     0,     0,   115,   112,   111,    22,
      21,     0,    25,     0,    49,     0,     0,     0,     0,     0,
       0,    54,     0,    50,     0,    39,     0,    15,   104,    78,
     118,    32,    22,     0,     0,     0,     0,    54,     0,     0,
       0,    53,     0,    14,    37,    39,    48,   117,    30,    29,
      36,     0,     0,     0,     0,    56,     0,    47,     0,    38,
      31,     0,     0,     0,    54,     0,     0,     0,     0,     0,
      41,    52,     0,    55,     0,     0,    46,     0,     0,    42,
      54,    44,     0,    40,    51,     0,     0,     0,    45,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,  -159,   212,   198,  -159,  -159,    77,    -7,
    -108,    93,  -123,  -159,  -159,  -159,  -159,    41,  -159,   -28,
    -134,    79,    52,  -156,  -159,  -158,  -159,   -24,  -159,  -159,
    -159,  -159,   -70,   104,  -159,  -159,   174,   168,   173,   175,
     169,    38,   159,    36,    42,   -37,   -25,  -159,  -159,  -159,
      83,  -159,  -159
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    19,    20,    13,    14,   140,   151,
      15,    23,    65,   110,   139,    16,    66,   106,   189,    17,
     163,   164,   184,   165,   219,   180,   206,   166,   100,    88,
      96,    45,    46,    47,    77,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,   105,   132,
     146,    61,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    67,   115,   141,   101,    68,   102,    72,    73,   185,
      22,    70,    71,   150,    26,   111,    93,    94,    95,   194,
      74,   174,   112,     5,   114,   202,   171,    72,    72,   185,
     130,   131,    18,   141,   203,   107,    21,    72,   208,   137,
     108,    72,    63,   144,    64,    68,   212,   103,   104,    75,
      74,    76,   117,    74,    74,    74,    74,    74,    74,   129,
     113,    24,   225,    74,    74,    74,    74,    74,   210,   211,
       1,    74,    27,   217,    -5,   170,    72,    72,   133,     8,
       9,    10,    11,   142,   224,    84,    85,    86,    87,    -5,
      -5,    -5,    28,   229,     9,    10,    11,    97,    98,    99,
     135,     6,     7,    82,    83,    80,   168,    89,    90,    91,
      92,   136,    72,   142,   148,    72,    72,   186,    74,    74,
     122,   123,   153,    79,    29,   125,   126,    78,    81,   154,
      30,    31,    32,   127,   128,   109,   134,   181,   155,   156,
     157,   138,   158,   159,   160,   161,   162,   143,   145,   147,
     149,   192,   193,   181,    64,   172,    33,   153,   198,    34,
     107,   175,    35,   176,   177,   178,   179,    36,    37,    38,
      39,    40,    41,    42,    43,   182,    29,   209,   183,   190,
     181,   213,    30,    31,    32,   188,   191,     9,    10,    11,
     195,   196,   197,   201,   204,    29,   181,   216,   205,   214,
     207,    30,    31,    32,   215,   218,   220,   221,    33,   223,
     222,    34,   226,   227,    35,   228,    12,    25,   167,    36,
      37,    38,    39,    40,    41,    42,    43,    33,    69,   200,
      34,   152,   173,    35,    30,    31,    32,   199,    36,    37,
      38,    39,    40,    41,    42,    43,   118,   124,   169,   116,
     121,     0,   119,   187,     0,   120,     0,     0,     0,     0,
      33,     0,     0,    34,     0,     0,    35,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
      24,    29,    72,   111,     9,    29,    11,    13,    45,   165,
      17,    36,    37,   136,    21,     7,    17,    18,    19,   177,
      45,   155,    14,     0,    10,    10,   149,    13,    13,   185,
     100,   101,     6,   141,    10,    63,    17,    13,    10,   109,
      64,    13,     9,    49,    11,    69,   204,    52,    53,    46,
      75,    48,    76,    78,    79,    80,    81,    82,    83,    96,
      67,    59,   220,    88,    89,    90,    91,    92,   202,   203,
       1,    96,    59,    10,     5,   145,    13,    13,   102,     5,
      20,    21,    22,   111,   218,    37,    38,    39,    40,    20,
      21,    22,    14,   227,    20,    21,    22,    32,    33,    34,
     107,     3,     4,    35,    36,    43,   143,    50,    51,    15,
      16,    12,    13,   141,    12,    13,    13,    14,   143,   144,
      82,    83,     7,    42,     9,    89,    90,    45,    41,    14,
      15,    16,    17,    91,    92,    34,    10,   161,    23,    24,
      25,    13,    27,    28,    29,    30,    31,    10,    13,    10,
      59,   175,   176,   177,    11,    59,    41,     7,   182,    44,
     188,     9,    47,     9,     9,     9,     9,    52,    53,    54,
      55,    56,    57,    58,    59,     9,     9,   201,     8,     8,
     204,   205,    15,    16,    17,    13,    24,    20,    21,    22,
      57,    57,    14,     9,    14,     9,   220,    14,    13,    10,
      13,    15,    16,    17,    41,    26,    14,    14,    41,    14,
      59,    44,    10,    10,    47,    14,     4,    19,   141,    52,
      53,    54,    55,    56,    57,    58,    59,    41,     9,   188,
      44,   138,   153,    47,    15,    16,    17,   185,    52,    53,
      54,    55,    56,    57,    58,    59,    78,    88,   144,    75,
      81,    -1,    79,   170,    -1,    80,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    61,    62,    63,     0,     3,     4,     5,    20,
      21,    22,    64,    66,    67,    70,    75,    79,     6,    64,
      65,    17,    69,    71,    59,    65,    69,    59,    14,     9,
      15,    16,    17,    41,    44,    47,    52,    53,    54,    55,
      56,    57,    58,    59,    87,    91,    92,    93,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   111,   112,     9,    11,    72,    76,    79,    87,     9,
     106,   106,    13,   105,   106,    46,    48,    94,    45,    42,
      43,    41,    35,    36,    37,    38,    39,    40,    89,    50,
      51,    15,    16,    17,    18,    19,    90,    32,    33,    34,
      88,     9,    11,    52,    53,   108,    77,    79,    87,    34,
      73,     7,    14,    69,    10,    92,    96,    87,    97,    98,
      99,   100,   101,   101,   102,   103,   103,   104,   104,   105,
      92,    92,   109,    87,    10,    69,    12,    92,    13,    74,
      68,    70,    79,    10,    49,    13,   110,    10,    12,    59,
      72,    69,    71,     7,    14,    23,    24,    25,    27,    28,
      29,    30,    31,    80,    81,    83,    87,    68,   105,    93,
      92,    72,    59,    81,    80,     9,     9,     9,     9,     9,
      85,    87,     9,     8,    82,    83,    14,   110,    13,    78,
       8,    24,    87,    87,    85,    57,    57,    14,    87,    82,
      77,     9,    10,    10,    14,    13,    86,    13,    10,    87,
      80,    80,    85,    87,    10,    41,    14,    10,    26,    84,
      14,    14,    59,    14,    80,    85,    10,    10,    14,    80
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
      91,    91,    91,    91,    91,    92,    92,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   101,   101,   102,   102,   102,   103,   103,
     103,   104,   104,   105,   105,   106,   106,   106,   106,   107,
     107,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   112,   112,   112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     3,     1,     1,     2,
       0,     4,     1,     1,     8,     2,     0,     2,     0,     3,
       5,     4,     0,     2,     0,     2,     0,     5,     3,     5,
       0,     2,     0,     1,     1,     1,     3,     2,     2,     0,
       7,     5,     6,     9,     6,     8,     5,     3,     2,     1,
       1,     2,     0,     1,     0,     2,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     4,     0,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     5,     1,     2,     2,     2,     1,
       2,     3,     3,     1,     1,     2,     0,     3,     0,     1,
       1,     1,     1,     3,     1,     1,     1
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
#line 169 "sintatico.y"
                      { 
        AST = (yyvsp[-1].prog);
        erroAux = 0; 
        return 0; 
    }
#line 1393 "sintatico.tab.c"
    break;

  case 3: /* Start: Programa ERRO  */
#line 174 "sintatico.y"
                    { erroAux = 1; return 0; }
#line 1399 "sintatico.tab.c"
    break;

  case 4: /* Start: error  */
#line 175 "sintatico.y"
            { erroAux = 1; return 0; }
#line 1405 "sintatico.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 177 "sintatico.y"
          { 
        void **hash = createHash();
        globalHash = hash;
    }
#line 1414 "sintatico.tab.c"
    break;

  case 6: /* Programa: $@1 DeclaracaoOUFuncao ListaFuncoes  */
#line 181 "sintatico.y"
                                    {
        Program *aux = createProgram(globalHash, (yyvsp[-1].func), NULL); // $2 should be a list of functions, therefore Function *
        (yyval.prog) = aux; 
    }
#line 1423 "sintatico.tab.c"
    break;

  case 7: /* DeclaracaoOUFuncao: Declaracoes  */
#line 186 "sintatico.y"
                                { /* inserir na hash global o que quer que apareça aqui */
        // currentHash = globalHash;
        (yyval.func) = NULL;
    }
#line 1432 "sintatico.tab.c"
    break;

  case 8: /* DeclaracaoOUFuncao: Funcao  */
#line 190 "sintatico.y"
             { 
        (yyval.func) = (yyvsp[0].func);  // should return a list of functions
    }
#line 1440 "sintatico.tab.c"
    break;

  case 9: /* ListaFuncoes: DeclaracaoOUFuncao ListaFuncoes  */
#line 194 "sintatico.y"
                                              { 
        if (((Function *) (yyvsp[-1].func)) != NULL) {  // se for uma funcao e nao uma declaracao
            (yyvsp[-1].func)->next = (yyvsp[0].func);  // devia linkar as funcoes, sera se ta certo?
            (yyval.func) = (yyvsp[-1].func);  // devia retornar aa lista de funcoes
        }
    }
#line 1451 "sintatico.tab.c"
    break;

  case 10: /* ListaFuncoes: %empty  */
#line 200 "sintatico.y"
      { (yyval.func) = NULL; }
#line 1457 "sintatico.tab.c"
    break;

  case 11: /* Declaracoes: NUMBER_SIGN DEFINE ID Expressao  */
#line 202 "sintatico.y"
                                             { /* Adicionar isso na hash */
        if (lookForValueInHash(globalHash, (yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, DEFINE, &textBefore, &semanticError) != -1) {
            void *node = insertHash(globalHash, (yyvsp[-1].token).valor, (yyvsp[-1].token).line, (yyvsp[-1].token).column, DEFINE, 0);
            // evalExpression(node, $4);
            setAssign(node, (yyvsp[0].expr));
        }
    }
#line 1469 "sintatico.tab.c"
    break;

  case 12: /* Declaracoes: DeclaraVariaveis  */
#line 209 "sintatico.y"
                       { /* Adicionar isso na hash */ }
#line 1475 "sintatico.tab.c"
    break;

  case 13: /* Declaracoes: DeclaraPrototipos  */
#line 210 "sintatico.y"
                        { /* Adicionar isso na hash */ }
#line 1481 "sintatico.tab.c"
    break;

  case 14: /* Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET  */
#line 212 "sintatico.y"
                                                                                                    {
        // vendo se a funcao ja foi declarada

        if (!lookForPrototypeInHash(globalHash, (yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, (yyvsp[-7].token).type, (yyvsp[-4].param), paramsQntd, &textBefore, &semanticError)) {
            if (!lookForValueInHash(globalHash, (yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, (yyvsp[-7].token).type, &textBefore, &semanticError)) {
                void *node = insertHash(globalHash, (yyvsp[-5].token).valor, (yyvsp[-5].token).line, (yyvsp[-5].token).column, (yyvsp[-7].token).type, pointerQntd);
                setQntdParams(node, paramsQntd);
                setParam(node, (yyvsp[-4].param));
            } 
        }
        Function *func = createFunction(currentHash, (yyvsp[-7].token).type, pointerQntd, (yyvsp[-5].token).valor, (yyvsp[-1].cmd), NULL);
        pointerQntd = 0;
        paramsQntd = 0;
        currentHash = NULL;
        (yyval.func) = func;
    }
#line 1502 "sintatico.tab.c"
    break;

  case 15: /* DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao  */
#line 229 "sintatico.y"
                                                                { /* descendo para colocar na hash da funcao */ }
#line 1508 "sintatico.tab.c"
    break;

  case 16: /* DeclaraVariaveisFuncao: %empty  */
#line 230 "sintatico.y"
      { }
#line 1514 "sintatico.tab.c"
    break;

  case 17: /* Ponteiro: MULTIPLY Ponteiro  */
#line 232 "sintatico.y"
                            { pointerQntd++; }
#line 1520 "sintatico.tab.c"
    break;

  case 18: /* Ponteiro: %empty  */
#line 233 "sintatico.y"
      { }
#line 1526 "sintatico.tab.c"
    break;

  case 19: /* DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON  */
#line 235 "sintatico.y"
                                                { 
        CURRENT_TYPE = (yyvsp[-2].token).type;
    }
#line 1534 "sintatico.tab.c"
    break;

  case 20: /* BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel  */
#line 239 "sintatico.y"
                                                                              {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }
        if (CURRENT_TYPE == 277 && pointerQntd == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: variable '%s' declared void", (yyvsp[-3].token).line, (yyvsp[-3].token).column, (yyvsp[-3].token).valor);
            printLineError((yyvsp[-3].token).line, (yyvsp[-3].token).column);
            if (currentHash) freeHash(currentHash);
            traverseAST(AST);
            exit(1);
        }
        // considerar o ponteiro, dimensoes e atribuicao se existirem
        if (!lookForValueInHash(currentHash, (yyvsp[-3].token).valor, (yyvsp[-3].token).line, (yyvsp[-3].token).column, CURRENT_TYPE, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, (yyvsp[-3].token).valor, (yyvsp[-3].token).line, (yyvsp[-3].token).column, CURRENT_TYPE, pointerQntd);
            setDimensions(node, (yyvsp[-2].dim));
            // evalExpression(node, $4);
            setAssign(node, (yyvsp[-1].expr));
        }
        pointerQntd = 0;
    }
#line 1561 "sintatico.tab.c"
    break;

  case 21: /* ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete  */
#line 262 "sintatico.y"
                                                                                 {
        // nova struct para dimensoes?
        Dimension *aux = createDimension((yyvsp[-2].expr));
        aux->next = (yyvsp[0].dim);
        (yyval.dim) = aux;
    }
#line 1572 "sintatico.tab.c"
    break;

  case 22: /* ExpressaoColchete: %empty  */
#line 268 "sintatico.y"
      { (yyval.dim) = NULL; }
#line 1578 "sintatico.tab.c"
    break;

  case 23: /* ExpressaoAssign: ASSIGN ExpressaoAtribuicao  */
#line 270 "sintatico.y"
                                            { 
        (yyvsp[0].expr)->assign = ASSIGN;
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1587 "sintatico.tab.c"
    break;

  case 24: /* ExpressaoAssign: %empty  */
#line 274 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1593 "sintatico.tab.c"
    break;

  case 25: /* RetornoVariavel: COMMA BlocoVariaveis  */
#line 276 "sintatico.y"
                                      { /* colocar na hash */ }
#line 1599 "sintatico.tab.c"
    break;

  case 26: /* RetornoVariavel: %empty  */
#line 277 "sintatico.y"
      { }
#line 1605 "sintatico.tab.c"
    break;

  case 27: /* DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON  */
#line 279 "sintatico.y"
                                                         { 
        // colocar na hash global e ver se bate com as funcoes ?
        void *node = insertHash(globalHash, (yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-4].token).type, pointerQntd);
        setPrototype(node);
        setQntdParams(node, paramsQntd);
        setParam(node, (yyvsp[-1].param));
        prototypeParam = NULL;
        pointerQntd = 0;
        paramsQntd = 0;
        free(currentHash);
        currentHash = NULL;
    }
#line 1622 "sintatico.tab.c"
    break;

  case 28: /* Parametros: L_PAREN BlocoParametros R_PAREN  */
#line 292 "sintatico.y"
                                            { 
        (yyval.param) = prototypeParam;
    }
#line 1630 "sintatico.tab.c"
    break;

  case 29: /* BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros  */
#line 296 "sintatico.y"
                                                                      {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }

        if ((yyvsp[-4].token).type == 277 && pointerQntd == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: variable '%s' declared void", (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-2].token).valor);
            printLineError((yyvsp[-2].token).line, (yyvsp[-2].token).column);
            if (currentHash) freeHash(currentHash);
            traverseAST(AST);
            exit(1);
        }
        paramsQntd++;
        Param *aux = createParam((yyvsp[-4].token).type, (yyvsp[-2].token).valor, pointerQntd, (yyvsp[-2].token).line, (yyvsp[-2].token).column+1, (yyvsp[0].param));
        if (!prototypeParam) prototypeParam = aux;

        if (!lookForValueInHash(currentHash, (yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-4].token).type, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, (yyvsp[-2].token).valor, (yyvsp[-2].token).line, (yyvsp[-2].token).column, (yyvsp[-4].token).type, pointerQntd);
            setQntdParams(node, paramsQntd);
            setDimensions(node, (yyvsp[-1].dim));
        }

        pointerQntd = 0;
        (yyval.param) = aux;
    }
#line 1662 "sintatico.tab.c"
    break;

  case 30: /* BlocoParametros: %empty  */
#line 323 "sintatico.y"
      { (yyval.param) = NULL; }
#line 1668 "sintatico.tab.c"
    break;

  case 31: /* RetornaParametros: COMMA BlocoParametros  */
#line 325 "sintatico.y"
                                         { 
        (yyval.param) = (yyvsp[0].param);
    }
#line 1676 "sintatico.tab.c"
    break;

  case 32: /* RetornaParametros: %empty  */
#line 328 "sintatico.y"
      { (yyval.param) = NULL; }
#line 1682 "sintatico.tab.c"
    break;

  case 33: /* Tipo: INT  */
#line 330 "sintatico.y"
          { 
        CURRENT_TYPE = INT; 
        (yyval.token) = yylval.token; 
    }
#line 1691 "sintatico.tab.c"
    break;

  case 34: /* Tipo: CHAR  */
#line 334 "sintatico.y"
           { 
        CURRENT_TYPE = CHAR;
        (yyval.token) = yylval.token;
    }
#line 1700 "sintatico.tab.c"
    break;

  case 35: /* Tipo: VOID  */
#line 338 "sintatico.y"
           { 
        CURRENT_TYPE = VOID;
        (yyval.token) = yylval.token;
    }
#line 1709 "sintatico.tab.c"
    break;

  case 36: /* Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET  */
#line 343 "sintatico.y"
                                                { (yyval.cmd) = (yyvsp[-1].cmd); }
#line 1715 "sintatico.tab.c"
    break;

  case 37: /* Comandos: ListaComandos RetornoComandos  */
#line 345 "sintatico.y"
                                        {
        (yyvsp[-1].cmd)->next = (yyvsp[0].cmd);
        (yyval.cmd) = (yyvsp[-1].cmd);
    }
#line 1724 "sintatico.tab.c"
    break;

  case 38: /* RetornoComandos: ListaComandos RetornoComandos  */
#line 350 "sintatico.y"
                                               { 
        (yyvsp[-1].cmd)->next = (yyvsp[0].cmd);
        (yyval.cmd) = (yyvsp[-1].cmd);
    }
#line 1733 "sintatico.tab.c"
    break;

  case 39: /* RetornoComandos: %empty  */
#line 354 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 1739 "sintatico.tab.c"
    break;

  case 40: /* ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON  */
#line 356 "sintatico.y"
                                                                  {
        Command *aux = createDoWhileStatement((yyvsp[-2].expr), (yyvsp[-5].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1748 "sintatico.tab.c"
    break;

  case 41: /* ListaComandos: WHILE L_PAREN Expressao R_PAREN Bloco  */
#line 360 "sintatico.y"
                                            {
        Command *aux = createWhileStatement((yyvsp[-2].expr), (yyvsp[0].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1757 "sintatico.tab.c"
    break;

  case 42: /* ListaComandos: IF L_PAREN Expressao R_PAREN Bloco AuxElse  */
#line 364 "sintatico.y"
                                                 {
        Command *aux = createIfStatement((yyvsp[-3].expr), (yyvsp[-1].cmd), (yyvsp[0].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1766 "sintatico.tab.c"
    break;

  case 43: /* ListaComandos: FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco  */
#line 368 "sintatico.y"
                                                                         {
        Command *aux = createForStatement((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1775 "sintatico.tab.c"
    break;

  case 44: /* ListaComandos: PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON  */
#line 372 "sintatico.y"
                                                       {
        Command *aux = createPrintStatement(yylval.token.valor, (yyvsp[-2].expr), NULL);
        (yyval.cmd) = aux;
    }
#line 1784 "sintatico.tab.c"
    break;

  case 45: /* ListaComandos: SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON  */
#line 376 "sintatico.y"
                                                                  {
        Command *aux = createScanStatement(yylval.token.valor, yylval.token.valor, NULL);
        (yyval.cmd) = aux;
    }
#line 1793 "sintatico.tab.c"
    break;

  case 46: /* ListaComandos: EXIT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 380 "sintatico.y"
                                               {
        Command *aux = createExitStatement((yyvsp[-2].expr), NULL);
        (yyval.cmd) = aux; 
    }
#line 1802 "sintatico.tab.c"
    break;

  case 47: /* ListaComandos: RETURN AuxFor SEMICOLON  */
#line 384 "sintatico.y"
                              {
        Command *aux = createReturnStatement((yyvsp[-1].expr), NULL);
        (yyval.cmd) = aux;
    }
#line 1811 "sintatico.tab.c"
    break;

  case 48: /* ListaComandos: Expressao SEMICOLON  */
#line 388 "sintatico.y"
                          {
        Command *aux = createCommandExpression((yyvsp[-1].expr), NULL);
        (yyval.cmd) = aux;
    }
#line 1820 "sintatico.tab.c"
    break;

  case 49: /* ListaComandos: SEMICOLON  */
#line 392 "sintatico.y"
                { }
#line 1826 "sintatico.tab.c"
    break;

  case 50: /* ListaComandos: Bloco  */
#line 393 "sintatico.y"
            { (yyval.cmd) = (yyvsp[0].cmd); }
#line 1832 "sintatico.tab.c"
    break;

  case 51: /* AuxElse: ELSE Bloco  */
#line 395 "sintatico.y"
                    {
        (yyval.cmd) = (yyvsp[0].cmd);
    }
#line 1840 "sintatico.tab.c"
    break;

  case 52: /* AuxElse: %empty  */
#line 398 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 1846 "sintatico.tab.c"
    break;

  case 53: /* AuxFor: Expressao  */
#line 400 "sintatico.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 1852 "sintatico.tab.c"
    break;

  case 54: /* AuxFor: %empty  */
#line 401 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1858 "sintatico.tab.c"
    break;

  case 55: /* AuxPrint: COMMA Expressao  */
#line 403 "sintatico.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1864 "sintatico.tab.c"
    break;

  case 56: /* AuxPrint: %empty  */
#line 404 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1870 "sintatico.tab.c"
    break;

  case 57: /* Expressao: ExpressaoAtribuicao  */
#line 406 "sintatico.y"
                               {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1878 "sintatico.tab.c"
    break;

  case 58: /* Expressao: Expressao COMMA ExpressaoAtribuicao  */
#line 409 "sintatico.y"
                                          { 
        Expression *aux = createExpression(NAOSEI, COMMA, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1887 "sintatico.tab.c"
    break;

  case 59: /* OpAtrib: ASSIGN  */
#line 414 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 1893 "sintatico.tab.c"
    break;

  case 60: /* OpAtrib: ADD_ASSIGN  */
#line 415 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1899 "sintatico.tab.c"
    break;

  case 61: /* OpAtrib: MINUS_ASSIGN  */
#line 416 "sintatico.y"
                   { (yyval.token) = yylval.token; }
#line 1905 "sintatico.tab.c"
    break;

  case 62: /* OpRel: LESS_THAN  */
#line 418 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1911 "sintatico.tab.c"
    break;

  case 63: /* OpRel: LESS_EQUAL  */
#line 419 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1917 "sintatico.tab.c"
    break;

  case 64: /* OpRel: GREATER_THAN  */
#line 420 "sintatico.y"
                   { (yyval.token) = yylval.token; }
#line 1923 "sintatico.tab.c"
    break;

  case 65: /* OpRel: GREATER_EQUAL  */
#line 421 "sintatico.y"
                    { (yyval.token) = yylval.token; }
#line 1929 "sintatico.tab.c"
    break;

  case 66: /* OpMult: MULTIPLY  */
#line 423 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1935 "sintatico.tab.c"
    break;

  case 67: /* OpMult: DIVIDE  */
#line 424 "sintatico.y"
             { (yyval.token) = yylval.token; }
#line 1941 "sintatico.tab.c"
    break;

  case 68: /* OpMult: REMAINDER  */
#line 425 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 1947 "sintatico.tab.c"
    break;

  case 69: /* OpUnario: BITWISE_AND  */
#line 427 "sintatico.y"
                      { (yyval.token) = yylval.token; }
#line 1953 "sintatico.tab.c"
    break;

  case 70: /* OpUnario: MULTIPLY  */
#line 428 "sintatico.y"
               { (yyval.token) = yylval.token; }
#line 1959 "sintatico.tab.c"
    break;

  case 71: /* OpUnario: PLUS  */
#line 429 "sintatico.y"
           { (yyval.token) = yylval.token; }
#line 1965 "sintatico.tab.c"
    break;

  case 72: /* OpUnario: MINUS  */
#line 430 "sintatico.y"
            { (yyval.token) = yylval.token; }
#line 1971 "sintatico.tab.c"
    break;

  case 73: /* OpUnario: NOT  */
#line 431 "sintatico.y"
          { (yyval.token) = yylval.token; }
#line 1977 "sintatico.tab.c"
    break;

  case 74: /* OpUnario: BITWISE_NOT  */
#line 432 "sintatico.y"
                  { (yyval.token) = yylval.token; }
#line 1983 "sintatico.tab.c"
    break;

  case 75: /* ExpressaoAtribuicao: ExpressaoCondicional  */
#line 434 "sintatico.y"
                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1989 "sintatico.tab.c"
    break;

  case 76: /* ExpressaoAtribuicao: ExpressaoUnaria OpAtrib ExpressaoAtribuicao  */
#line 435 "sintatico.y"
                                                  {
        Expression *aux = createExpression(ATRIBUICAO, (yyvsp[-1].token).type, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1998 "sintatico.tab.c"
    break;

  case 77: /* ExpressaoCondicional: ExpressaoOrLogico AuxCondicional  */
#line 440 "sintatico.y"
                                                       {
        (yyvsp[-1].expr)->ternary = (yyvsp[0].expr);
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2007 "sintatico.tab.c"
    break;

  case 78: /* AuxCondicional: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional  */
#line 445 "sintatico.y"
                                                                         {
        Expression *aux = createExpression(TERNARY, TERNARY_CONDITIONAL, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2016 "sintatico.tab.c"
    break;

  case 79: /* AuxCondicional: %empty  */
#line 449 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2022 "sintatico.tab.c"
    break;

  case 80: /* ExpressaoOrLogico: ExpressaoAndLogico  */
#line 451 "sintatico.y"
                                      { (yyval.expr) = (yyvsp[0].expr); }
#line 2028 "sintatico.tab.c"
    break;

  case 81: /* ExpressaoOrLogico: ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico  */
#line 452 "sintatico.y"
                                                      { 
        Expression *aux = createExpression(OR_LOGICO, LOGICAL_OR, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2037 "sintatico.tab.c"
    break;

  case 82: /* ExpressaoAndLogico: ExpressaoOr  */
#line 457 "sintatico.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2043 "sintatico.tab.c"
    break;

  case 83: /* ExpressaoAndLogico: ExpressaoAndLogico LOGICAL_AND ExpressaoOr  */
#line 458 "sintatico.y"
                                                 {
        Expression *aux = createExpression(AND_LOGICO, LOGICAL_AND, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2052 "sintatico.tab.c"
    break;

  case 84: /* ExpressaoOr: ExpressaoXor  */
#line 463 "sintatico.y"
                          { (yyval.expr) = (yyvsp[0].expr);}
#line 2058 "sintatico.tab.c"
    break;

  case 85: /* ExpressaoOr: ExpressaoOr BITWISE_OR ExpressaoXor  */
#line 464 "sintatico.y"
                                          {
        Expression *aux = createExpression(OR_BIT, BITWISE_OR, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2067 "sintatico.tab.c"
    break;

  case 86: /* ExpressaoXor: ExpressaoAnd  */
#line 469 "sintatico.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 2073 "sintatico.tab.c"
    break;

  case 87: /* ExpressaoXor: ExpressaoXor BITWISE_XOR ExpressaoAnd  */
#line 470 "sintatico.y"
                                            {
        Expression *aux = createExpression(XOR_BIT, BITWISE_XOR, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2082 "sintatico.tab.c"
    break;

  case 88: /* ExpressaoAnd: ExpressaoIgual  */
#line 475 "sintatico.y"
                             { (yyval.expr) = (yyvsp[0].expr); }
#line 2088 "sintatico.tab.c"
    break;

  case 89: /* ExpressaoAnd: ExpressaoAnd BITWISE_AND ExpressaoIgual  */
#line 476 "sintatico.y"
                                              {
        Expression *aux = createExpression(AND_BIT, BITWISE_AND, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2097 "sintatico.tab.c"
    break;

  case 90: /* ExpressaoIgual: ExpressaoRelacional  */
#line 481 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2103 "sintatico.tab.c"
    break;

  case 91: /* ExpressaoIgual: ExpressaoIgual EQUAL ExpressaoRelacional  */
#line 482 "sintatico.y"
                                               {
        Expression *aux = createExpression(IGUALDADE, EQUAL, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2112 "sintatico.tab.c"
    break;

  case 92: /* ExpressaoIgual: ExpressaoIgual NOT_EQUAL ExpressaoRelacional  */
#line 486 "sintatico.y"
                                                   { 
        Expression *aux = createExpression(IGUALDADE, NOT_EQUAL, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2121 "sintatico.tab.c"
    break;

  case 93: /* ExpressaoRelacional: ExpressaoShift  */
#line 491 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2127 "sintatico.tab.c"
    break;

  case 94: /* ExpressaoRelacional: ExpressaoRelacional OpRel ExpressaoShift  */
#line 492 "sintatico.y"
                                               { 
        Expression *aux = createExpression(RELACIONAL, (yyvsp[-1].token).type, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2136 "sintatico.tab.c"
    break;

  case 95: /* ExpressaoShift: ExpressaoAditiva  */
#line 497 "sintatico.y"
                                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2142 "sintatico.tab.c"
    break;

  case 96: /* ExpressaoShift: ExpressaoShift R_SHIFT ExpressaoAditiva  */
#line 498 "sintatico.y"
                                              {
        Expression *aux = createExpression(SHIFT, R_SHIFT, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2151 "sintatico.tab.c"
    break;

  case 97: /* ExpressaoShift: ExpressaoShift L_SHIFT ExpressaoAditiva  */
#line 502 "sintatico.y"
                                              {
        Expression *aux = createExpression(SHIFT, L_SHIFT, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2160 "sintatico.tab.c"
    break;

  case 98: /* ExpressaoAditiva: ExpressaoMultiplicativa  */
#line 507 "sintatico.y"
                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2166 "sintatico.tab.c"
    break;

  case 99: /* ExpressaoAditiva: ExpressaoAditiva PLUS ExpressaoMultiplicativa  */
#line 508 "sintatico.y"
                                                    { 
        Expression *aux = createExpression(ADITIVIVA, PLUS, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2175 "sintatico.tab.c"
    break;

  case 100: /* ExpressaoAditiva: ExpressaoAditiva MINUS ExpressaoMultiplicativa  */
#line 512 "sintatico.y"
                                                     { 
        Expression *aux = createExpression(ADITIVIVA, MINUS, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2184 "sintatico.tab.c"
    break;

  case 101: /* ExpressaoMultiplicativa: ExpressaoCast  */
#line 517 "sintatico.y"
                                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2190 "sintatico.tab.c"
    break;

  case 102: /* ExpressaoMultiplicativa: ExpressaoMultiplicativa OpMult ExpressaoCast  */
#line 518 "sintatico.y"
                                                   {
        Expression *aux = createExpression(MULTIPLICATIVA, (yyvsp[-1].token).type, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2199 "sintatico.tab.c"
    break;

  case 103: /* ExpressaoCast: ExpressaoUnaria  */
#line 523 "sintatico.y"
                               { (yyval.expr) = (yyvsp[0].expr); }
#line 2205 "sintatico.tab.c"
    break;

  case 104: /* ExpressaoCast: L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast  */
#line 524 "sintatico.y"
                                                  {
        // tem qua tratar o ponteiro e fazer alguma coisa com essa expressao
        Expression *aux = createExpression(CASTING, (yyvsp[-3].token).type, NULL, NULL, (yyvsp[0].expr));
        aux->pointer = pointerQntd;
        pointerQntd = 0;
    }
#line 2216 "sintatico.tab.c"
    break;

  case 105: /* ExpressaoUnaria: ExpressaoPosFixa  */
#line 531 "sintatico.y"
                                  { (yyval.expr) = (yyvsp[0].expr); }
#line 2222 "sintatico.tab.c"
    break;

  case 106: /* ExpressaoUnaria: INC ExpressaoUnaria  */
#line 532 "sintatico.y"
                          {
        Expression *aux = createExpression(UNARIA, INC, NULL, (yyvsp[0].expr), NULL);
        (yyvsp[0].expr)->preIncrement = INC; 
        (yyval.expr) = aux;
    }
#line 2232 "sintatico.tab.c"
    break;

  case 107: /* ExpressaoUnaria: DEC ExpressaoUnaria  */
#line 537 "sintatico.y"
                          {
        Expression *aux = createExpression(UNARIA, DEC, NULL, (yyvsp[0].expr), NULL);
        (yyvsp[0].expr)->preIncrement = DEC; 
        (yyval.expr) = aux;
    }
#line 2242 "sintatico.tab.c"
    break;

  case 108: /* ExpressaoUnaria: OpUnario ExpressaoCast  */
#line 542 "sintatico.y"
                             {
        // Expression *aux = createExpression(UNARIA, $1.type, NULL, $2, NULL);
        (yyvsp[0].expr)->unario = (yyvsp[-1].token).type; 
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2252 "sintatico.tab.c"
    break;

  case 109: /* ExpressaoPosFixa: ExpressaoPrimaria  */
#line 548 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2258 "sintatico.tab.c"
    break;

  case 110: /* ExpressaoPosFixa: ExpressaoPosFixa AuxPosFixa  */
#line 549 "sintatico.y"
                                  {
        (yyvsp[-1].expr)->next = (yyvsp[0].expr);
        (yyvsp[-1].expr)->posIncrement = auxPosIncrement;
        auxPosIncrement = 0;
        (yyval.expr) = (yyvsp[-1].expr); 
    }
#line 2269 "sintatico.tab.c"
    break;

  case 111: /* AuxPosFixa: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET  */
#line 556 "sintatico.y"
                                                        { (yyval.expr) = (yyvsp[-1].expr); }
#line 2275 "sintatico.tab.c"
    break;

  case 112: /* AuxPosFixa: L_PAREN PulaExpressaoAtribuicao R_PAREN  */
#line 557 "sintatico.y"
                                              { (yyval.expr) = (yyvsp[-1].expr); }
#line 2281 "sintatico.tab.c"
    break;

  case 113: /* AuxPosFixa: INC  */
#line 558 "sintatico.y"
          { auxPosIncrement = INC; }
#line 2287 "sintatico.tab.c"
    break;

  case 114: /* AuxPosFixa: DEC  */
#line 559 "sintatico.y"
          { auxPosIncrement = DEC; }
#line 2293 "sintatico.tab.c"
    break;

  case 115: /* PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula  */
#line 561 "sintatico.y"
                                                     { 
        (yyvsp[-1].expr)->next = (yyvsp[0].expr); 
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2302 "sintatico.tab.c"
    break;

  case 116: /* PulaExpressaoAtribuicao: %empty  */
#line 565 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2308 "sintatico.tab.c"
    break;

  case 117: /* AuxPula: COMMA ExpressaoAtribuicao AuxPula  */
#line 567 "sintatico.y"
                                           {
        (yyvsp[-1].expr)->next = (yyvsp[0].expr);
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2317 "sintatico.tab.c"
    break;

  case 118: /* AuxPula: %empty  */
#line 571 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2323 "sintatico.tab.c"
    break;

  case 119: /* ExpressaoPrimaria: ID  */
#line 573 "sintatico.y"
                      { 
        Expression *aux = createExpression(PRIMARIA, ID, (yyvsp[0].token).valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2332 "sintatico.tab.c"
    break;

  case 120: /* ExpressaoPrimaria: Numero  */
#line 577 "sintatico.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 2338 "sintatico.tab.c"
    break;

  case 121: /* ExpressaoPrimaria: CHARACTER  */
#line 578 "sintatico.y"
                { 
        Expression *aux = createExpression(PRIMARIA, CHARACTER, (yyvsp[0].token).valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2347 "sintatico.tab.c"
    break;

  case 122: /* ExpressaoPrimaria: STRING  */
#line 582 "sintatico.y"
             { 
        Expression *aux = createExpression(PRIMARIA, STRING, (yyvsp[0].token).valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2356 "sintatico.tab.c"
    break;

  case 123: /* ExpressaoPrimaria: L_PAREN Expressao R_PAREN  */
#line 586 "sintatico.y"
                                {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2364 "sintatico.tab.c"
    break;

  case 124: /* Numero: NUM_INT  */
#line 590 "sintatico.y"
                {
        Expression *aux = createExpression(NUMEROS, NUM_INT, (yyvsp[0].token).valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2373 "sintatico.tab.c"
    break;

  case 125: /* Numero: NUM_HEXA  */
#line 594 "sintatico.y"
               { 
        Expression *aux = createExpression(NUMEROS, NUM_HEXA, (yyvsp[0].token).valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2382 "sintatico.tab.c"
    break;

  case 126: /* Numero: NUM_OCTAL  */
#line 598 "sintatico.y"
                {
        Expression *aux = createExpression(NUMEROS, NUM_OCTAL, (yyvsp[0].token).valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2391 "sintatico.tab.c"
    break;


#line 2395 "sintatico.tab.c"

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

#line 603 "sintatico.y"


void yyerror(void *s) {}

void printLineError(int line, int column) {
    getLineBuffer(line);
        
    printf("\n%s\n", lineBuffer);
    for (int i = 0; i < column - 1; i++) printf(" ");
    printf("^");
}

int main(int argc, char *argv[]) {
    yyparse();
    traverseAST(AST);
    if (textBefore) printf("\n");
    if (erroAux) {
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
        freeAST(AST);
    
    } else {
        int resultado = traverseAST(AST);
        if (resultado != 666) {
            printf("SUCCESSFUL COMPILATION.");
            freeAST(AST);
        }
    }
    return 0;
}
