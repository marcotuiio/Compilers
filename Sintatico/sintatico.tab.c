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


#include <stdio.h>
#include <string.h>
extern int yylex();
extern char *yytext;
extern int yychar;
extern int textBefore;
extern char lineBuffer[2048];
int erroAux = 0;
void yyerror(void *s);


#line 85 "sintatico.tab.c"

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
  YYSYMBOL_AuxPrograma = 63,               /* AuxPrograma  */
  YYSYMBOL_Declaracoes = 64,               /* Declaracoes  */
  YYSYMBOL_Funcao = 65,                    /* Funcao  */
  YYSYMBOL_DeclaraVariaveisFuncao = 66,    /* DeclaraVariaveisFuncao  */
  YYSYMBOL_Ponteiro = 67,                  /* Ponteiro  */
  YYSYMBOL_DeclaraVariaveis = 68,          /* DeclaraVariaveis  */
  YYSYMBOL_BlocoVariaveis = 69,            /* BlocoVariaveis  */
  YYSYMBOL_ExpressaoColchete = 70,         /* ExpressaoColchete  */
  YYSYMBOL_ExpressaoAssign = 71,           /* ExpressaoAssign  */
  YYSYMBOL_RetornoVariavel = 72,           /* RetornoVariavel  */
  YYSYMBOL_DeclaraPrototipos = 73,         /* DeclaraPrototipos  */
  YYSYMBOL_Parametros = 74,                /* Parametros  */
  YYSYMBOL_BlocoParametros = 75,           /* BlocoParametros  */
  YYSYMBOL_RetornaParametros = 76,         /* RetornaParametros  */
  YYSYMBOL_Tipo = 77,                      /* Tipo  */
  YYSYMBOL_Bloco = 78,                     /* Bloco  */
  YYSYMBOL_Comandos = 79,                  /* Comandos  */
  YYSYMBOL_RetornoComandos = 80,           /* RetornoComandos  */
  YYSYMBOL_ListaComandos = 81,             /* ListaComandos  */
  YYSYMBOL_AuxElse = 82,                   /* AuxElse  */
  YYSYMBOL_AuxFor = 83,                    /* AuxFor  */
  YYSYMBOL_AuxPrint = 84,                  /* AuxPrint  */
  YYSYMBOL_Expressao = 85,                 /* Expressao  */
  YYSYMBOL_OpAtrib = 86,                   /* OpAtrib  */
  YYSYMBOL_OpRel = 87,                     /* OpRel  */
  YYSYMBOL_OpMult = 88,                    /* OpMult  */
  YYSYMBOL_OpUnario = 89,                  /* OpUnario  */
  YYSYMBOL_ExpressaoAtribuicao = 90,       /* ExpressaoAtribuicao  */
  YYSYMBOL_ExpressaoCondicional = 91,      /* ExpressaoCondicional  */
  YYSYMBOL_AuxCondicional = 92,            /* AuxCondicional  */
  YYSYMBOL_ExpressaoOrLogico = 93,         /* ExpressaoOrLogico  */
  YYSYMBOL_ExpressaoAndLogico = 94,        /* ExpressaoAndLogico  */
  YYSYMBOL_ExpressaoOr = 95,               /* ExpressaoOr  */
  YYSYMBOL_ExpressaoXor = 96,              /* ExpressaoXor  */
  YYSYMBOL_ExpressaoAnd = 97,              /* ExpressaoAnd  */
  YYSYMBOL_ExpressaoIgual = 98,            /* ExpressaoIgual  */
  YYSYMBOL_ExpressaoRelacional = 99,       /* ExpressaoRelacional  */
  YYSYMBOL_ExpressaoShift = 100,           /* ExpressaoShift  */
  YYSYMBOL_ExpressaoAditiva = 101,         /* ExpressaoAditiva  */
  YYSYMBOL_ExpressaoMultiplicativa = 102,  /* ExpressaoMultiplicativa  */
  YYSYMBOL_ExpressaoCast = 103,            /* ExpressaoCast  */
  YYSYMBOL_ExpressaoUnaria = 104,          /* ExpressaoUnaria  */
  YYSYMBOL_ExpressaoPosFixa = 105,         /* ExpressaoPosFixa  */
  YYSYMBOL_AuxPosFixa = 106,               /* AuxPosFixa  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
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
       0,    87,    87,    88,    89,    92,    93,    96,    97,    99,
     100,   101,   104,   107,   108,   111,   112,   115,   118,   121,
     122,   125,   126,   128,   129,   132,   135,   138,   139,   142,
     143,   145,   146,   147,   150,   153,   156,   157,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   173,
     174,   177,   178,   181,   182,   185,   186,   189,   190,   191,
     194,   195,   196,   197,   200,   201,   202,   205,   206,   207,
     208,   209,   210,   213,   214,   217,   220,   221,   223,   224,
     227,   228,   231,   232,   235,   236,   239,   240,   243,   244,
     245,   248,   249,   251,   252,   253,   256,   257,   258,   261,
     262,   265,   266,   269,   270,   271,   272,   275,   276,   279,
     280,   281,   282,   285,   286,   289,   290,   293,   294,   295,
     296,   297,   300,   301,   302
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
  "CHARACTER", "ID", "$accept", "Start", "Programa", "AuxPrograma",
  "Declaracoes", "Funcao", "DeclaraVariaveisFuncao", "Ponteiro",
  "DeclaraVariaveis", "BlocoVariaveis", "ExpressaoColchete",
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

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,  -161,    86,  -161,  -161,  -161,    61,    14,    65,    65,
    -161,  -161,    10,    46,  -161,  -161,  -161,    65,  -161,  -161,
      10,    48,   109,   186,  -161,  -161,    92,  -161,   167,  -161,
    -161,  -161,  -161,  -161,  -161,   219,   219,  -161,  -161,  -161,
    -161,  -161,  -161,    99,   186,  -161,  -161,    56,    82,    94,
      85,   100,    41,    51,    31,    93,    55,  -161,    62,    27,
    -161,  -161,    77,   186,   101,     2,    10,    15,   186,  -161,
    -161,   186,  -161,  -161,   186,   186,  -161,   186,   186,   186,
     186,   186,   186,  -161,  -161,  -161,  -161,   186,   186,   186,
     186,   186,  -161,  -161,  -161,   186,  -161,  -161,  -161,   186,
     186,   186,  -161,  -161,  -161,   137,    10,    98,   186,   135,
      77,  -161,   139,  -161,  -161,    82,     0,    94,    85,   100,
      41,    51,    51,    31,    93,    93,    55,    55,  -161,  -161,
     141,   140,   102,  -161,    96,   146,  -161,    10,  -161,   115,
      77,    10,   186,   186,   186,  -161,  -161,  -161,   146,  -161,
     104,  -161,   115,  -161,   154,   155,   156,   157,   166,   169,
     186,   170,  -161,   177,   115,   103,  -161,  -161,  -161,   141,
     173,   146,   182,   168,   186,   186,   186,   134,   136,   180,
      99,   186,  -161,  -161,   115,  -161,  -161,    77,  -161,  -161,
     188,    19,    24,   184,   187,   191,  -161,    34,  -161,  -161,
     186,   154,   154,   186,   186,   189,   164,   192,    38,  -161,
     181,   195,    99,   196,   153,  -161,   199,   154,  -161,   186,
    -161,   205,  -161,  -161,   206,   203,   154,  -161,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,    31,    32,    33,     0,     0,     8,     8,
      10,    11,    16,     0,     1,     2,     3,     8,     5,     6,
      16,     0,     0,     0,     7,    15,    20,    17,     0,    69,
      70,    68,    67,    72,    71,     0,     0,   122,   123,   124,
     120,   119,   117,     9,     0,    55,    73,    77,    78,    80,
      82,    84,    86,    88,    91,    93,    96,    99,   101,   103,
     107,   118,    28,     0,    22,     0,    16,     0,     0,   104,
     105,     0,   106,   101,     0,     0,    75,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,     0,     0,     0,
       0,     0,    64,    65,    66,     0,    58,    59,    57,     0,
     114,     0,   111,   112,   108,     0,    16,     0,     0,    24,
      14,    25,     0,   121,    56,    79,     0,    81,    83,    85,
      87,    89,    90,    92,    94,    95,    97,    98,   100,    74,
     116,     0,     0,    26,     0,    20,    21,    16,    18,     0,
      14,    16,     0,     0,     0,   113,   110,   109,    20,    19,
       0,    23,     0,    47,     0,     0,     0,     0,     0,     0,
      52,     0,    48,     0,    37,     0,    13,   102,    76,   116,
      30,    20,     0,     0,     0,     0,    52,     0,     0,     0,
      51,     0,    12,    35,    37,    46,   115,    28,    27,    34,
       0,     0,     0,     0,    54,     0,    45,     0,    36,    29,
       0,     0,     0,    52,     0,     0,     0,     0,     0,    39,
      50,     0,    53,     0,     0,    44,     0,     0,    40,    52,
      42,     0,    38,    49,     0,     0,     0,    43,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,   218,    -2,  -161,  -161,    89,    -6,  -107,    95,
    -125,  -161,  -161,  -161,  -161,    44,  -161,   -27,  -133,    97,
      53,  -160,  -161,  -157,  -161,   -23,  -161,  -161,  -161,  -161,
     -69,   105,  -161,  -161,   172,   174,   175,   171,   176,    39,
     160,    37,    43,   -36,   -24,  -161,  -161,  -161,    83,  -161,
    -161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,    17,    18,     8,     9,   139,   150,    10,    22,
      64,   109,   138,    11,    65,   105,   188,    12,   162,   163,
     183,   164,   218,   179,   205,   165,    99,    87,    95,    44,
      45,    46,    76,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   104,   131,   145,    60,
      61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    66,   114,   140,   184,    67,    21,    19,    72,   110,
     149,    69,    70,    71,    25,    24,   111,    15,    16,   193,
      73,   173,     1,   170,   184,   113,     2,    20,    71,   201,
     129,   130,    71,   140,   202,   106,   100,    71,   101,   136,
     107,     3,     4,     5,   207,    67,   211,    71,   216,   143,
      73,    71,   116,    73,    73,    73,    73,    73,    73,   128,
     112,    14,   224,    73,    73,    73,    73,    73,   209,   210,
       2,    73,    92,    93,    94,   169,    81,    82,   132,   102,
     103,    88,    89,   141,   223,     3,     4,     5,    83,    84,
      85,    86,    13,   228,    96,    97,    98,     3,     4,     5,
     134,    62,    74,    63,    75,    23,   167,    26,    90,    91,
     135,    71,    71,   141,   147,    71,    71,   185,    73,    73,
     121,   122,   152,    27,    28,   124,   125,    77,    79,   153,
      29,    30,    31,   126,   127,   108,    78,   180,   154,   155,
     156,    80,   157,   158,   159,   160,   161,   133,   137,   142,
     146,   191,   192,   180,   144,   148,    32,    63,   197,    33,
     106,   152,    34,   171,   174,   175,   176,    35,    36,    37,
      38,    39,    40,    41,    42,   177,    28,   208,   178,   181,
     180,   212,    29,    30,    31,   182,   187,     3,     4,     5,
     189,   194,   190,   195,   196,    28,   180,   200,   203,   213,
     204,    29,    30,    31,   206,   214,   215,   217,    32,   219,
     220,    33,   221,   222,    34,   225,   226,   227,     7,    35,
      36,    37,    38,    39,    40,    41,    42,    32,    68,   166,
      33,   199,   151,    34,    29,    30,    31,   198,    35,    36,
      37,    38,    39,    40,    41,    42,   115,   123,   168,   172,
     119,   117,   186,   118,     0,     0,   120,     0,     0,     0,
      32,     0,     0,    33,     0,     0,    34,     0,     0,     0,
       0,    35,    36,    37,    38,    39,    40,    41,    42
};

static const yytype_int16 yycheck[] =
{
      23,    28,    71,   110,   164,    28,    12,     9,    44,     7,
     135,    35,    36,    13,    20,    17,    14,     3,     4,   176,
      44,   154,     1,   148,   184,    10,     5,    17,    13,    10,
      99,   100,    13,   140,    10,    62,     9,    13,    11,   108,
      63,    20,    21,    22,    10,    68,   203,    13,    10,    49,
      74,    13,    75,    77,    78,    79,    80,    81,    82,    95,
      66,     0,   219,    87,    88,    89,    90,    91,   201,   202,
       5,    95,    17,    18,    19,   144,    35,    36,   101,    52,
      53,    50,    51,   110,   217,    20,    21,    22,    37,    38,
      39,    40,     6,   226,    32,    33,    34,    20,    21,    22,
     106,     9,    46,    11,    48,    59,   142,    59,    15,    16,
      12,    13,    13,   140,    12,    13,    13,    14,   142,   143,
      81,    82,     7,    14,     9,    88,    89,    45,    43,    14,
      15,    16,    17,    90,    91,    34,    42,   160,    23,    24,
      25,    41,    27,    28,    29,    30,    31,    10,    13,    10,
      10,   174,   175,   176,    13,    59,    41,    11,   181,    44,
     187,     7,    47,    59,     9,     9,     9,    52,    53,    54,
      55,    56,    57,    58,    59,     9,     9,   200,     9,     9,
     203,   204,    15,    16,    17,     8,    13,    20,    21,    22,
       8,    57,    24,    57,    14,     9,   219,     9,    14,    10,
      13,    15,    16,    17,    13,    41,    14,    26,    41,    14,
      14,    44,    59,    14,    47,    10,    10,    14,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    41,     9,   140,
      44,   187,   137,    47,    15,    16,    17,   184,    52,    53,
      54,    55,    56,    57,    58,    59,    74,    87,   143,   152,
      79,    77,   169,    78,    -1,    -1,    80,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    20,    21,    22,    61,    62,    64,    65,
      68,    73,    77,     6,     0,     3,     4,    62,    63,    63,
      17,    67,    69,    59,    63,    67,    59,    14,     9,    15,
      16,    17,    41,    44,    47,    52,    53,    54,    55,    56,
      57,    58,    59,    85,    89,    90,    91,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     109,   110,     9,    11,    70,    74,    77,    85,     9,   104,
     104,    13,   103,   104,    46,    48,    92,    45,    42,    43,
      41,    35,    36,    37,    38,    39,    40,    87,    50,    51,
      15,    16,    17,    18,    19,    88,    32,    33,    34,    86,
       9,    11,    52,    53,   106,    75,    77,    85,    34,    71,
       7,    14,    67,    10,    90,    94,    85,    95,    96,    97,
      98,    99,    99,   100,   101,   101,   102,   102,   103,    90,
      90,   107,    85,    10,    67,    12,    90,    13,    72,    66,
      68,    77,    10,    49,    13,   108,    10,    12,    59,    70,
      67,    69,     7,    14,    23,    24,    25,    27,    28,    29,
      30,    31,    78,    79,    81,    85,    66,   103,    91,    90,
      70,    59,    79,    78,     9,     9,     9,     9,     9,    83,
      85,     9,     8,    80,    81,    14,   108,    13,    76,     8,
      24,    85,    85,    83,    57,    57,    14,    85,    80,    75,
       9,    10,    10,    14,    13,    84,    13,    10,    85,    78,
      78,    83,    85,    10,    41,    14,    10,    26,    82,    14,
      14,    59,    14,    78,    83,    10,    10,    14,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    65,    66,    66,    67,    67,    68,    69,    70,
      70,    71,    71,    72,    72,    73,    74,    75,    75,    76,
      76,    77,    77,    77,    78,    79,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      98,    99,    99,   100,   100,   100,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   104,   105,   105,   106,
     106,   106,   106,   107,   107,   108,   108,   109,   109,   109,
     109,   109,   110,   110,   110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     0,     4,
       1,     1,     8,     2,     0,     2,     0,     3,     5,     4,
       0,     2,     0,     2,     0,     5,     3,     5,     0,     2,
       0,     1,     1,     1,     3,     2,     2,     0,     7,     5,
       6,     9,     6,     8,     5,     3,     2,     1,     1,     2,
       0,     1,     0,     2,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     4,     0,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     5,     1,     2,     2,     2,     1,     2,     3,
       3,     1,     1,     2,     0,     3,     0,     1,     1,     1,
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
#line 87 "sintatico.y"
                      { erroAux = 0; return 0; }
#line 1361 "sintatico.tab.c"
    break;

  case 3: /* Start: Programa ERRO  */
