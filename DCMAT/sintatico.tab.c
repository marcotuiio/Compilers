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
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 211

#define H_VIEW_LO -6.500000
#define H_VIEW_HI 6.500000
#define V_VIEW_LO -3.500000
#define V_VIEW_HI 3.500000
#define FLOAT_PRECISION 6
#define INTEGRAL_STEPS_VALUE 1000
#define DRAW_AXIS true
#define ERASE_PLOT true
#define CONNECT_DOTS_OP false

extern int yylex();
void yyerror(void *s);

extern int yychar;
extern int myEof;

int erroAux = 0;
int semanticError = 0;

float h_view_lo = H_VIEW_LO;
float h_view_hi = H_VIEW_HI;
float v_view_lo = V_VIEW_LO;
float v_view_hi = V_VIEW_HI;
int float_precision = FLOAT_PRECISION;
int integral_steps_value = INTEGRAL_STEPS_VALUE;
bool draw_axis = DRAW_AXIS;
bool erase_plot = ERASE_PLOT;
bool connect_dots_op = CONNECT_DOTS_OP;

typedef struct node {
    int key;
    char *value;
    struct node *next;
} HashNode;

void showSettings();
void resetSettings();
void showAbout();

// int hash();
// void insertHash();
// int lookForValueInHash();
// void freeHash();

// void **myHashTable = NULL;


