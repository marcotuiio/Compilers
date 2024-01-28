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
#include "ast.h"
#include "hash.h"

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

float h_view_lo = H_VIEW_LO;
float h_view_hi = H_VIEW_HI;
float v_view_lo = V_VIEW_LO;
float v_view_hi = V_VIEW_HI;
int float_precision = FLOAT_PRECISION;
int integral_steps_value = INTEGRAL_STEPS_VALUE;
bool draw_axis = DRAW_AXIS;
bool erase_plot = ERASE_PLOT;
bool connect_dots_op = CONNECT_DOTS_OP;

void **myHashTable = NULL;

void showSettings();
void resetSettings();
void showAbout();



#line 114 "sintatico.tab.c"

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
  YYSYMBOL_OpUnario = 60,                  /* OpUnario  */
  YYSYMBOL_OpMult = 61,                    /* OpMult  */
  YYSYMBOL_Expressao = 62,                 /* Expressao  */
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
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

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
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   118,   140,   142,   143,   144,   153,   162,
     163,   164,   165,   166,   167,   168,   169,   177,   208,   228,
     229,   230,   231,   232,   233,   242,   245,   254,   255,   263,
     264,   265,   267,   268,   270,   271,   273,   277,   281,   285,
     290,   291,   293,   294,   295,   296,   298,   303,   304,   309,
     310,   315,   316,   321,   325,   329,   333,   337,   341,   345,
     348
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
  "Repet_Matrix", "Repet_Dimen", "Funcao", "OpUnario", "OpMult",
  "Expressao", "ExpressaoAditiva", "ExpressaoMultiplicativa",
  "ExpressaoUnaria", "ExpressaoPrimaria", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      57,  -144,  -144,   129,    -2,     0,     7,  -144,    15,    24,
    -144,    16,  -144,    13,    35,   -17,   -14,   -11,    45,    54,
    -144,    27,  -144,  -144,  -144,    70,     4,  -144,   163,    25,
      39,   151,  -144,  -144,  -144,    21,  -144,   129,   129,   129,
      65,  -144,   129,    75,   129,    40,    88,    52,    53,   129,
     129,    76,   129,    83,    86,    89,    93,   101,    67,   129,
    -144,   115,  -144,  -144,  -144,  -144,   129,  -144,  -144,  -144,
    -144,   129,  -144,    43,    49,   116,   125,    59,  -144,    62,
     126,   132,   134,   135,   106,   129,   138,   136,   129,   140,
    -144,  -144,  -144,  -144,  -144,   111,   110,   137,   150,   151,
    -144,  -144,  -144,   129,   109,   158,  -144,  -144,  -144,  -144,
    -144,   160,   161,   162,   129,  -144,   159,   129,   129,  -144,
     121,  -144,   164,   172,  -144,  -144,  -144,  -144,   174,   176,
     177,   178,   172,   129,   139,   175,  -144,  -144,  -144,   129,
     179,   112,   172,   182,   183,   182,   185,  -144,   173,   181,
     129,   184,  -144,   147,   190,   120,   192,   172,  -144,   194,
    -144,   188,  -144,   182,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    40,    41,     0,     0,     0,     0,    58,     0,     0,
      57,     0,    31,     0,     0,     0,     0,     0,     0,     0,
      54,    53,    55,    56,     4,     0,     0,    60,     0,     0,
      46,    47,    49,    51,    53,     0,    23,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     1,     2,    52,     3,     0,    42,    43,    45,
      44,     0,    59,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     5,    27,    21,    22,     0,     0,     0,     0,    48,
      50,    39,    37,     0,     0,     0,    36,    10,     9,    30,
      29,     0,     0,     0,     0,    16,     0,     0,     0,    38,
       0,    24,     0,    33,    12,    13,    14,    28,     0,     0,
       0,     0,    33,     0,     0,     0,     7,    15,     8,     0,
       0,     0,    33,    35,     0,    35,     0,    32,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    33,    19,     0,
      25,     0,    18,    35,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -119,  -143,  -144,   -29,  -144,   -34,    -3,
     141,   145,   180
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,   135,   149,    27,    28,    71,    29,    30,
      31,    32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    66,   151,    45,    46,    75,    66,    47,    36,    48,
      49,    50,    56,   140,    37,    86,    87,    53,    89,    57,
     164,    38,    51,   147,     1,     2,    41,    98,    54,    39,
      42,    52,    55,    40,    73,    74,    72,    60,   161,    77,
      61,    79,     1,     2,    66,    66,     1,     2,    66,    44,
      66,   113,     1,     2,   116,    43,    96,    63,   101,    58,
       1,     2,     1,     2,   102,     1,     2,    66,    59,   122,
      62,     3,    80,    81,   105,     4,     5,   106,    65,     6,
     128,    76,     7,   130,   131,    78,     8,    84,     9,    85,
      88,    10,    11,    90,    12,    13,    91,    14,    15,    92,
      16,    17,    18,    93,    19,   144,    20,    21,    22,    23,
      24,    94,    66,     1,     2,     1,     2,    95,     1,     2,
      82,    83,   118,     1,     2,   119,    66,   146,   103,     3,
     141,    97,     1,     2,     5,   159,   107,     6,   111,   112,
       7,   104,   108,     3,   109,   110,   115,   155,     5,    10,
     114,     6,   117,   120,     7,    14,    67,    68,    69,    70,
     121,   123,    19,    10,    20,    34,    22,    23,   124,    14,
     125,   126,   127,   132,   129,   133,    19,     3,    20,    34,
      22,    23,     5,   134,   136,     6,   137,   138,     7,   153,
     139,   142,   143,   148,   150,   152,   145,    10,   154,   157,
     158,   156,   160,    14,   162,   163,     0,    99,    64,     0,
      19,     0,    20,    34,    22,    23,   100
};