#line 88 "sintatico.y"
                    { erroAux = 1; return 0; }
#line 1367 "sintatico.tab.c"
    break;

  case 4: /* Start: error  */
#line 89 "sintatico.y"
            { erroAux = 1; return 0; }
#line 1373 "sintatico.tab.c"
    break;

  case 5: /* Programa: Declaracoes AuxPrograma  */
#line 92 "sintatico.y"
                                  { }
#line 1379 "sintatico.tab.c"
    break;

  case 6: /* Programa: Funcao AuxPrograma  */
#line 93 "sintatico.y"
                         { }
#line 1385 "sintatico.tab.c"
    break;

  case 7: /* AuxPrograma: Programa AuxPrograma  */
#line 96 "sintatico.y"
                                  { }
#line 1391 "sintatico.tab.c"
    break;

  case 8: /* AuxPrograma: %empty  */
#line 97 "sintatico.y"
      { }
#line 1397 "sintatico.tab.c"
    break;

  case 9: /* Declaracoes: NUMBER_SIGN DEFINE ID Expressao  */
#line 99 "sintatico.y"
                                             { }
#line 1403 "sintatico.tab.c"
    break;

  case 10: /* Declaracoes: DeclaraVariaveis  */
#line 100 "sintatico.y"
                       { }
#line 1409 "sintatico.tab.c"
    break;

  case 11: /* Declaracoes: DeclaraPrototipos  */