#line 128 "sintatico.tab.c"

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
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MULTIPLY = 5,                   /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 6,                     /* DIVIDE  */
  YYSYMBOL_POWER = 7,                      /* POWER  */
  YYSYMBOL_REMAINDER = 8,                  /* REMAINDER  */
  YYSYMBOL_ASSIGN = 9,                     /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 10,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 11,                     /* COMMA  */
  YYSYMBOL_COLON = 12,                     /* COLON  */
  YYSYMBOL_COLON_ASSIGN = 13,              /* COLON_ASSIGN  */
  YYSYMBOL_L_PAREN = 14,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 15,                   /* R_PAREN  */
  YYSYMBOL_L_SQUARE_BRACKET = 16,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 17,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_ABOUT = 18,                     /* ABOUT  */
  YYSYMBOL_ABS = 19,                       /* ABS  */
  YYSYMBOL_AXIS = 20,                      /* AXIS  */
  YYSYMBOL_CONNECT_DOTS = 21,              /* CONNECT_DOTS  */
  YYSYMBOL_COS = 22,                       /* COS  */
  YYSYMBOL_DETERMINANT = 23,               /* DETERMINANT  */
  YYSYMBOL_ERASE = 24,                     /* ERASE  */
  YYSYMBOL_EULER = 25,                     /* EULER  */
  YYSYMBOL_FLOAT = 26,                     /* FLOAT  */
  YYSYMBOL_H_VIEW = 27,                    /* H_VIEW  */
  YYSYMBOL_INTEGRAL_STEPS = 28,            /* INTEGRAL_STEPS  */
  YYSYMBOL_INTEGRATE = 29,                 /* INTEGRATE  */
  YYSYMBOL_LINEAR_SYSTEM = 30,             /* LINEAR_SYSTEM  */
  YYSYMBOL_MATRIX = 31,                    /* MATRIX  */
  YYSYMBOL_OFF = 32,                       /* OFF  */
  YYSYMBOL_ON = 33,                        /* ON  */
  YYSYMBOL_PI = 34,                        /* PI  */
  YYSYMBOL_PLOT = 35,                      /* PLOT  */
  YYSYMBOL_PRECISION = 36,                 /* PRECISION  */
  YYSYMBOL_QUIT = 37,                      /* QUIT  */
  YYSYMBOL_RESET = 38,                     /* RESET  */
  YYSYMBOL_RPN = 39,                       /* RPN  */
  YYSYMBOL_SEN = 40,                       /* SEN  */
  YYSYMBOL_SET = 41,                       /* SET  */
  YYSYMBOL_SETTINGS = 42,                  /* SETTINGS  */
  YYSYMBOL_SHOW = 43,                      /* SHOW  */
  YYSYMBOL_SOLVE = 44,                     /* SOLVE  */
  YYSYMBOL_SUM = 45,                       /* SUM  */
  YYSYMBOL_SYMBOLS = 46,                   /* SYMBOLS  */
  YYSYMBOL_TAN = 47,                       /* TAN  */
  YYSYMBOL_V_VIEW = 48,                    /* V_VIEW  */
  YYSYMBOL_VAR_X = 49,                     /* VAR_X  */
  YYSYMBOL_ID = 50,                        /* ID  */
  YYSYMBOL_NUM_INT = 51,                   /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 52,                 /* NUM_FLOAT  */
  YYSYMBOL_EOL = 53,                       /* EOL  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_S = 55,                         /* S  */
  YYSYMBOL_Comandos = 56,                  /* Comandos  */
  YYSYMBOL_Repet_Matrix = 57,              /* Repet_Matrix  */
  YYSYMBOL_Repet_Dimen = 58,               /* Repet_Dimen  */
  YYSYMBOL_Funcao = 59,                    /* Funcao  */
  YYSYMBOL_Expressao = 60,                 /* Expressao  */
  YYSYMBOL_OpUnario = 61,                  /* OpUnario  */
  YYSYMBOL_OpMult = 62,                    /* OpMult  */
  YYSYMBOL_ExpressaoAditiva = 63,          /* ExpressaoAditiva  */
  YYSYMBOL_ExpressaoMultiplicativa = 64,   /* ExpressaoMultiplicativa  */
  YYSYMBOL_ExpressaoUnaria = 65,           /* ExpressaoUnaria  */
  YYSYMBOL_ExpressaoPrimaria = 66          /* ExpressaoPrimaria  */
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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   122,   122,   123,   125,   126,   127,   135,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     167,   168,   170,   171,   173,   174,   175,   176,   178,   179,
     181,   182,   184,   185,   186,   187,   189,   190,   192,   193,
     195,   196,   198,   199,   200,   201,   204
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
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "POWER", "REMAINDER", "ASSIGN", "SEMICOLON",
  "COMMA", "COLON", "COLON_ASSIGN", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ABOUT", "ABS", "AXIS",
  "CONNECT_DOTS", "COS", "DETERMINANT", "ERASE", "EULER", "FLOAT",
  "H_VIEW", "INTEGRAL_STEPS", "INTEGRATE", "LINEAR_SYSTEM", "MATRIX",
  "OFF", "ON", "PI", "PLOT", "PRECISION", "QUIT", "RESET", "RPN", "SEN",
  "SET", "SETTINGS", "SHOW", "SOLVE", "SUM", "SYMBOLS", "TAN", "V_VIEW",
  "VAR_X", "ID", "NUM_INT", "NUM_FLOAT", "EOL", "$accept", "S", "Comandos",
  "Repet_Matrix", "Repet_Dimen", "Funcao", "Expressao", "OpUnario",
  "OpMult", "ExpressaoAditiva", "ExpressaoMultiplicativa",
  "ExpressaoUnaria", "ExpressaoPrimaria", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,    -5,    -7,    32,     9,   -24,    73,   -22,   -17,    37,
      15,  -137,    45,    19,  -137,    -6,    54,  -137,    62,    64,
      -3,     1,    41,    46,     7,    38,    74,     7,    80,    81,
      86,    88,    93,    55,  -137,    -2,  -137,  -137,    92,    90,
      94,    96,    97,    99,   100,  -137,   104,   106,   107,   109,
      10,    56,  -137,  -137,     7,  -137,  -137,  -137,  -137,  -137,
     108,    17,    75,    31,  -137,  -137,   112,     7,   111,  -137,
    -137,  -137,  -137,  -137,   113,   110,   115,    76,    77,     7,
       7,     7,     7,   117,  -137,  -137,  -137,  -137,   120,   121,
     122,   118,     7,  -137,    12,  -137,  -137,  -137,  -137,    12,
    -137,   119,     7,    83,    84,  -137,   126,   127,   124,   125,
     128,   129,  -137,  -137,  -137,  -137,  -137,   131,    31,  -137,
     132,   135,   134,   127,    62,    95,   133,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,   101,   137,   136,   127,   138,   141,
     138,   145,  -137,   140,   142,     7,   143,  -137,   105,   148,
     146,   152,   127,  -137,   153,  -137,   147,  -137,   138,  -137
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,    22,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    38,    53,    52,    54,    55,
       0,     0,    39,    46,    48,    50,     0,     0,     0,    19,
       4,    26,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     8,    29,    28,     0,     0,
       0,     0,     0,    51,     0,    42,    43,    45,    44,     0,
      15,     0,     0,     0,     0,    23,     0,    31,     0,     0,
       0,     0,    11,    12,    13,    27,    56,     0,    47,    49,
       0,     0,     0,    31,     0,     0,     0,    37,    35,    34,
      36,     6,    14,     7,     0,     0,     0,    31,    33,     0,
      33,     0,    30,     0,     0,     0,     0,    16,     0,     0,
       0,     0,    31,    18,     0,    24,     0,    17,    33,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,  -120,  -136,    24,   -27,   103,  -137,  -137,
      72,    68,   114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,   126,   144,    44,    60,    61,    99,    62,
      63,    64,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    52,    53,   135,   146,    14,    31,    15,    76,    28,
      52,    53,    54,    32,    75,    52,    53,   142,    19,    17,
      29,    54,   159,    18,    30,    34,    54,    91,    35,    46,
      47,    54,   156,    48,    49,    55,    95,    96,    97,    98,
     101,    16,    88,    89,    55,    36,    38,    56,    57,    58,
      59,    33,   108,   109,   110,   111,    56,    57,    58,    59,
       1,    56,    57,    58,    59,   117,    56,    57,    58,    59,
      39,     2,    37,     3,    45,   121,    50,     4,    52,    53,
       5,    40,    51,     6,    41,     7,     8,     9,    67,    66,
      69,    70,    10,    20,    21,    11,    71,    22,    72,    23,
      24,    25,    42,    73,    77,    74,    78,    90,    79,    43,
      80,    81,    26,    82,    84,    83,    85,    86,   150,    87,
      92,    27,   100,   102,   103,   105,   104,   112,   106,   107,
     113,   114,   115,   116,   120,   122,   123,   124,   125,   127,
     128,   131,   132,   129,   130,   133,   134,   137,   136,   143,
     138,   141,   145,   139,   140,   147,   148,   152,   153,   149,
     151,   154,   155,   157,   158,    94,   118,   119,     0,     0,
       0,     0,     0,     0,     0,    93
};

