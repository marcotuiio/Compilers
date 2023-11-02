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


#line 98 "sintatico.tab.c"

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
  YYSYMBOL_DeclaracaoOUFuncao = 63,        /* DeclaracaoOUFuncao  */
  YYSYMBOL_ListaFuncoes = 64,              /* ListaFuncoes  */
  YYSYMBOL_Declaracoes = 65,               /* Declaracoes  */
  YYSYMBOL_Funcao = 66,                    /* Funcao  */
  YYSYMBOL_DeclaraVariaveisFuncao = 67,    /* DeclaraVariaveisFuncao  */
  YYSYMBOL_Ponteiro = 68,                  /* Ponteiro  */
  YYSYMBOL_DeclaraVariaveis = 69,          /* DeclaraVariaveis  */
  YYSYMBOL_BlocoVariaveis = 70,            /* BlocoVariaveis  */
  YYSYMBOL_ExpressaoColchete = 71,         /* ExpressaoColchete  */
  YYSYMBOL_ExpressaoAssign = 72,           /* ExpressaoAssign  */
  YYSYMBOL_RetornoVariavel = 73,           /* RetornoVariavel  */
  YYSYMBOL_DeclaraPrototipos = 74,         /* DeclaraPrototipos  */
  YYSYMBOL_Parametros = 75,                /* Parametros  */
  YYSYMBOL_BlocoParametros = 76,           /* BlocoParametros  */
  YYSYMBOL_RetornaParametros = 77,         /* RetornaParametros  */
  YYSYMBOL_Tipo = 78,                      /* Tipo  */
  YYSYMBOL_Bloco = 79,                     /* Bloco  */
  YYSYMBOL_Comandos = 80,                  /* Comandos  */
  YYSYMBOL_RetornoComandos = 81,           /* RetornoComandos  */
  YYSYMBOL_ListaComandos = 82,             /* ListaComandos  */
  YYSYMBOL_AuxElse = 83,                   /* AuxElse  */
  YYSYMBOL_AuxFor = 84,                    /* AuxFor  */
  YYSYMBOL_AuxPrint = 85,                  /* AuxPrint  */
  YYSYMBOL_Expressao = 86,                 /* Expressao  */
  YYSYMBOL_OpAtrib = 87,                   /* OpAtrib  */
  YYSYMBOL_OpRel = 88,                     /* OpRel  */
  YYSYMBOL_OpMult = 89,                    /* OpMult  */
  YYSYMBOL_OpUnario = 90,                  /* OpUnario  */
  YYSYMBOL_ExpressaoAtribuicao = 91,       /* ExpressaoAtribuicao  */
  YYSYMBOL_ExpressaoCondicional = 92,      /* ExpressaoCondicional  */
  YYSYMBOL_AuxCondicional = 93,            /* AuxCondicional  */
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
  YYSYMBOL_AuxPosFixa = 107,               /* AuxPosFixa  */
  YYSYMBOL_PulaExpressaoAtribuicao = 108,  /* PulaExpressaoAtribuicao  */
  YYSYMBOL_AuxPula = 109,                  /* AuxPula  */
  YYSYMBOL_ExpressaoPrimaria = 110,        /* ExpressaoPrimaria  */
  YYSYMBOL_Numero = 111                    /* Numero  */
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

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
       0,   155,   155,   156,   157,   159,   165,   166,   170,   176,
     178,   179,   180,   182,   191,   192,   194,   195,   197,   199,
     205,   208,   210,   211,   213,   214,   216,   220,   222,   225,
     227,   228,   230,   234,   237,   242,   244,   249,   253,   255,
     259,   263,   267,   271,   275,   279,   283,   287,   291,   292,
     294,   297,   299,   300,   302,   303,   305,   308,   313,   314,
     315,   317,   318,   319,   320,   322,   323,   324,   326,   327,
     328,   329,   330,   331,   333,   334,   339,   341,   342,   344,
     345,   350,   351,   356,   357,   362,   363,   368,   369,   374,
     375,   379,   384,   385,   390,   391,   395,   400,   401,   405,
     410,   411,   416,   417,   421,   422,   423,   424,   426,   427,
     429,   430,   431,   432,   434,   435,   437,   438,   440,   444,
     445,   449,   453,   457,   461,   465
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
  "CHARACTER", "ID", "$accept", "Start", "Programa", "DeclaracaoOUFuncao",
  "ListaFuncoes", "Declaracoes", "Funcao", "DeclaraVariaveisFuncao",
  "Ponteiro", "DeclaraVariaveis", "BlocoVariaveis", "ExpressaoColchete",
  "ExpressaoAssign", "RetornoVariavel", "DeclaraPrototipos", "Parametros",
  "BlocoParametros", "RetornaParametros", "Tipo", "Bloco", "Comandos",
  "RetornoComandos", "ListaComandos", "AuxElse", "AuxFor", "AuxPrint",
  "Expressao", "OpAtrib", "OpRel", "OpMult", "OpUnario",
  "ExpressaoAtribuicao", "ExpressaoCondicional", "AuxCondicional",
  "ExpressaoOrLogico", "ExpressaoAndLogico", "ExpressaoOr", "ExpressaoXor",
  "ExpressaoAnd", "ExpressaoIgual", "ExpressaoRelacional",
  "ExpressaoShift", "ExpressaoAditiva", "ExpressaoMultiplicativa",
  "ExpressaoCast", "ExpressaoUnaria", "ExpressaoPosFixa", "AuxPosFixa",
  "PulaExpressaoAtribuicao", "AuxPula", "ExpressaoPrimaria", "Numero", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,  -158,    26,  -158,  -158,  -158,    16,    88,    65,  -158,
    -158,  -158,  -158,    34,   -32,  -158,  -158,  -158,    65,  -158,
      34,   -15,    47,   186,  -158,  -158,    27,  -158,   167,  -158,
    -158,  -158,  -158,  -158,  -158,   219,   219,  -158,  -158,  -158,
    -158,  -158,  -158,    59,   186,  -158,  -158,    55,    78,    60,
      84,    87,    69,    42,    57,    94,    71,  -158,    62,    -5,
    -158,  -158,    77,   186,   101,    10,    34,     5,   186,  -158,
    -158,   186,  -158,  -158,   186,   186,  -158,   186,   186,   186,
     186,   186,   186,  -158,  -158,  -158,  -158,   186,   186,   186,
     186,   186,  -158,  -158,  -158,   186,  -158,  -158,  -158,   186,
     186,   186,  -158,  -158,  -158,   126,    34,    99,   186,   128,
      77,  -158,   137,  -158,  -158,    78,     0,    60,    84,    87,
      69,    42,    42,    57,    94,    94,    71,    71,  -158,  -158,
     135,   139,   102,  -158,    91,   143,  -158,    34,  -158,   115,
      77,    34,   186,   186,   186,  -158,  -158,  -158,   143,  -158,
      96,  -158,   115,  -158,   150,   152,   154,   155,   156,   157,
     186,   166,  -158,   170,   115,   103,  -158,  -158,  -158,   135,
     172,   143,   171,   162,   186,   186,   186,   133,   134,   178,
      59,   186,  -158,  -158,   115,  -158,  -158,    77,  -158,  -158,
     184,    15,    24,   180,   185,   187,  -158,    63,  -158,  -158,
     186,   150,   150,   186,   186,   189,   163,   183,    64,  -158,
     179,   192,    59,   193,   151,  -158,   195,   150,  -158,   186,
    -158,   202,  -158,  -158,   203,   201,   150,  -158,  -158
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,    32,    33,    34,     0,     0,     9,     6,
       7,    11,    12,    17,     0,     1,     2,     3,     9,     5,
      17,     0,     0,     0,     8,    16,    21,    18,     0,    70,
      71,    69,    68,    73,    72,     0,     0,   123,   124,   125,
     121,   120,   118,    10,     0,    56,    74,    78,    79,    81,
      83,    85,    87,    89,    92,    94,    97,   100,   102,   104,
     108,   119,    29,     0,    23,     0,    17,     0,     0,   105,
     106,     0,   107,   102,     0,     0,    76,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,     0,     0,     0,
       0,     0,    65,    66,    67,     0,    59,    60,    58,     0,
     115,     0,   112,   113,   109,     0,    17,     0,     0,    25,
      15,    26,     0,   122,    57,    80,     0,    82,    84,    86,
      88,    90,    91,    93,    95,    96,    98,    99,   101,    75,
     117,     0,     0,    27,     0,    21,    22,    17,    19,     0,
      15,    17,     0,     0,     0,   114,   111,   110,    21,    20,
       0,    24,     0,    48,     0,     0,     0,     0,     0,     0,
      53,     0,    49,     0,    38,     0,    14,   103,    77,   117,
      31,    21,     0,     0,     0,     0,    53,     0,     0,     0,
      52,     0,    13,    36,    38,    47,   116,    29,    28,    35,
       0,     0,     0,     0,    55,     0,    46,     0,    37,    30,
       0,     0,     0,    53,     0,     0,     0,     0,     0,    40,
      51,     0,    54,     0,     0,    45,     0,     0,    41,    53,
      43,     0,    39,    50,     0,     0,     0,    44,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,   216,   199,  -158,  -158,    89,    -6,  -107,
      81,  -125,  -158,  -158,  -158,  -158,    44,  -158,   -27,  -133,
      80,    53,  -155,  -158,  -157,  -158,   -23,  -158,  -158,  -158,
    -158,   -69,   104,  -158,  -158,   174,   169,   173,   175,   176,
      39,   165,    37,    43,   -36,   -24,  -158,  -158,  -158,    86,
    -158,  -158
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    18,    19,     9,    10,   139,   150,    11,
      22,    64,   109,   138,    12,    65,   105,   188,    13,   162,
     163,   183,   164,   218,   179,   205,   165,    99,    87,    95,
      44,    45,    46,    76,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   104,   131,   145,
      60,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    66,   114,   140,   100,    67,   101,    21,    72,   184,
     149,    69,    70,    71,    25,   113,    15,   110,    71,   193,
      73,   173,     1,   170,   111,   201,     2,    23,    71,   184,
     129,   130,    14,   140,   202,   106,    62,    71,    63,   136,
     107,     3,     4,     5,    26,    67,   211,   102,   103,   143,
      73,    20,   116,    73,    73,    73,    73,    73,    73,   128,
     112,    27,   224,    73,    73,    73,    73,    73,   209,   210,
       2,    73,    71,   207,   216,   169,    71,    71,   132,    83,
      84,    85,    86,   141,   223,     3,     4,     5,    92,    93,
      94,    16,    17,   228,    96,    97,    98,     3,     4,     5,
     134,    74,    78,    75,    81,    82,   167,    88,    89,    90,
      91,   135,    71,   141,   147,    71,    71,   185,    73,    73,
     121,   122,   152,    77,    28,   124,   125,    79,    80,   153,
      29,    30,    31,   126,   127,   108,   133,   180,   154,   155,
     156,   137,   157,   158,   159,   160,   161,   142,   144,   146,
     148,   191,   192,   180,    63,   171,    32,   152,   197,    33,
     106,   174,    34,   175,   176,   177,   178,    35,    36,    37,
      38,    39,    40,    41,    42,   181,    28,   208,   182,   189,
     180,   212,    29,    30,    31,   187,   190,     3,     4,     5,
     194,   195,   196,   200,   203,    28,   180,   215,   204,   213,
     206,    29,    30,    31,   214,   217,   219,   220,    32,   222,
     221,    33,   225,   226,    34,   227,     8,    24,   151,    35,
      36,    37,    38,    39,    40,    41,    42,    32,    68,   166,
      33,   199,   172,    34,    29,    30,    31,   198,    35,    36,
      37,    38,    39,    40,    41,    42,   117,   168,   115,     0,
       0,   118,   123,     0,   119,   186,   120,     0,     0,     0,
      32,     0,     0,    33,     0,     0,    34,     0,     0,     0,
       0,    35,    36,    37,    38,    39,    40,    41,    42
};