#line 101 "sintatico.y"
                        { }
#line 1415 "sintatico.tab.c"
    break;

  case 12: /* Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET  */
#line 104 "sintatico.y"
                                                                                                    { }
#line 1421 "sintatico.tab.c"
    break;

  case 13: /* DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao  */
#line 107 "sintatico.y"
                                                                { }
#line 1427 "sintatico.tab.c"
    break;

  case 14: /* DeclaraVariaveisFuncao: %empty  */
#line 108 "sintatico.y"
      { }
#line 1433 "sintatico.tab.c"
    break;

  case 15: /* Ponteiro: MULTIPLY Ponteiro  */
#line 111 "sintatico.y"
                            { }
#line 1439 "sintatico.tab.c"
    break;

  case 16: /* Ponteiro: %empty  */
#line 112 "sintatico.y"
      { }
#line 1445 "sintatico.tab.c"
    break;

  case 17: /* DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON  */
#line 115 "sintatico.y"
                                                { }
#line 1451 "sintatico.tab.c"
    break;

  case 18: /* BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel  */
#line 118 "sintatico.y"
                                                                              { }
#line 1457 "sintatico.tab.c"
    break;

  case 19: /* ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete  */
#line 121 "sintatico.y"
                                                                                 { }
#line 1463 "sintatico.tab.c"
    break;

  case 20: /* ExpressaoColchete: %empty  */