static const yytype_int16 yycheck[] =
{
      27,     3,     4,   123,   140,    10,    23,    14,    35,    31,
       3,     4,    14,    30,    16,     3,     4,   137,    42,    10,
      42,    14,   158,    14,    46,    10,    14,    54,    13,    32,
      33,    14,   152,    32,    33,    37,     5,     6,     7,     8,
      67,     9,    32,    33,    37,     0,    52,    49,    50,    51,
      52,    14,    79,    80,    81,    82,    49,    50,    51,    52,
      18,    49,    50,    51,    52,    92,    49,    50,    51,    52,
      16,    29,    53,    31,    10,   102,    35,    35,     3,     4,
      38,    19,    36,    41,    22,    43,    44,    45,    14,    51,
      10,    10,    50,    20,    21,    53,    10,    24,    10,    26,
      27,    28,    40,    10,    12,    50,    16,    51,    14,    47,
      14,    14,    39,    14,    10,    15,    10,    10,   145,    10,
      12,    48,    10,    12,    11,    10,    16,    10,    52,    52,
      10,    10,    10,    15,    15,    52,    52,    11,    11,    15,
      15,    10,    10,    15,    15,    10,    12,    52,   124,    11,
      17,    15,    11,    52,    17,    10,    16,    52,    10,    17,
      17,    15,    10,    10,    17,    62,    94,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    29,    31,    35,    38,    41,    43,    44,    45,
      50,    53,    55,    56,    10,    14,     9,    10,    14,    42,
      20,    21,    24,    26,    27,    28,    39,    48,    31,    42,
      46,    23,    30,    14,    10,    13,     0,    53,    52,    16,
      19,    22,    40,    47,    59,    10,    32,    33,    32,    33,
      35,    36,     3,     4,    14,    37,    49,    50,    51,    52,
      60,    61,    63,    64,    65,    66,    51,    14,    60,    10,
      10,    10,    10,    10,    50,    16,    60,    12,    16,    14,
      14,    14,    14,    15,    10,    10,    10,    10,    32,    33,
      51,    60,    12,    66,    61,     5,     6,     7,     8,    62,
      10,    60,    12,    11,    16,    10,    52,    52,    60,    60,
      60,    60,    10,    10,    10,    10,    15,    60,    64,    65,
      15,    60,    52,    52,    11,    11,    57,    15,    15,    15,
      15,    10,    10,    10,    12,    57,    59,    52,    17,    52,
      17,    15,    57,    11,    58,    11,    58,    10,    16,    17,
      60,    17,    52,    10,    15,    10,    57,    10,    17,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     3,     6,     6,     4,     4,
       2,     5,     5,     5,     6,     4,     9,    11,    10,     3,
       3,     3,     2,     4,    10,     2,     3,     5,     4,     4,
       3,     0,     6,     0,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     2,     1,     1,     1,     1,     3
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
  case 2: /* S: Comandos EOL  */
#line 122 "sintatico.y"
                { return 0; }
#line 1278 "sintatico.tab.c"
    break;

  case 3: /* S: EOL  */
#line 123 "sintatico.y"
          { return 0; }
#line 1284 "sintatico.tab.c"
    break;

  case 4: /* Comandos: SHOW SETTINGS SEMICOLON  */
#line 125 "sintatico.y"
                                  { showSettings(); }
#line 1290 "sintatico.tab.c"
    break;

  case 5: /* Comandos: RESET SETTINGS SEMICOLON  */
#line 126 "sintatico.y"
                               { resetSettings(); }
#line 1296 "sintatico.tab.c"
    break;

  case 6: /* Comandos: SET H_VIEW Expressao COLON Expressao SEMICOLON  */
#line 127 "sintatico.y"
                                                     { 
        // if ($3 > $5) {
        //     printf("\nERROR: h_view_lo must be less than h_view_hi\n");
        // } else {
        //     h_view_lo = $3;
        //     h_view_hi = $5;
        // }
    }
#line 1309 "sintatico.tab.c"
    break;

  case 7: /* Comandos: SET V_VIEW Expressao COLON Expressao SEMICOLON  */
#line 135 "sintatico.y"
                                                     {
        // if ($3 > $5) {
        //     printf("\nERROR: v_view_lo must be less than v_view_hi\n");
        // } else {
        //     v_view_lo = $3;
        //     v_view_hi = $5;
        // }
    }
#line 1322 "sintatico.tab.c"
    break;

  case 8: /* Comandos: SET AXIS ON SEMICOLON  */
#line 143 "sintatico.y"
                            { }
#line 1328 "sintatico.tab.c"
    break;

  case 9: /* Comandos: SET AXIS OFF SEMICOLON  */
#line 144 "sintatico.y"
                             { }
#line 1334 "sintatico.tab.c"
    break;

  case 10: /* Comandos: PLOT SEMICOLON  */
#line 145 "sintatico.y"
                     { }
#line 1340 "sintatico.tab.c"
    break;

  case 11: /* Comandos: PLOT L_PAREN Funcao R_PAREN SEMICOLON  */
#line 146 "sintatico.y"
                                            { }
#line 1346 "sintatico.tab.c"
    break;

  case 12: /* Comandos: SET ERASE PLOT OFF SEMICOLON  */
#line 147 "sintatico.y"
                                   { }
#line 1352 "sintatico.tab.c"
    break;

  case 13: /* Comandos: SET ERASE PLOT ON SEMICOLON  */
#line 148 "sintatico.y"
                                  { }
#line 1358 "sintatico.tab.c"
    break;

  case 14: /* Comandos: SET RPN L_PAREN Expressao R_PAREN SEMICOLON  */
#line 149 "sintatico.y"
                                                  { }
#line 1364 "sintatico.tab.c"
    break;

  case 15: /* Comandos: SET INTEGRAL_STEPS NUM_INT SEMICOLON  */
#line 150 "sintatico.y"
                                           { }
#line 1370 "sintatico.tab.c"
    break;

  case 16: /* Comandos: INTEGRATE L_PAREN NUM_FLOAT COLON NUM_FLOAT COMMA Funcao R_PAREN SEMICOLON  */
#line 151 "sintatico.y"
                                                                                 { }
#line 1376 "sintatico.tab.c"
    break;

  case 17: /* Comandos: SUM L_PAREN ID COMMA NUM_FLOAT COLON NUM_FLOAT COMMA Expressao R_PAREN SEMICOLON  */
#line 152 "sintatico.y"
                                                                                       { }
#line 1382 "sintatico.tab.c"
    break;

  case 18: /* Comandos: MATRIX ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON  */
#line 153 "sintatico.y"
                                                                                                                                     { }
#line 1388 "sintatico.tab.c"
    break;

  case 19: /* Comandos: SHOW MATRIX SEMICOLON  */
#line 154 "sintatico.y"
                            { }
#line 1394 "sintatico.tab.c"
    break;

  case 20: /* Comandos: SOLVE DETERMINANT SEMICOLON  */
#line 155 "sintatico.y"
                                  { }
#line 1400 "sintatico.tab.c"
    break;

  case 21: /* Comandos: SOLVE LINEAR_SYSTEM SEMICOLON  */
#line 156 "sintatico.y"
                                    { }
#line 1406 "sintatico.tab.c"
    break;

  case 22: /* Comandos: ABOUT SEMICOLON  */
#line 157 "sintatico.y"
                      { showAbout(); }
#line 1412 "sintatico.tab.c"
    break;

  case 23: /* Comandos: ID COLON_ASSIGN Expressao SEMICOLON  */
#line 158 "sintatico.y"
                                          { }
#line 1418 "sintatico.tab.c"
    break;

  case 24: /* Comandos: ID COLON_ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON  */
#line 159 "sintatico.y"
                                                                                                                                       { }
#line 1424 "sintatico.tab.c"
    break;

  case 25: /* Comandos: ID SEMICOLON  */
#line 160 "sintatico.y"
                   { }
#line 1430 "sintatico.tab.c"
    break;

  case 26: /* Comandos: SHOW SYMBOLS SEMICOLON  */
#line 161 "sintatico.y"
                             { }
#line 1436 "sintatico.tab.c"
    break;

  case 27: /* Comandos: SET FLOAT PRECISION NUM_INT SEMICOLON  */
#line 162 "sintatico.y"
                                            { }
#line 1442 "sintatico.tab.c"
    break;

  case 28: /* Comandos: SET CONNECT_DOTS ON SEMICOLON  */
#line 163 "sintatico.y"
                                    { }
#line 1448 "sintatico.tab.c"
    break;

  case 29: /* Comandos: SET CONNECT_DOTS OFF SEMICOLON  */
#line 164 "sintatico.y"
                                     { }
#line 1454 "sintatico.tab.c"
    break;

  case 30: /* Repet_Matrix: COMMA NUM_FLOAT Repet_Matrix  */
#line 167 "sintatico.y"
                                           { }
#line 1460 "sintatico.tab.c"
    break;

  case 31: /* Repet_Matrix: %empty  */
#line 168 "sintatico.y"
      { }
#line 1466 "sintatico.tab.c"
    break;

  case 32: /* Repet_Dimen: COMMA L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen  */
#line 170 "sintatico.y"
                                                                                        { }
#line 1472 "sintatico.tab.c"
    break;

  case 33: /* Repet_Dimen: %empty  */
#line 171 "sintatico.y"
      { }
#line 1478 "sintatico.tab.c"
    break;

  case 34: /* Funcao: SEN L_PAREN Expressao R_PAREN  */
#line 173 "sintatico.y"
                                      { }
#line 1484 "sintatico.tab.c"
    break;

  case 35: /* Funcao: COS L_PAREN Expressao R_PAREN  */
#line 174 "sintatico.y"
                                    { }
#line 1490 "sintatico.tab.c"
    break;

  case 36: /* Funcao: TAN L_PAREN Expressao R_PAREN  */
#line 175 "sintatico.y"
                                    { }
#line 1496 "sintatico.tab.c"
    break;

  case 37: /* Funcao: ABS L_PAREN Expressao R_PAREN  */
#line 176 "sintatico.y"
                                    { }
#line 1502 "sintatico.tab.c"
    break;

  case 38: /* Expressao: QUIT  */
#line 178 "sintatico.y"
                { return QUIT; }
#line 1508 "sintatico.tab.c"
    break;

  case 39: /* Expressao: ExpressaoAditiva  */
#line 179 "sintatico.y"
                       { }
#line 1514 "sintatico.tab.c"
    break;

  case 40: /* OpUnario: PLUS  */
#line 181 "sintatico.y"
               { }
#line 1520 "sintatico.tab.c"
    break;

  case 41: /* OpUnario: MINUS  */
#line 182 "sintatico.y"
            { }
#line 1526 "sintatico.tab.c"
    break;

  case 42: /* OpMult: MULTIPLY  */
#line 184 "sintatico.y"
                 { }
#line 1532 "sintatico.tab.c"
    break;

  case 43: /* OpMult: DIVIDE  */
#line 185 "sintatico.y"
             { }
#line 1538 "sintatico.tab.c"
    break;

  case 44: /* OpMult: REMAINDER  */
#line 186 "sintatico.y"
                { }
#line 1544 "sintatico.tab.c"
    break;

  case 45: /* OpMult: POWER  */
#line 187 "sintatico.y"
            { }
#line 1550 "sintatico.tab.c"
    break;

  case 46: /* ExpressaoAditiva: ExpressaoMultiplicativa  */
#line 189 "sintatico.y"
                                          { }
#line 1556 "sintatico.tab.c"
    break;

  case 47: /* ExpressaoAditiva: ExpressaoAditiva OpUnario ExpressaoMultiplicativa  */
#line 190 "sintatico.y"
                                                        { }
#line 1562 "sintatico.tab.c"
    break;

  case 48: /* ExpressaoMultiplicativa: ExpressaoUnaria  */
#line 192 "sintatico.y"
                                         { }
#line 1568 "sintatico.tab.c"
    break;

  case 49: /* ExpressaoMultiplicativa: ExpressaoMultiplicativa OpMult ExpressaoUnaria  */
#line 193 "sintatico.y"
                                                     { }
#line 1574 "sintatico.tab.c"
    break;

  case 50: /* ExpressaoUnaria: ExpressaoPrimaria  */
#line 195 "sintatico.y"
                                   { }
#line 1580 "sintatico.tab.c"
    break;

  case 51: /* ExpressaoUnaria: OpUnario ExpressaoPrimaria  */
#line 196 "sintatico.y"
                                 { }
#line 1586 "sintatico.tab.c"
    break;

  case 52: /* ExpressaoPrimaria: ID  */
#line 198 "sintatico.y"
                      { }
#line 1592 "sintatico.tab.c"
    break;

  case 53: /* ExpressaoPrimaria: VAR_X  */
#line 199 "sintatico.y"
            { }
#line 1598 "sintatico.tab.c"
    break;

  case 54: /* ExpressaoPrimaria: NUM_INT  */
#line 200 "sintatico.y"
              { }
#line 1604 "sintatico.tab.c"
    break;

  case 55: /* ExpressaoPrimaria: NUM_FLOAT  */
#line 201 "sintatico.y"
                { }
#line 1610 "sintatico.tab.c"
    break;

  case 56: /* ExpressaoPrimaria: L_PAREN Expressao R_PAREN  */
#line 204 "sintatico.y"
                                { }
#line 1616 "sintatico.tab.c"
    break;


#line 1620 "sintatico.tab.c"

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

#line 206 "sintatico.y"


void yyerror(void *s) {
    if (yychar = EOL) {
        printf("\nSYNTAX ERROR: Incomplete Command\n\n");
        return;
    }
    printf("\nSYNTAX ERROR: [%d]\n\n", yychar);
    
}

void showSettings() {
    printf("\nh_view_lo: %.6f\n", h_view_lo);
    printf("h_view_hi: %.6f\n", h_view_hi);
    printf("v_view_lo: %.6f\n", v_view_lo);
    printf("v_view_hi: %.6f\n", v_view_hi);
    printf("float_precision: %d\n", float_precision);
    printf("integral_steps_value: %d\n", integral_steps_value);
    printf("\nDraw Axis: %s\n", draw_axis ? "ON" : "OFF");
    printf("Erase Plot: %s\n", erase_plot ? "ON" : "OFF");
    printf("Connect Dots: %s\n\n", connect_dots_op ? "ON" : "OFF");
}

void resetSettings() {
    h_view_lo = H_VIEW_LO;
    h_view_hi = H_VIEW_HI;
    v_view_lo = V_VIEW_LO;
    v_view_hi = V_VIEW_HI;
    float_precision = FLOAT_PRECISION;
    integral_steps_value = INTEGRAL_STEPS_VALUE;
    draw_axis = DRAW_AXIS;
    erase_plot = ERASE_PLOT;
    connect_dots_op = CONNECT_DOTS_OP;
}

void showAbout() {
    printf("\n+-------------------------------------------------------+\n");
    printf("|                                                       |\n");
    printf("|              Marco Tulio Alves de Barros              |\n");
    printf("|                     202100560105                      |\n");
    printf("|                                                       |\n");
    printf("+-------------------------------------------------------+\n\n");
}   

/* int hash() {
    int hash = 0;
    for (int i = 0; i < strlen(yylval.token.valor); i++)
        hash += yylval.token.valor[i];
    return hash % HASH_SIZE;
}

void insertHash() {
    int index = hash(yylval.token.valor);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->key = currentType;
    aux->value = calloc(strlen(yylval.token.valor) + 1, sizeof(char));
    strcpy(aux->value, yylval.token.valor);

    HashNode *head = (HashNode *) myHashTable[index];
    if (!head) {
        myHashTable[index] = aux;
    } else {
        while (head->next) 
            head = head->next;
        head->next = aux;
    }

}

int lookForValueInHash() {
    if (!myHashTable) return 0;
    int index = hash(yylval.token.valor);
    int ocorrencias = 0;
    HashNode *head = (HashNode *) myHashTable[index];

    while (head) {
        if (!strcmp(yylval.token.valor, head->value)) { // existe outro daquele identificador na hash
            ocorrencias++;
            if (ocorrencias == 1) continue;  // se for o primeiro, continua 
            if (currentType == head->key) {  // se for do mesmo tipo
                if (textBefore) printf("\n");
                printf("%d: identifier '%s' already declared", yylval.token.line, yylval.token.valor);
                semanticError = 1;
                textBefore = 1;
                return 1;

            } else {  // se for de tipo diferente
                if (textBefore) printf("\n");
                printf("%d: redefinition of identifier '%s'", yylval.token.line, yylval.token.valor);
                semanticError = 1;
                textBefore = 1;
                return 1;
            }
        }
        head = head->next;
    }
    return 0;
}

void freeHash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *head = myHashTable[i];
        while (head) {
            HashNode *aux = head->next;
            if (head->value) 
                free(head->value);
            free(head);
            head = aux;
        }
        myHashTable[i] = NULL; 
    }
} */

int main(int argc, char *argv[]) {
    while (true) {
        printf(">");
        if (yyparse() == QUIT) break;
    }
    return 0;
}