static const yytype_int16 yycheck[] =
{
       3,    30,   145,    20,    21,    39,    35,    24,    10,    26,
      27,    28,    23,   132,    14,    49,    50,    31,    52,    30,
     163,    14,    39,   142,     3,     4,    10,    61,    42,    14,
      14,    48,    46,     9,    37,    38,    15,    10,   157,    42,
      13,    44,     3,     4,    73,    74,     3,     4,    77,    14,
      79,    85,     3,     4,    88,    42,    59,    53,    15,    14,
       3,     4,     3,     4,    15,     3,     4,    96,    14,   103,
       0,    14,    32,    33,    15,    18,    19,    15,    53,    22,
     114,    16,    25,   117,   118,    10,    29,    35,    31,    36,
      14,    34,    35,    10,    37,    38,    10,    40,    41,    10,
      43,    44,    45,    10,    47,   139,    49,    50,    51,    52,
      53,    10,   141,     3,     4,     3,     4,    50,     3,     4,
      32,    33,    11,     3,     4,    15,   155,    15,    12,    14,
     133,    16,     3,     4,    19,    15,    10,    22,    32,    33,
      25,    16,    10,    14,    10,    10,    10,   150,    19,    34,
      12,    22,    12,    16,    25,    40,     5,     6,     7,     8,
      10,    52,    47,    34,    49,    50,    51,    52,    10,    40,
      10,    10,    10,    52,    15,    11,    47,    14,    49,    50,
      51,    52,    19,    11,    10,    22,    10,    10,    25,    16,
      12,    52,    17,    11,    11,    10,    17,    34,    17,    52,
      10,    17,    10,    40,    10,    17,    -1,    66,    28,    -1,
      47,    -1,    49,    50,    51,    52,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    14,    18,    19,    22,    25,    29,    31,
      34,    35,    37,    38,    40,    41,    43,    44,    45,    47,
      49,    50,    51,    52,    53,    55,    56,    59,    60,    62,
      63,    64,    65,    66,    50,    63,    10,    14,    14,    14,
       9,    10,    14,    42,    14,    20,    21,    24,    26,    27,
      28,    39,    48,    31,    42,    46,    23,    30,    14,    14,
      10,    13,     0,    53,    66,    53,    60,     5,     6,     7,
       8,    61,    15,    63,    63,    62,    16,    63,    10,    63,
      32,    33,    32,    33,    35,    36,    62,    62,    14,    62,
      10,    10,    10,    10,    10,    50,    63,    16,    62,    64,
      65,    15,    15,    12,    16,    15,    15,    10,    10,    10,
      10,    32,    33,    62,    12,    10,    62,    12,    11,    15,
      16,    10,    62,    52,    10,    10,    10,    10,    62,    15,
      62,    62,    52,    11,    11,    57,    10,    10,    10,    12,
      57,    63,    52,    17,    62,    17,    15,    57,    11,    58,
      11,    58,    10,    16,    17,    63,    17,    52,    10,    15,
      10,    57,    10,    17,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     3,     3,     6,     6,     4,
       4,     2,     5,     5,     5,     6,     4,     9,    11,    10,
       3,     3,     3,     2,     4,    10,     2,     3,     5,     4,
       4,     1,     3,     0,     6,     0,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     3,
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
#line 117 "sintatico.y"
                { printf(">"); return 0; }
#line 1278 "sintatico.tab.c"
    break;

  case 3: /* S: Expressao EOL  */
#line 118 "sintatico.y"
                    {
        if ((yyvsp[-1].result)) {
            switch ((yyvsp[-1].result)->type) {
                case NUM_INT:
                    printf("\n%d\n\n", (int) (yyvsp[-1].result)->r_float);
                    break;
                case NUM_FLOAT:
                    printf("\n%f\n\n", (yyvsp[-1].result)->r_float);
                    break;
                case ID:
                    printf("\n%s\n\n", (yyvsp[-1].result)->r_string);
                    break;
                default:
                    printf("\nERROR: Invalid Expression\n\n");
                    break;
            }
        } else {
            printf("\n\n");
        }
        printf(">");
        return 0;   
    }
#line 1305 "sintatico.tab.c"
    break;

  case 4: /* S: EOL  */
#line 140 "sintatico.y"
          { printf(">"); return 0; }
#line 1311 "sintatico.tab.c"
    break;

  case 5: /* Comandos: SHOW SETTINGS SEMICOLON  */
#line 142 "sintatico.y"
                                  { showSettings(); }
#line 1317 "sintatico.tab.c"
    break;

  case 6: /* Comandos: RESET SETTINGS SEMICOLON  */
#line 143 "sintatico.y"
                               { resetSettings(); }
#line 1323 "sintatico.tab.c"
    break;

  case 7: /* Comandos: SET H_VIEW Expressao COLON Expressao SEMICOLON  */
#line 144 "sintatico.y"
                                                     { 
        if ((yyvsp[-3].result)->r_float > (yyvsp[-1].result)->r_float) {
            printf("\nERROR: h_view_lo must be less than h_view_hi\n\n");
            return 0;
        } else {
            h_view_lo = (yyvsp[-3].result)->r_float;
            h_view_hi = (yyvsp[-1].result)->r_float;
        }
    }
#line 1337 "sintatico.tab.c"
    break;

  case 8: /* Comandos: SET V_VIEW Expressao COLON Expressao SEMICOLON  */
#line 153 "sintatico.y"
                                                     {
        if ((yyvsp[-3].result)->r_float > (yyvsp[-1].result)->r_float) {
            printf("\nERROR: v_view_lo must be less than v_view_hi\n\n");
            return 0;
        } else {
            v_view_lo = (yyvsp[-3].result)->r_float;
            v_view_hi = (yyvsp[-1].result)->r_float;
        }
    }
#line 1351 "sintatico.tab.c"
    break;

  case 9: /* Comandos: SET AXIS ON SEMICOLON  */
#line 162 "sintatico.y"
                            { draw_axis = true; }
#line 1357 "sintatico.tab.c"
    break;

  case 10: /* Comandos: SET AXIS OFF SEMICOLON  */
#line 163 "sintatico.y"
                             { draw_axis = false; }
#line 1363 "sintatico.tab.c"
    break;

  case 11: /* Comandos: PLOT SEMICOLON  */
#line 164 "sintatico.y"
                     { }
#line 1369 "sintatico.tab.c"
    break;

  case 12: /* Comandos: PLOT L_PAREN ExpressaoAditiva R_PAREN SEMICOLON  */
#line 165 "sintatico.y"
                                                      { }
#line 1375 "sintatico.tab.c"
    break;

  case 13: /* Comandos: SET ERASE PLOT OFF SEMICOLON  */
#line 166 "sintatico.y"
                                   { erase_plot = false; }
#line 1381 "sintatico.tab.c"
    break;

  case 14: /* Comandos: SET ERASE PLOT ON SEMICOLON  */
#line 167 "sintatico.y"
                                  { erase_plot = true; }
#line 1387 "sintatico.tab.c"
    break;

  case 15: /* Comandos: SET RPN L_PAREN Expressao R_PAREN SEMICOLON  */
#line 168 "sintatico.y"
                                                  { }
#line 1393 "sintatico.tab.c"
    break;

  case 16: /* Comandos: SET INTEGRAL_STEPS Expressao SEMICOLON  */
#line 169 "sintatico.y"
                                             { 
        if ((int) (yyvsp[-1].result)->r_float < 1) {
            printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
            return 0;
        } else {
            integral_steps_value = (int) (yyvsp[-1].result)->r_float;
        }
    }
#line 1406 "sintatico.tab.c"
    break;

  case 17: /* Comandos: INTEGRATE L_PAREN Expressao COLON Expressao COMMA ExpressaoAditiva R_PAREN SEMICOLON  */
#line 177 "sintatico.y"
                                                                                           {
        if (!(yyvsp[-6].result) || !(yyvsp[-4].result)) {
            printf("\n\n");
            return 0;
        }

        if ((yyvsp[-6].result)->r_float > (yyvsp[-4].result)->r_float) {
            printf("\nERROR: integral lower limit must be smaller than upper limit\n\n");
            return 0;
        
        } else {
            float integral = 0;
            float step = ((yyvsp[-4].result)->r_float - (yyvsp[-6].result)->r_float) / integral_steps_value;
            ResultExpression *integrand = NULL;
            
            HashNode *xVar = getIdentifierNode(myHashTable, "x");
            xVar->valueId = (yyvsp[-6].result)->r_float;

            for (int i = 0; i < integral_steps_value; i++) {
                integrand = evalExpression((yyvsp[-2].expr), myHashTable);
                if (!integrand) {
                    printf("\n\n");
                    return 0;
                }
                integral += integrand->r_float * step;
                // printf("x %f funcValue %f e integral %f\n", xVar->valueId, integrand->r_float, integral);
                xVar->valueId = xVar->valueId + step;
            }
            printf("\n%f\n\n", integral);
        }
    }
#line 1442 "sintatico.tab.c"
    break;

  case 18: /* Comandos: SUM L_PAREN ID COMMA Expressao COLON Expressao COMMA ExpressaoAditiva R_PAREN SEMICOLON  */
#line 208 "sintatico.y"
                                                                                              {
        float sum = 0;
        insertHash(myHashTable, (yyvsp[-8].value), (yyvsp[-6].result)->r_float, NUM_FLOAT);
        ResultExpression *summand = NULL;
        
        HashNode *node = getIdentifierNode(myHashTable, (yyvsp[-8].value));

        for (int i = (int) node->valueId; i <= (int) (yyvsp[-4].result)->r_float; i++) {
            summand = evalExpression((yyvsp[-2].expr), myHashTable);
            if (!summand) {
                printf("\n\n");
                removeNode(myHashTable, (yyvsp[-8].value));
                return 0;
            }
            sum += summand->r_float;
            node->valueId++;
        }
        printf("\n%f\n\n", sum);
        removeNode(myHashTable, (yyvsp[-8].value));
    }
#line 1467 "sintatico.tab.c"
    break;

  case 19: /* Comandos: MATRIX ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON  */
#line 228 "sintatico.y"
                                                                                                                                     { }
#line 1473 "sintatico.tab.c"
    break;

  case 20: /* Comandos: SHOW MATRIX SEMICOLON  */
#line 229 "sintatico.y"
                            { }
#line 1479 "sintatico.tab.c"
    break;

  case 21: /* Comandos: SOLVE DETERMINANT SEMICOLON  */
#line 230 "sintatico.y"
                                  { }
#line 1485 "sintatico.tab.c"
    break;

  case 22: /* Comandos: SOLVE LINEAR_SYSTEM SEMICOLON  */
#line 231 "sintatico.y"
                                    { }
#line 1491 "sintatico.tab.c"
    break;

  case 23: /* Comandos: ABOUT SEMICOLON  */
#line 232 "sintatico.y"
                      { showAbout(); }
#line 1497 "sintatico.tab.c"
    break;

  case 24: /* Comandos: ID COLON_ASSIGN Expressao SEMICOLON  */
#line 233 "sintatico.y"
                                          {
        if ((yyvsp[-1].result)) {   
            insertHash(myHashTable, (yyvsp[-3].value), (yyvsp[-1].result)->r_float, NUM_FLOAT);
            printf("\n%f\n\n", (yyvsp[-1].result)->r_float);
        } else {
            printf("\n\n");
        }
        return 0;
    }
#line 1511 "sintatico.tab.c"
    break;

  case 25: /* Comandos: ID COLON_ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON  */
#line 242 "sintatico.y"
                                                                                                                                       {
        
    }
#line 1519 "sintatico.tab.c"
    break;

  case 26: /* Comandos: ID SEMICOLON  */
#line 245 "sintatico.y"
                   {
        HashNode *node = getIdentifierNode(myHashTable, (yyvsp[-1].value));
        if (!node) {
            printf("\nUndefined symbol [%s]\n\n", (yyvsp[-1].value));
            return 0;
        }
        printf("\n%f\n\n", node->valueId);
        return 0;
    }
#line 1533 "sintatico.tab.c"
    break;

  case 27: /* Comandos: SHOW SYMBOLS SEMICOLON  */
#line 254 "sintatico.y"
                             { showSymbols(myHashTable); return 0; }
#line 1539 "sintatico.tab.c"
    break;

  case 28: /* Comandos: SET FLOAT PRECISION Expressao SEMICOLON  */
#line 255 "sintatico.y"
                                              {
        if ((int) (yyvsp[-1].result)->r_float < 0 || (int) (yyvsp[-1].result)->r_float > 8) {
            printf("\nERROR: float_precision must be from 0 to 8\n\n");
            return 0;
        } 
        float_precision = (int) (yyvsp[-1].result)->r_float; 
        return 0;
    }
#line 1552 "sintatico.tab.c"
    break;

  case 29: /* Comandos: SET CONNECT_DOTS ON SEMICOLON  */
#line 263 "sintatico.y"
                                    { connect_dots_op = true; /*connectDots();*/ }
#line 1558 "sintatico.tab.c"
    break;

  case 30: /* Comandos: SET CONNECT_DOTS OFF SEMICOLON  */
#line 264 "sintatico.y"
                                     { connect_dots_op = false; }
#line 1564 "sintatico.tab.c"
    break;

  case 31: /* Comandos: QUIT  */
#line 265 "sintatico.y"
           { freeHash(myHashTable); return QUIT; }
#line 1570 "sintatico.tab.c"
    break;

  case 32: /* Repet_Matrix: COMMA NUM_FLOAT Repet_Matrix  */
#line 267 "sintatico.y"
                                           { }
#line 1576 "sintatico.tab.c"
    break;

  case 33: /* Repet_Matrix: %empty  */
#line 268 "sintatico.y"
      { }
#line 1582 "sintatico.tab.c"
    break;

  case 34: /* Repet_Dimen: COMMA L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen  */
#line 270 "sintatico.y"
                                                                                        { }
#line 1588 "sintatico.tab.c"
    break;

  case 35: /* Repet_Dimen: %empty  */
#line 271 "sintatico.y"
      { }
#line 1594 "sintatico.tab.c"
    break;

  case 36: /* Funcao: SEN L_PAREN ExpressaoAditiva R_PAREN  */
#line 273 "sintatico.y"
                                             {
        Function *func = createFunction(SEN, (yyvsp[-1].expr));
        (yyval.func) = func;
    }
#line 1603 "sintatico.tab.c"
    break;

  case 37: /* Funcao: COS L_PAREN ExpressaoAditiva R_PAREN  */
#line 277 "sintatico.y"
                                           { 
        Function *func = createFunction(COS, (yyvsp[-1].expr));
        (yyval.func) = func;
    }
#line 1612 "sintatico.tab.c"
    break;

  case 38: /* Funcao: TAN L_PAREN ExpressaoAditiva R_PAREN  */
#line 281 "sintatico.y"
                                           {
        Function *func = createFunction(TAN, (yyvsp[-1].expr));
        (yyval.func) = func;
    }
#line 1621 "sintatico.tab.c"
    break;

  case 39: /* Funcao: ABS L_PAREN ExpressaoAditiva R_PAREN  */
#line 285 "sintatico.y"
                                           {
        Function *func = createFunction(ABS, (yyvsp[-1].expr));
        (yyval.func) = func;
    }
#line 1630 "sintatico.tab.c"
    break;

  case 40: /* OpUnario: PLUS  */
#line 290 "sintatico.y"
               { (yyval.op) = PLUS; }
#line 1636 "sintatico.tab.c"
    break;

  case 41: /* OpUnario: MINUS  */
#line 291 "sintatico.y"
            { (yyval.op) = MINUS; }
#line 1642 "sintatico.tab.c"
    break;

  case 42: /* OpMult: MULTIPLY  */
#line 293 "sintatico.y"
                 { (yyval.op) = MULTIPLY; }
#line 1648 "sintatico.tab.c"
    break;

  case 43: /* OpMult: DIVIDE  */
#line 294 "sintatico.y"
             { (yyval.op) = DIVIDE; }
#line 1654 "sintatico.tab.c"
    break;

  case 44: /* OpMult: REMAINDER  */
#line 295 "sintatico.y"
                { (yyval.op) = REMAINDER; }
#line 1660 "sintatico.tab.c"
    break;

  case 45: /* OpMult: POWER  */
#line 296 "sintatico.y"
            { (yyval.op) = POWER; }
#line 1666 "sintatico.tab.c"
    break;

  case 46: /* Expressao: ExpressaoAditiva  */
#line 298 "sintatico.y"
                            { 
        ResultExpression *result = evalExpression((yyvsp[0].expr), myHashTable); 
        (yyval.result) = result;
    }
#line 1675 "sintatico.tab.c"
    break;

  case 47: /* ExpressaoAditiva: ExpressaoMultiplicativa  */
#line 303 "sintatico.y"
                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1681 "sintatico.tab.c"
    break;

  case 48: /* ExpressaoAditiva: ExpressaoAditiva OpUnario ExpressaoMultiplicativa  */
#line 304 "sintatico.y"
                                                        {
        Expression *expr = createExpression(ADITIVA, (yyvsp[-1].op), NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1690 "sintatico.tab.c"
    break;

  case 49: /* ExpressaoMultiplicativa: ExpressaoUnaria  */
#line 309 "sintatico.y"
                                         { (yyval.expr) = (yyvsp[0].expr); }
#line 1696 "sintatico.tab.c"
    break;

  case 50: /* ExpressaoMultiplicativa: ExpressaoMultiplicativa OpMult ExpressaoUnaria  */
#line 310 "sintatico.y"
                                                     {
        Expression *expr = createExpression(MULTIPLICATIVA, (yyvsp[-1].op), NULL, (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1705 "sintatico.tab.c"
    break;

  case 51: /* ExpressaoUnaria: ExpressaoPrimaria  */
#line 315 "sintatico.y"
                                   { (yyval.expr) = (yyvsp[0].expr); }
#line 1711 "sintatico.tab.c"
    break;

  case 52: /* ExpressaoUnaria: OpUnario ExpressaoPrimaria  */
#line 316 "sintatico.y"
                                 {
        Expression *expr = createExpression(UNARIA, (yyvsp[-1].op), NULL, (yyvsp[0].expr), NULL);
        (yyval.expr) = expr;
    }
#line 1720 "sintatico.tab.c"
    break;

  case 53: /* ExpressaoPrimaria: ID  */
#line 321 "sintatico.y"
                      {
        Expression *expr = createExpression(PRIMARIA, ID, (yyvsp[0].value), NULL, NULL);
        (yyval.expr) = expr;
    }
#line 1729 "sintatico.tab.c"
    break;

  case 54: /* ExpressaoPrimaria: VAR_X  */
#line 325 "sintatico.y"
            {
        Expression *expr = createExpression(PRIMARIA, VAR_X, "x", NULL, NULL);
        (yyval.expr) = expr;
    }
#line 1738 "sintatico.tab.c"
    break;

  case 55: /* ExpressaoPrimaria: NUM_INT  */
#line 329 "sintatico.y"
              {
        Expression *expr = createExpression(PRIMARIA, NUM_INT, (yyvsp[0].value), NULL, NULL);
        (yyval.expr) = expr;
    }
#line 1747 "sintatico.tab.c"
    break;

  case 56: /* ExpressaoPrimaria: NUM_FLOAT  */
#line 333 "sintatico.y"
                {
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, (yyvsp[0].value), NULL, NULL);
        (yyval.expr) = expr;
    }
#line 1756 "sintatico.tab.c"
    break;

  case 57: /* ExpressaoPrimaria: PI  */
#line 337 "sintatico.y"
         {
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, "3.14159265", NULL, NULL);
        (yyval.expr) = expr;
    }
#line 1765 "sintatico.tab.c"
    break;

  case 58: /* ExpressaoPrimaria: EULER  */
#line 341 "sintatico.y"
            {
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, "2.71828182", NULL, NULL);
        (yyval.expr) = expr;
    }
#line 1774 "sintatico.tab.c"
    break;

  case 59: /* ExpressaoPrimaria: L_PAREN ExpressaoAditiva R_PAREN  */
#line 345 "sintatico.y"
                                       {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1782 "sintatico.tab.c"
    break;

  case 60: /* ExpressaoPrimaria: Funcao  */
#line 348 "sintatico.y"
             {
        Expression *expr = createExpression(PRIMARIA, FUNCTION, NULL, NULL, NULL);
        expr->func = (yyvsp[0].func);
        (yyval.expr) = expr;
    }
#line 1792 "sintatico.tab.c"
    break;


#line 1796 "sintatico.tab.c"

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

#line 354 "sintatico.y"


void yyerror(void *s) {
    if (yychar == EOL) {
        printf("\nSYNTAX ERROR: Incomplete Command\n\n>");
        return;
    }
    if (yychar != 0) {
        printf("\nSYNTAX ERROR: [%s]\n\n", yylval.value);
    }
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

int main(int argc, char *argv[]) {
    myHashTable = createHash();
    printf(">");
    while (true) {
        if (yyparse() == QUIT || yychar == 0) break;
    }
    return 0;
}