#line 122 "sintatico.y"
      { }
#line 1469 "sintatico.tab.c"
    break;

  case 21: /* ExpressaoAssign: ASSIGN ExpressaoAtribuicao  */
#line 125 "sintatico.y"
                                            { }
#line 1475 "sintatico.tab.c"
    break;

  case 22: /* ExpressaoAssign: %empty  */
#line 126 "sintatico.y"
      { }
#line 1481 "sintatico.tab.c"
    break;

  case 23: /* RetornoVariavel: COMMA BlocoVariaveis  */
#line 128 "sintatico.y"
                                      { }
#line 1487 "sintatico.tab.c"
    break;

  case 24: /* RetornoVariavel: %empty  */
#line 129 "sintatico.y"
      { }
#line 1493 "sintatico.tab.c"
    break;

  case 25: /* DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON  */
#line 132 "sintatico.y"
                                                         { }
#line 1499 "sintatico.tab.c"
    break;

  case 26: /* Parametros: L_PAREN BlocoParametros R_PAREN  */
#line 135 "sintatico.y"
                                            { }
#line 1505 "sintatico.tab.c"
    break;

  case 27: /* BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros  */
#line 138 "sintatico.y"
                                                                      { }
#line 1511 "sintatico.tab.c"
    break;

  case 28: /* BlocoParametros: %empty  */