static const yytype_int16 yycheck[] =
{
      23,    28,    71,   110,     9,    28,    11,    13,    44,   164,
     135,    35,    36,    13,    20,    10,     0,     7,    13,   176,
      44,   154,     1,   148,    14,    10,     5,    59,    13,   184,
      99,   100,     6,   140,    10,    62,     9,    13,    11,   108,
      63,    20,    21,    22,    59,    68,   203,    52,    53,    49,
      74,    17,    75,    77,    78,    79,    80,    81,    82,    95,
      66,    14,   219,    87,    88,    89,    90,    91,   201,   202,
       5,    95,    13,    10,    10,   144,    13,    13,   101,    37,
      38,    39,    40,   110,   217,    20,    21,    22,    17,    18,
      19,     3,     4,   226,    32,    33,    34,    20,    21,    22,
     106,    46,    42,    48,    35,    36,   142,    50,    51,    15,
      16,    12,    13,   140,    12,    13,    13,    14,   142,   143,
      81,    82,     7,    45,     9,    88,    89,    43,    41,    14,
      15,    16,    17,    90,    91,    34,    10,   160,    23,    24,
      25,    13,    27,    28,    29,    30,    31,    10,    13,    10,
      59,   174,   175,   176,    11,    59,    41,     7,   181,    44,
     187,     9,    47,     9,     9,     9,     9,    52,    53,    54,
      55,    56,    57,    58,    59,     9,     9,   200,     8,     8,
     203,   204,    15,    16,    17,    13,    24,    20,    21,    22,
      57,    57,    14,     9,    14,     9,   219,    14,    13,    10,
      13,    15,    16,    17,    41,    26,    14,    14,    41,    14,
      59,    44,    10,    10,    47,    14,     0,    18,   137,    52,
      53,    54,    55,    56,    57,    58,    59,    41,     9,   140,
      44,   187,   152,    47,    15,    16,    17,   184,    52,    53,
      54,    55,    56,    57,    58,    59,    77,   143,    74,    -1,
      -1,    78,    87,    -1,    79,   169,    80,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    20,    21,    22,    61,    62,    63,    65,
      66,    69,    74,    78,     6,     0,     3,     4,    63,    64,
      17,    68,    70,    59,    64,    68,    59,    14,     9,    15,
      16,    17,    41,    44,    47,    52,    53,    54,    55,    56,
      57,    58,    59,    86,    90,    91,    92,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     110,   111,     9,    11,    71,    75,    78,    86,     9,   105,
     105,    13,   104,   105,    46,    48,    93,    45,    42,    43,
      41,    35,    36,    37,    38,    39,    40,    88,    50,    51,
      15,    16,    17,    18,    19,    89,    32,    33,    34,    87,
       9,    11,    52,    53,   107,    76,    78,    86,    34,    72,
       7,    14,    68,    10,    91,    95,    86,    96,    97,    98,
      99,   100,   100,   101,   102,   102,   103,   103,   104,    91,
      91,   108,    86,    10,    68,    12,    91,    13,    73,    67,
      69,    78,    10,    49,    13,   109,    10,    12,    59,    71,
      68,    70,     7,    14,    23,    24,    25,    27,    28,    29,
      30,    31,    79,    80,    82,    86,    67,   104,    92,    91,
      71,    59,    80,    79,     9,     9,     9,     9,     9,    84,
      86,     9,     8,    81,    82,    14,   109,    13,    77,     8,
      24,    86,    86,    84,    57,    57,    14,    86,    81,    76,
       9,    10,    10,    14,    13,    85,    13,    10,    86,    79,
      79,    84,    86,    10,    41,    14,    10,    26,    83,    14,
      14,    59,    14,    79,    84,    10,    10,    14,    79
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    63,    63,    64,    64,
      65,    65,    65,    66,    67,    67,    68,    68,    69,    70,
      71,    71,    72,    72,    73,    73,    74,    75,    76,    76,
      77,    77,    78,    78,    78,    79,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    89,    89,    89,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   101,   101,   101,   102,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     107,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     1,     1,     2,     0,
       4,     1,     1,     8,     2,     0,     2,     0,     3,     5,
       4,     0,     2,     0,     2,     0,     5,     3,     5,     0,
       2,     0,     1,     1,     1,     3,     2,     2,     0,     7,
       5,     6,     9,     6,     8,     5,     3,     2,     1,     1,
       2,     0,     1,     0,     2,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     4,     0,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     5,     1,     2,     2,     2,     1,     2,
       3,     3,     1,     1,     2,     0,     3,     0,     1,     1,
       1,     1,     3,     1,     1,     1
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
#line 155 "sintatico.y"
                      { erroAux = 0; return 0; }
#line 1375 "sintatico.tab.c"
    break;

  case 3: /* Start: Programa ERRO  */
#line 156 "sintatico.y"
                    { erroAux = 1; return 0; }
#line 1381 "sintatico.tab.c"
    break;

  case 4: /* Start: error  */
#line 157 "sintatico.y"
            { erroAux = 1; return 0; }
#line 1387 "sintatico.tab.c"
    break;

  case 5: /* Programa: DeclaracaoOUFuncao ListaFuncoes  */
#line 159 "sintatico.y"
                                          {
        void **hash = createHash();
        Program *aux = createProgram(hash, (yyvsp[0].func), NULL); // $2 should be a list of functions, therefore Function *
        (yyval.prog) = aux;  // should return the whole program after being parsed, but its returning the union
    }
#line 1397 "sintatico.tab.c"
    break;

  case 6: /* DeclaracaoOUFuncao: Declaracoes  */
#line 165 "sintatico.y"
                                { (yyval.func) = NULL; /* inserir na hash o que quer que apareça aqui */}
#line 1403 "sintatico.tab.c"
    break;

  case 7: /* DeclaracaoOUFuncao: Funcao  */
#line 166 "sintatico.y"
             { 
        (yyval.func) = (yyvsp[0].func);  // should return a list of functions, but its returning the union  
    }
#line 1411 "sintatico.tab.c"
    break;

  case 8: /* ListaFuncoes: DeclaracaoOUFuncao ListaFuncoes  */
#line 170 "sintatico.y"
                                              { 
        if (((Function *) (yyvsp[-1].func)) != NULL) {  // should verify if its a function or a declaration, but its verifying if the union return is NULL
            (yyvsp[-1].func)->next = (yyvsp[0].func);  // should link the fuctions, but is trying to link the unions
            (yyval.func) = (yyvsp[-1].func);  // then again should return the functions, but is returning the union
        }
    }
#line 1422 "sintatico.tab.c"
    break;

  case 9: /* ListaFuncoes: %empty  */
#line 176 "sintatico.y"
      { (yyval.func) = NULL; }
#line 1428 "sintatico.tab.c"
    break;

  case 10: /* Declaracoes: NUMBER_SIGN DEFINE ID Expressao  */
#line 178 "sintatico.y"
                                             { /* Adicionar isso na hash */ }
#line 1434 "sintatico.tab.c"
    break;

  case 11: /* Declaracoes: DeclaraVariaveis  */
#line 179 "sintatico.y"
                       { /* Adicionar isso na hash */ }
#line 1440 "sintatico.tab.c"
    break;

  case 12: /* Declaracoes: DeclaraPrototipos  */
#line 180 "sintatico.y"
                        { /* Adicionar isso na hash */ }
#line 1446 "sintatico.tab.c"
    break;

  case 13: /* Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET  */
#line 182 "sintatico.y"
                                                                                                    {
        void **hash = createHash();
        // descobrir como pegar nome da funcao
        // colocar nome da funcao na hash global e na struct da funcao 
        Function *func = createFunction(hash, (yyvsp[-7].token).type, pointerQntd, "Nome da funcao", (yyvsp[-1].cmd), NULL);
        pointerQntd = 0;  // nao sei se funciona
        (yyval.func) = func;
    }
#line 1459 "sintatico.tab.c"
    break;

  case 14: /* DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao  */
#line 191 "sintatico.y"
                                                                { /* colocar na hash da funcao */}
#line 1465 "sintatico.tab.c"
    break;

  case 15: /* DeclaraVariaveisFuncao: %empty  */
#line 192 "sintatico.y"
      { }
#line 1471 "sintatico.tab.c"
    break;

  case 16: /* Ponteiro: MULTIPLY Ponteiro  */
#line 194 "sintatico.y"
                            { pointerQntd++; }
#line 1477 "sintatico.tab.c"
    break;

  case 17: /* Ponteiro: %empty  */
#line 195 "sintatico.y"
      { }
#line 1483 "sintatico.tab.c"
    break;

  case 18: /* DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON  */
#line 197 "sintatico.y"
                                                { }
#line 1489 "sintatico.tab.c"
    break;

  case 19: /* BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel  */
#line 199 "sintatico.y"
                                                                              {
        // inserir na hash devida
        // considerar ponteiro, nome e dimensoes (se tiver)
        pointerQntd = 0;
    }
#line 1499 "sintatico.tab.c"
    break;

  case 20: /* ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete  */
#line 205 "sintatico.y"
                                                                                 {
        // nova struct para dimensoes?
    }
#line 1507 "sintatico.tab.c"
    break;

  case 21: /* ExpressaoColchete: %empty  */
#line 208 "sintatico.y"
      { }
#line 1513 "sintatico.tab.c"
    break;

  case 22: /* ExpressaoAssign: ASSIGN ExpressaoAtribuicao  */
#line 210 "sintatico.y"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1519 "sintatico.tab.c"
    break;

  case 23: /* ExpressaoAssign: %empty  */
#line 211 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1525 "sintatico.tab.c"
    break;

  case 24: /* RetornoVariavel: COMMA BlocoVariaveis  */
#line 213 "sintatico.y"
                                      { /* colocar na hash */ }
#line 1531 "sintatico.tab.c"
    break;

  case 25: /* RetornoVariavel: %empty  */
#line 214 "sintatico.y"
      { }
#line 1537 "sintatico.tab.c"
    break;

  case 26: /* DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON  */
#line 216 "sintatico.y"
                                                         { 
        // colocar na hash global e ver se bate com as funcoes ?
    }
#line 1545 "sintatico.tab.c"
    break;

  case 27: /* Parametros: L_PAREN BlocoParametros R_PAREN  */
#line 220 "sintatico.y"
                                            { /* vai pra hash */ }
#line 1551 "sintatico.tab.c"
    break;

  case 28: /* BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros  */
#line 222 "sintatico.y"
                                                                      {
        // colocar na hash devida 
    }
#line 1559 "sintatico.tab.c"
    break;

  case 29: /* BlocoParametros: %empty  */
#line 225 "sintatico.y"
      { }
#line 1565 "sintatico.tab.c"
    break;

  case 30: /* RetornaParametros: COMMA BlocoParametros  */
#line 227 "sintatico.y"
                                         { /* colocar na hash */ }
#line 1571 "sintatico.tab.c"
    break;

  case 31: /* RetornaParametros: %empty  */
#line 228 "sintatico.y"
      { }
#line 1577 "sintatico.tab.c"
    break;

  case 32: /* Tipo: INT  */
#line 230 "sintatico.y"
          { 
        CURRENT_TYPE = INT; 
        (yyval.token) = yylval.token; 
    }
#line 1586 "sintatico.tab.c"
    break;

  case 33: /* Tipo: CHAR  */
#line 234 "sintatico.y"
           { CURRENT_TYPE = CHAR;
        (yyval.token) = yylval.token;
    }
#line 1594 "sintatico.tab.c"
    break;

  case 34: /* Tipo: VOID  */
#line 237 "sintatico.y"
           { 
        CURRENT_TYPE = VOID;
        (yyval.token) = yylval.token;
    }
#line 1603 "sintatico.tab.c"
    break;

  case 35: /* Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET  */
#line 242 "sintatico.y"
                                                { (yyval.cmd) = (yyvsp[-1].cmd); }
#line 1609 "sintatico.tab.c"
    break;

  case 36: /* Comandos: ListaComandos RetornoComandos  */
#line 244 "sintatico.y"
                                        {
        (yyvsp[-1].cmd)->next = (yyvsp[0].cmd);
        (yyval.cmd) = (yyvsp[-1].cmd);
    }
#line 1618 "sintatico.tab.c"
    break;

  case 37: /* RetornoComandos: ListaComandos RetornoComandos  */
#line 249 "sintatico.y"
                                               { 
        (yyvsp[-1].cmd)->next = (yyvsp[0].cmd);
        (yyval.cmd) = (yyvsp[-1].cmd);
    }
#line 1627 "sintatico.tab.c"
    break;

  case 38: /* RetornoComandos: %empty  */
#line 253 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 1633 "sintatico.tab.c"
    break;

  case 39: /* ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON  */
#line 255 "sintatico.y"
                                                                  {
        Command *aux = createDoWhileStatement((yyvsp[-2].expr), (yyvsp[-5].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1642 "sintatico.tab.c"
    break;

  case 40: /* ListaComandos: WHILE L_PAREN Expressao R_PAREN Bloco  */
#line 259 "sintatico.y"
                                            {
        Command *aux = createWhileStatement((yyvsp[-2].expr), (yyvsp[0].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1651 "sintatico.tab.c"
    break;

  case 41: /* ListaComandos: IF L_PAREN Expressao R_PAREN Bloco AuxElse  */
#line 263 "sintatico.y"
                                                 {
        Command *aux = createIfStatement((yyvsp[-3].expr), (yyvsp[-1].cmd), (yyvsp[0].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1660 "sintatico.tab.c"
    break;

  case 42: /* ListaComandos: FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco  */
#line 267 "sintatico.y"
                                                                         {
        Command *aux = createForStatement((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].cmd), NULL);
        (yyval.cmd) = aux;
    }
#line 1669 "sintatico.tab.c"
    break;

  case 43: /* ListaComandos: PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON  */
#line 271 "sintatico.y"
                                                       {
        Command *aux = createPrintStatement(yylval.token.valor, (yyvsp[-2].expr), NULL);
        (yyval.cmd) = aux;
    }
#line 1678 "sintatico.tab.c"
    break;

  case 44: /* ListaComandos: SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON  */
#line 275 "sintatico.y"
                                                                  {
        Command *aux = createScanStatement(yylval.token.valor, yylval.token.valor, NULL);
        (yyval.cmd) = aux;
    }
#line 1687 "sintatico.tab.c"
    break;

  case 45: /* ListaComandos: EXIT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 279 "sintatico.y"
                                               {
        Command *aux = createExitStatement((yyvsp[-2].expr), NULL);
        (yyval.cmd) = aux; 
    }
#line 1696 "sintatico.tab.c"
    break;

  case 46: /* ListaComandos: RETURN AuxFor SEMICOLON  */
#line 283 "sintatico.y"
                              {
        Command *aux = createReturnStatement((yyvsp[-1].expr), NULL);
        (yyval.cmd) = aux;
    }
#line 1705 "sintatico.tab.c"
    break;

  case 47: /* ListaComandos: Expressao SEMICOLON  */
#line 287 "sintatico.y"
                          {
        Command *aux = createCommandExpression((yyvsp[-1].expr), NULL);
        (yyval.cmd) = aux;
    }
#line 1714 "sintatico.tab.c"
    break;

  case 48: /* ListaComandos: SEMICOLON  */
#line 291 "sintatico.y"
                { }
#line 1720 "sintatico.tab.c"
    break;

  case 49: /* ListaComandos: Bloco  */
#line 292 "sintatico.y"
            { (yyval.cmd) = (yyvsp[0].cmd); }
#line 1726 "sintatico.tab.c"
    break;

  case 50: /* AuxElse: ELSE Bloco  */
#line 294 "sintatico.y"
                    {
        (yyval.cmd) = (yyvsp[0].cmd);
    }
#line 1734 "sintatico.tab.c"
    break;

  case 51: /* AuxElse: %empty  */
#line 297 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 1740 "sintatico.tab.c"
    break;

  case 52: /* AuxFor: Expressao  */
#line 299 "sintatico.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 1746 "sintatico.tab.c"
    break;

  case 53: /* AuxFor: %empty  */
#line 300 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1752 "sintatico.tab.c"
    break;

  case 54: /* AuxPrint: COMMA Expressao  */
#line 302 "sintatico.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1758 "sintatico.tab.c"
    break;

  case 55: /* AuxPrint: %empty  */
#line 303 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1764 "sintatico.tab.c"
    break;

  case 56: /* Expressao: ExpressaoAtribuicao  */
#line 305 "sintatico.y"
                               {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1772 "sintatico.tab.c"
    break;

  case 57: /* Expressao: Expressao COMMA ExpressaoAtribuicao  */
#line 308 "sintatico.y"
                                          { 
        Expression *aux = createExpression(COMMA, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1781 "sintatico.tab.c"
    break;

  case 58: /* OpAtrib: ASSIGN  */
#line 313 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 1787 "sintatico.tab.c"
    break;

  case 59: /* OpAtrib: ADD_ASSIGN  */
#line 314 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1793 "sintatico.tab.c"
    break;

  case 60: /* OpAtrib: MINUS_ASSIGN  */
#line 315 "sintatico.y"
                   { (yyval.token) = yylval.token; }
#line 1799 "sintatico.tab.c"
    break;

  case 61: /* OpRel: LESS_THAN  */
#line 317 "sintatico.y"
                 { }
#line 1805 "sintatico.tab.c"
    break;

  case 62: /* OpRel: LESS_EQUAL  */
#line 318 "sintatico.y"
                 { }
#line 1811 "sintatico.tab.c"
    break;

  case 63: /* OpRel: GREATER_THAN  */
#line 319 "sintatico.y"
                   { }
#line 1817 "sintatico.tab.c"
    break;

  case 64: /* OpRel: GREATER_EQUAL  */
#line 320 "sintatico.y"
                    { }
#line 1823 "sintatico.tab.c"
    break;

  case 65: /* OpMult: MULTIPLY  */
#line 322 "sintatico.y"
                 { }
#line 1829 "sintatico.tab.c"
    break;

  case 66: /* OpMult: DIVIDE  */
#line 323 "sintatico.y"
             { }
#line 1835 "sintatico.tab.c"
    break;

  case 67: /* OpMult: REMAINDER  */
#line 324 "sintatico.y"
                { }
#line 1841 "sintatico.tab.c"
    break;

  case 68: /* OpUnario: BITWISE_AND  */
#line 326 "sintatico.y"
                      { }
#line 1847 "sintatico.tab.c"
    break;

  case 69: /* OpUnario: MULTIPLY  */
#line 327 "sintatico.y"
               { }
#line 1853 "sintatico.tab.c"
    break;

  case 70: /* OpUnario: PLUS  */
#line 328 "sintatico.y"
           { }
#line 1859 "sintatico.tab.c"
    break;

  case 71: /* OpUnario: MINUS  */
#line 329 "sintatico.y"
            { }
#line 1865 "sintatico.tab.c"
    break;

  case 72: /* OpUnario: NOT  */
#line 330 "sintatico.y"
          { }
#line 1871 "sintatico.tab.c"
    break;

  case 73: /* OpUnario: BITWISE_NOT  */
#line 331 "sintatico.y"
                  { }
#line 1877 "sintatico.tab.c"
    break;

  case 74: /* ExpressaoAtribuicao: ExpressaoCondicional  */
#line 333 "sintatico.y"
                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1883 "sintatico.tab.c"
    break;

  case 75: /* ExpressaoAtribuicao: ExpressaoUnaria OpAtrib ExpressaoAtribuicao  */
#line 334 "sintatico.y"
                                                  {
        Expression *aux = createExpression((yyvsp[-1].token).type, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1892 "sintatico.tab.c"
    break;

  case 76: /* ExpressaoCondicional: ExpressaoOrLogico AuxCondicional  */
#line 339 "sintatico.y"
                                                       { }
#line 1898 "sintatico.tab.c"
    break;

  case 77: /* AuxCondicional: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional  */
#line 341 "sintatico.y"
                                                                         { }
#line 1904 "sintatico.tab.c"
    break;

  case 78: /* AuxCondicional: %empty  */
#line 342 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 1910 "sintatico.tab.c"
    break;

  case 79: /* ExpressaoOrLogico: ExpressaoAndLogico  */
#line 344 "sintatico.y"
                                      { (yyval.expr) = (yyvsp[0].expr); }
#line 1916 "sintatico.tab.c"
    break;

  case 80: /* ExpressaoOrLogico: ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico  */
#line 345 "sintatico.y"
                                                      { 
        Expression *aux = createExpression(LOGICAL_OR, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1925 "sintatico.tab.c"
    break;

  case 81: /* ExpressaoAndLogico: ExpressaoOr  */
#line 350 "sintatico.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1931 "sintatico.tab.c"
    break;

  case 82: /* ExpressaoAndLogico: ExpressaoAndLogico LOGICAL_AND ExpressaoOr  */
#line 351 "sintatico.y"
                                                 {
        Expression *aux = createExpression(LOGICAL_AND, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1940 "sintatico.tab.c"
    break;

  case 83: /* ExpressaoOr: ExpressaoXor  */
#line 356 "sintatico.y"
                          { (yyval.expr) = (yyvsp[0].expr);}
#line 1946 "sintatico.tab.c"
    break;

  case 84: /* ExpressaoOr: ExpressaoOr BITWISE_OR ExpressaoXor  */
#line 357 "sintatico.y"
                                          {
        Expression *aux = createExpression(BITWISE_OR, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1955 "sintatico.tab.c"
    break;

  case 85: /* ExpressaoXor: ExpressaoAnd  */
#line 362 "sintatico.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 1961 "sintatico.tab.c"
    break;

  case 86: /* ExpressaoXor: ExpressaoXor BITWISE_XOR ExpressaoAnd  */
#line 363 "sintatico.y"
                                            {
        Expression *aux = createExpression(BITWISE_XOR, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1970 "sintatico.tab.c"
    break;

  case 87: /* ExpressaoAnd: ExpressaoIgual  */
#line 368 "sintatico.y"
                             { (yyval.expr) = (yyvsp[0].expr); }
#line 1976 "sintatico.tab.c"
    break;

  case 88: /* ExpressaoAnd: ExpressaoAnd BITWISE_AND ExpressaoIgual  */
#line 369 "sintatico.y"
                                              {
        Expression *aux = createExpression(BITWISE_AND, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 1985 "sintatico.tab.c"
    break;

  case 89: /* ExpressaoIgual: ExpressaoRelacional  */
#line 374 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1991 "sintatico.tab.c"
    break;

  case 90: /* ExpressaoIgual: ExpressaoIgual EQUAL ExpressaoRelacional  */
#line 375 "sintatico.y"
                                               {
        Expression *aux = createExpression(EQUAL, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2000 "sintatico.tab.c"
    break;

  case 91: /* ExpressaoIgual: ExpressaoIgual NOT_EQUAL ExpressaoRelacional  */
#line 379 "sintatico.y"
                                                   { 
        Expression *aux = createExpression(NOT_EQUAL, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2009 "sintatico.tab.c"
    break;

  case 92: /* ExpressaoRelacional: ExpressaoShift  */
#line 384 "sintatico.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2015 "sintatico.tab.c"
    break;

  case 93: /* ExpressaoRelacional: ExpressaoRelacional OpRel ExpressaoShift  */
#line 385 "sintatico.y"
                                               { 
        Expression *aux = createExpression((yyvsp[-1].token).type, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2024 "sintatico.tab.c"
    break;

  case 94: /* ExpressaoShift: ExpressaoAditiva  */
#line 390 "sintatico.y"
                                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2030 "sintatico.tab.c"
    break;

  case 95: /* ExpressaoShift: ExpressaoShift R_SHIFT ExpressaoAditiva  */
#line 391 "sintatico.y"
                                              {
        Expression *aux = createExpression(R_SHIFT, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2039 "sintatico.tab.c"
    break;

  case 96: /* ExpressaoShift: ExpressaoShift L_SHIFT ExpressaoAditiva  */
#line 395 "sintatico.y"
                                              {
        Expression *aux = createExpression(L_SHIFT, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2048 "sintatico.tab.c"
    break;

  case 97: /* ExpressaoAditiva: ExpressaoMultiplicativa  */
#line 400 "sintatico.y"
                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2054 "sintatico.tab.c"
    break;

  case 98: /* ExpressaoAditiva: ExpressaoAditiva PLUS ExpressaoMultiplicativa  */
#line 401 "sintatico.y"
                                                    { 
        Expression *aux = createExpression(PLUS, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2063 "sintatico.tab.c"
    break;

  case 99: /* ExpressaoAditiva: ExpressaoAditiva MINUS ExpressaoMultiplicativa  */
#line 405 "sintatico.y"
                                                     { 
        Expression *aux = createExpression(MINUS, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2072 "sintatico.tab.c"
    break;

  case 100: /* ExpressaoMultiplicativa: ExpressaoCast  */
#line 410 "sintatico.y"
                                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2078 "sintatico.tab.c"
    break;

  case 101: /* ExpressaoMultiplicativa: ExpressaoMultiplicativa OpMult ExpressaoCast  */
#line 411 "sintatico.y"
                                                   {
        Expression *aux = createExpression((yyvsp[-1].token).type, NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = aux;
    }
#line 2087 "sintatico.tab.c"
    break;

  case 102: /* ExpressaoCast: ExpressaoUnaria  */
#line 416 "sintatico.y"
                               { (yyval.expr) = (yyvsp[0].expr); }
#line 2093 "sintatico.tab.c"
    break;

  case 103: /* ExpressaoCast: L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast  */
#line 417 "sintatico.y"
                                                  {
        // tem qua tratar o ponteiro e fazer alguma coisa com essa expressao
    }
#line 2101 "sintatico.tab.c"
    break;

  case 104: /* ExpressaoUnaria: ExpressaoPosFixa  */
#line 421 "sintatico.y"
                                  { (yyval.expr) = (yyvsp[0].expr); }
#line 2107 "sintatico.tab.c"
    break;

  case 105: /* ExpressaoUnaria: INC ExpressaoUnaria  */
#line 422 "sintatico.y"
                          { }
#line 2113 "sintatico.tab.c"
    break;

  case 106: /* ExpressaoUnaria: DEC ExpressaoUnaria  */
#line 423 "sintatico.y"
                          { }
#line 2119 "sintatico.tab.c"
    break;

  case 107: /* ExpressaoUnaria: OpUnario ExpressaoCast  */
#line 424 "sintatico.y"
                             { }
#line 2125 "sintatico.tab.c"
    break;

  case 108: /* ExpressaoPosFixa: ExpressaoPrimaria  */
#line 426 "sintatico.y"
                                    { }
#line 2131 "sintatico.tab.c"
    break;

  case 109: /* ExpressaoPosFixa: ExpressaoPosFixa AuxPosFixa  */
#line 427 "sintatico.y"
                                  { }
#line 2137 "sintatico.tab.c"
    break;

  case 110: /* AuxPosFixa: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET  */
#line 429 "sintatico.y"
                                                        { (yyval.expr) = (yyvsp[-1].expr); }
#line 2143 "sintatico.tab.c"
    break;

  case 111: /* AuxPosFixa: L_PAREN PulaExpressaoAtribuicao R_PAREN  */
#line 430 "sintatico.y"
                                              { (yyval.expr) = (yyvsp[-1].expr); }
#line 2149 "sintatico.tab.c"
    break;

  case 112: /* AuxPosFixa: INC  */
#line 431 "sintatico.y"
          { }
#line 2155 "sintatico.tab.c"
    break;

  case 113: /* AuxPosFixa: DEC  */
#line 432 "sintatico.y"
          { }
#line 2161 "sintatico.tab.c"
    break;

  case 114: /* PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula  */
#line 434 "sintatico.y"
                                                     { }
#line 2167 "sintatico.tab.c"
    break;

  case 115: /* PulaExpressaoAtribuicao: %empty  */
#line 435 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2173 "sintatico.tab.c"
    break;

  case 116: /* AuxPula: COMMA ExpressaoAtribuicao AuxPula  */
#line 437 "sintatico.y"
                                           { }
#line 2179 "sintatico.tab.c"
    break;

  case 117: /* AuxPula: %empty  */
#line 438 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2185 "sintatico.tab.c"
    break;

  case 118: /* ExpressaoPrimaria: ID  */
#line 440 "sintatico.y"
                      { 
        Expression *aux = createExpression(ID, yylval.token.valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2194 "sintatico.tab.c"
    break;

  case 119: /* ExpressaoPrimaria: Numero  */
#line 444 "sintatico.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 2200 "sintatico.tab.c"
    break;

  case 120: /* ExpressaoPrimaria: CHARACTER  */
#line 445 "sintatico.y"
                { 
        Expression *aux = createExpression(CHARACTER, yylval.token.valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2209 "sintatico.tab.c"
    break;

  case 121: /* ExpressaoPrimaria: STRING  */
#line 449 "sintatico.y"
             { 
        Expression *aux = createExpression(STRING, yylval.token.valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2218 "sintatico.tab.c"
    break;

  case 122: /* ExpressaoPrimaria: L_PAREN Expressao R_PAREN  */
#line 453 "sintatico.y"
                                {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2226 "sintatico.tab.c"
    break;

  case 123: /* Numero: NUM_INT  */
#line 457 "sintatico.y"
                {
        Expression *aux = createExpression(NUM_INT, yylval.token.valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2235 "sintatico.tab.c"
    break;

  case 124: /* Numero: NUM_HEXA  */
#line 461 "sintatico.y"
               { 
        Expression *aux = createExpression(NUM_HEXA, yylval.token.valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2244 "sintatico.tab.c"
    break;

  case 125: /* Numero: NUM_OCTAL  */
#line 465 "sintatico.y"
                {
        Expression *aux = createExpression(NUM_OCTAL, yylval.token.valor, NULL, NULL);
        (yyval.expr) = aux;
    }
#line 2253 "sintatico.tab.c"
    break;


#line 2257 "sintatico.tab.c"

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

#line 470 "sintatico.y"


void yyerror(void *s) {}

int main(int argc, char *argv[]) {
    yyparse();

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

        getLineBuffer(yylval.token.line);
        
        printf("\n%s\n", lineBuffer);
        for (int i = 0; i < localColumn - 1; i++) printf(" ");
        printf("^");

    } else {
        printf("SUCCESSFUL COMPILATION.");
    }
    return 0;
}