#line 139 "sintatico.y"
      { }
#line 1517 "sintatico.tab.c"
    break;

  case 29: /* RetornaParametros: COMMA BlocoParametros  */
#line 142 "sintatico.y"
                                         { }
#line 1523 "sintatico.tab.c"
    break;

  case 30: /* RetornaParametros: %empty  */
#line 143 "sintatico.y"
      { }
#line 1529 "sintatico.tab.c"
    break;

  case 31: /* Tipo: INT  */
#line 145 "sintatico.y"
          { }
#line 1535 "sintatico.tab.c"
    break;

  case 32: /* Tipo: CHAR  */
#line 146 "sintatico.y"
           { }
#line 1541 "sintatico.tab.c"
    break;

  case 33: /* Tipo: VOID  */
#line 147 "sintatico.y"
           { }
#line 1547 "sintatico.tab.c"
    break;

  case 34: /* Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET  */
#line 150 "sintatico.y"
                                                { }
#line 1553 "sintatico.tab.c"
    break;

  case 35: /* Comandos: ListaComandos RetornoComandos  */
#line 153 "sintatico.y"
                                        { }
#line 1559 "sintatico.tab.c"
    break;

  case 36: /* RetornoComandos: ListaComandos RetornoComandos  */
#line 156 "sintatico.y"
                                               { }
#line 1565 "sintatico.tab.c"
    break;

  case 37: /* RetornoComandos: %empty  */
#line 157 "sintatico.y"
      { }
#line 1571 "sintatico.tab.c"
    break;

  case 38: /* ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON  */
#line 160 "sintatico.y"
                                                                  { }
#line 1577 "sintatico.tab.c"
    break;

  case 39: /* ListaComandos: WHILE L_PAREN Expressao R_PAREN Bloco  */
#line 161 "sintatico.y"
                                            { }
#line 1583 "sintatico.tab.c"
    break;

  case 40: /* ListaComandos: IF L_PAREN Expressao R_PAREN Bloco AuxElse  */
#line 162 "sintatico.y"
                                                 { }
#line 1589 "sintatico.tab.c"
    break;

  case 41: /* ListaComandos: FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco  */
#line 163 "sintatico.y"
                                                                         { }
#line 1595 "sintatico.tab.c"
    break;

  case 42: /* ListaComandos: PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON  */
#line 164 "sintatico.y"
                                                       { }
#line 1601 "sintatico.tab.c"
    break;

  case 43: /* ListaComandos: SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON  */
#line 165 "sintatico.y"
                                                                  { }
#line 1607 "sintatico.tab.c"
    break;

  case 44: /* ListaComandos: EXIT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 166 "sintatico.y"
                                               { }
#line 1613 "sintatico.tab.c"
    break;

  case 45: /* ListaComandos: RETURN AuxFor SEMICOLON  */
#line 167 "sintatico.y"
                              { }
#line 1619 "sintatico.tab.c"
    break;

  case 46: /* ListaComandos: Expressao SEMICOLON  */
#line 168 "sintatico.y"
                          { }
#line 1625 "sintatico.tab.c"
    break;

  case 47: /* ListaComandos: SEMICOLON  */
#line 169 "sintatico.y"
                { }
#line 1631 "sintatico.tab.c"
    break;

  case 48: /* ListaComandos: Bloco  */
#line 170 "sintatico.y"
            { }
#line 1637 "sintatico.tab.c"
    break;

  case 49: /* AuxElse: ELSE Bloco  */
#line 173 "sintatico.y"
                    { }
#line 1643 "sintatico.tab.c"
    break;

  case 50: /* AuxElse: %empty  */
#line 174 "sintatico.y"
      { }
#line 1649 "sintatico.tab.c"
    break;

  case 51: /* AuxFor: Expressao  */
#line 177 "sintatico.y"
                  { }
#line 1655 "sintatico.tab.c"
    break;

  case 52: /* AuxFor: %empty  */
#line 178 "sintatico.y"
      { }
#line 1661 "sintatico.tab.c"
    break;

  case 53: /* AuxPrint: COMMA Expressao  */
#line 181 "sintatico.y"
                          { }
#line 1667 "sintatico.tab.c"
    break;

  case 54: /* AuxPrint: %empty  */
#line 182 "sintatico.y"
      { }
#line 1673 "sintatico.tab.c"
    break;

  case 55: /* Expressao: ExpressaoAtribuicao  */
#line 185 "sintatico.y"
                               { }
#line 1679 "sintatico.tab.c"
    break;

  case 56: /* Expressao: Expressao COMMA ExpressaoAtribuicao  */
#line 186 "sintatico.y"
                                          { }
#line 1685 "sintatico.tab.c"
    break;

  case 57: /* OpAtrib: ASSIGN  */
#line 189 "sintatico.y"
                { }
#line 1691 "sintatico.tab.c"
    break;

  case 58: /* OpAtrib: ADD_ASSIGN  */
#line 190 "sintatico.y"
                 { }
#line 1697 "sintatico.tab.c"
    break;

  case 59: /* OpAtrib: MINUS_ASSIGN  */
#line 191 "sintatico.y"
                   { }
#line 1703 "sintatico.tab.c"
    break;

  case 60: /* OpRel: LESS_THAN  */
#line 194 "sintatico.y"
                 { }
#line 1709 "sintatico.tab.c"
    break;

  case 61: /* OpRel: LESS_EQUAL  */
#line 195 "sintatico.y"
                 { }
#line 1715 "sintatico.tab.c"
    break;

  case 62: /* OpRel: GREATER_THAN  */
#line 196 "sintatico.y"
                   { }
#line 1721 "sintatico.tab.c"
    break;

  case 63: /* OpRel: GREATER_EQUAL  */
#line 197 "sintatico.y"
                    { }
#line 1727 "sintatico.tab.c"
    break;

  case 64: /* OpMult: MULTIPLY  */
#line 200 "sintatico.y"
                 { }
#line 1733 "sintatico.tab.c"
    break;

  case 65: /* OpMult: DIVIDE  */
#line 201 "sintatico.y"
             { }
#line 1739 "sintatico.tab.c"
    break;

  case 66: /* OpMult: REMAINDER  */
#line 202 "sintatico.y"
                { }
#line 1745 "sintatico.tab.c"
    break;

  case 67: /* OpUnario: BITWISE_AND  */
#line 205 "sintatico.y"
                      { }
#line 1751 "sintatico.tab.c"
    break;

  case 68: /* OpUnario: MULTIPLY  */
#line 206 "sintatico.y"
               { }
#line 1757 "sintatico.tab.c"
    break;

  case 69: /* OpUnario: PLUS  */
#line 207 "sintatico.y"
           { }
#line 1763 "sintatico.tab.c"
    break;

  case 70: /* OpUnario: MINUS  */
#line 208 "sintatico.y"
            { }
#line 1769 "sintatico.tab.c"
    break;

  case 71: /* OpUnario: NOT  */
#line 209 "sintatico.y"
          { }
#line 1775 "sintatico.tab.c"
    break;

  case 72: /* OpUnario: BITWISE_NOT  */
#line 210 "sintatico.y"
                  { }
#line 1781 "sintatico.tab.c"
    break;

  case 73: /* ExpressaoAtribuicao: ExpressaoCondicional  */
#line 213 "sintatico.y"
                                          { }
#line 1787 "sintatico.tab.c"
    break;

  case 74: /* ExpressaoAtribuicao: ExpressaoUnaria OpAtrib ExpressaoAtribuicao  */
#line 214 "sintatico.y"
                                                  { }
#line 1793 "sintatico.tab.c"
    break;

  case 75: /* ExpressaoCondicional: ExpressaoOrLogico AuxCondicional  */
#line 217 "sintatico.y"
                                                       { }
#line 1799 "sintatico.tab.c"
    break;

  case 76: /* AuxCondicional: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional  */
#line 220 "sintatico.y"
                                                                         { }
#line 1805 "sintatico.tab.c"
    break;

  case 77: /* AuxCondicional: %empty  */
#line 221 "sintatico.y"
      { }
#line 1811 "sintatico.tab.c"
    break;

  case 78: /* ExpressaoOrLogico: ExpressaoAndLogico  */
#line 223 "sintatico.y"
                                      { }
#line 1817 "sintatico.tab.c"
    break;

  case 79: /* ExpressaoOrLogico: ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico  */
#line 224 "sintatico.y"
                                                      { }
#line 1823 "sintatico.tab.c"
    break;

  case 80: /* ExpressaoAndLogico: ExpressaoOr  */
#line 227 "sintatico.y"
                                { }
#line 1829 "sintatico.tab.c"
    break;

  case 81: /* ExpressaoAndLogico: ExpressaoAndLogico LOGICAL_AND ExpressaoOr  */
#line 228 "sintatico.y"
                                                 { }
#line 1835 "sintatico.tab.c"
    break;

  case 82: /* ExpressaoOr: ExpressaoXor  */
#line 231 "sintatico.y"
                          { }
#line 1841 "sintatico.tab.c"
    break;

  case 83: /* ExpressaoOr: ExpressaoOr BITWISE_OR ExpressaoXor  */
#line 232 "sintatico.y"
                                          { }
#line 1847 "sintatico.tab.c"
    break;

  case 84: /* ExpressaoXor: ExpressaoAnd  */
#line 235 "sintatico.y"
                           { }
#line 1853 "sintatico.tab.c"
    break;

  case 85: /* ExpressaoXor: ExpressaoXor BITWISE_XOR ExpressaoAnd  */
#line 236 "sintatico.y"
                                            { }
#line 1859 "sintatico.tab.c"
    break;

  case 86: /* ExpressaoAnd: ExpressaoIgual  */
#line 239 "sintatico.y"
                             { }
#line 1865 "sintatico.tab.c"
    break;

  case 87: /* ExpressaoAnd: ExpressaoAnd BITWISE_AND ExpressaoIgual  */
#line 240 "sintatico.y"
                                              { }
#line 1871 "sintatico.tab.c"
    break;

  case 88: /* ExpressaoIgual: ExpressaoRelacional  */
#line 243 "sintatico.y"
                                    { }
#line 1877 "sintatico.tab.c"
    break;

  case 89: /* ExpressaoIgual: ExpressaoIgual EQUAL ExpressaoRelacional  */
#line 244 "sintatico.y"
                                               { }
#line 1883 "sintatico.tab.c"
    break;

  case 90: /* ExpressaoIgual: ExpressaoIgual NOT_EQUAL ExpressaoRelacional  */
#line 245 "sintatico.y"
                                                   { }
#line 1889 "sintatico.tab.c"
    break;

  case 91: /* ExpressaoRelacional: ExpressaoShift  */
#line 248 "sintatico.y"
                                    { }
#line 1895 "sintatico.tab.c"
    break;

  case 92: /* ExpressaoRelacional: ExpressaoRelacional OpRel ExpressaoShift  */
#line 249 "sintatico.y"
                                               { }
#line 1901 "sintatico.tab.c"
    break;

  case 93: /* ExpressaoShift: ExpressaoAditiva  */
#line 251 "sintatico.y"
                                 { }
#line 1907 "sintatico.tab.c"
    break;

  case 94: /* ExpressaoShift: ExpressaoShift R_SHIFT ExpressaoAditiva  */
#line 252 "sintatico.y"
                                              { }
#line 1913 "sintatico.tab.c"
    break;

  case 95: /* ExpressaoShift: ExpressaoShift L_SHIFT ExpressaoAditiva  */
#line 253 "sintatico.y"
                                              { }
#line 1919 "sintatico.tab.c"
    break;

  case 96: /* ExpressaoAditiva: ExpressaoMultiplicativa  */
#line 256 "sintatico.y"
                                          { }
#line 1925 "sintatico.tab.c"
    break;

  case 97: /* ExpressaoAditiva: ExpressaoAditiva PLUS ExpressaoMultiplicativa  */
#line 257 "sintatico.y"
                                                    { }
#line 1931 "sintatico.tab.c"
    break;

  case 98: /* ExpressaoAditiva: ExpressaoAditiva MINUS ExpressaoMultiplicativa  */
#line 258 "sintatico.y"
                                                     { }
#line 1937 "sintatico.tab.c"
    break;

  case 99: /* ExpressaoMultiplicativa: ExpressaoCast  */
#line 261 "sintatico.y"
                                       { }
#line 1943 "sintatico.tab.c"
    break;

  case 100: /* ExpressaoMultiplicativa: ExpressaoMultiplicativa OpMult ExpressaoCast  */
#line 262 "sintatico.y"
                                                   { }
#line 1949 "sintatico.tab.c"
    break;

  case 101: /* ExpressaoCast: ExpressaoUnaria  */
#line 265 "sintatico.y"
                               { }
#line 1955 "sintatico.tab.c"
    break;

  case 102: /* ExpressaoCast: L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast  */
#line 266 "sintatico.y"
                                                  { }
#line 1961 "sintatico.tab.c"
    break;

  case 103: /* ExpressaoUnaria: ExpressaoPosFixa  */
#line 269 "sintatico.y"
                                  { }
#line 1967 "sintatico.tab.c"
    break;

  case 104: /* ExpressaoUnaria: INC ExpressaoUnaria  */
#line 270 "sintatico.y"
                          { }
#line 1973 "sintatico.tab.c"
    break;

  case 105: /* ExpressaoUnaria: DEC ExpressaoUnaria  */
#line 271 "sintatico.y"
                          { }
#line 1979 "sintatico.tab.c"
    break;

  case 106: /* ExpressaoUnaria: OpUnario ExpressaoCast  */
#line 272 "sintatico.y"
                             { }
#line 1985 "sintatico.tab.c"
    break;

  case 107: /* ExpressaoPosFixa: ExpressaoPrimaria  */
#line 275 "sintatico.y"
                                    { }
#line 1991 "sintatico.tab.c"
    break;

  case 108: /* ExpressaoPosFixa: ExpressaoPosFixa AuxPosFixa  */
#line 276 "sintatico.y"
                                  { }
#line 1997 "sintatico.tab.c"
    break;

  case 109: /* AuxPosFixa: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET  */
#line 279 "sintatico.y"
                                                        { }
#line 2003 "sintatico.tab.c"
    break;

  case 110: /* AuxPosFixa: L_PAREN PulaExpressaoAtribuicao R_PAREN  */
#line 280 "sintatico.y"
                                              { }
#line 2009 "sintatico.tab.c"
    break;

  case 111: /* AuxPosFixa: INC  */
#line 281 "sintatico.y"
          { }
#line 2015 "sintatico.tab.c"
    break;

  case 112: /* AuxPosFixa: DEC  */
#line 282 "sintatico.y"
          { }
#line 2021 "sintatico.tab.c"
    break;

  case 113: /* PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula  */
#line 285 "sintatico.y"
                                                     { }
#line 2027 "sintatico.tab.c"
    break;

  case 114: /* PulaExpressaoAtribuicao: %empty  */
#line 286 "sintatico.y"
      { }
#line 2033 "sintatico.tab.c"
    break;

  case 115: /* AuxPula: COMMA ExpressaoAtribuicao AuxPula  */
#line 289 "sintatico.y"
                                           { }
#line 2039 "sintatico.tab.c"
    break;

  case 116: /* AuxPula: %empty  */
#line 290 "sintatico.y"
      { }
#line 2045 "sintatico.tab.c"
    break;

  case 117: /* ExpressaoPrimaria: ID  */
#line 293 "sintatico.y"
                      { }
#line 2051 "sintatico.tab.c"
    break;

  case 118: /* ExpressaoPrimaria: Numero  */
#line 294 "sintatico.y"
             { }
#line 2057 "sintatico.tab.c"
    break;

  case 119: /* ExpressaoPrimaria: CHARACTER  */
#line 295 "sintatico.y"
                { }
#line 2063 "sintatico.tab.c"
    break;

  case 120: /* ExpressaoPrimaria: STRING  */
#line 296 "sintatico.y"
             { }
#line 2069 "sintatico.tab.c"
    break;

  case 121: /* ExpressaoPrimaria: L_PAREN Expressao R_PAREN  */
#line 297 "sintatico.y"
                                { }
#line 2075 "sintatico.tab.c"
    break;

  case 122: /* Numero: NUM_INT  */
#line 300 "sintatico.y"
                { }
#line 2081 "sintatico.tab.c"
    break;

  case 123: /* Numero: NUM_HEXA  */
#line 301 "sintatico.y"
               { }
#line 2087 "sintatico.tab.c"
    break;

  case 124: /* Numero: NUM_OCTAL  */
#line 302 "sintatico.y"
                { }
#line 2093 "sintatico.tab.c"
    break;


#line 2097 "sintatico.tab.c"

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

#line 305 "sintatico.y"


void yyerror(void *s) {}

int main(int argc, char* argv[]) {
    yyparse();

    if (textBefore) printf("\n");
    if (erroAux) {

        if (yychar == 0 || yychar == MyEOF) {
            printf("error:syntax:%d:%d: expected declaration or statement at end of input", yylval.token.line, yylval.token.column);            
        } else {
            printf("error:syntax:%d:%d: %s", yylval.token.line, yylval.token.column, yylval.token.valor);
        }

        if (lineBuffer[0] == '\n') lineBuffer[0] = ' ';
        if (lineBuffer[strlen(lineBuffer) - 1] == '\n') lineBuffer[strlen(lineBuffer) - 1] = ' ';
        printf("\n%s\n", lineBuffer);
        for (int i = 0; i < yylval.token.column - 1; i++) printf(" ");
        printf("^");

    } else {
        printf("SUCCESSFUL COMPILATION.");
    }

    return 0;
}
