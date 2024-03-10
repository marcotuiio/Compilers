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

// #include "asm.h"
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
void yyerror(void *s);

// int dimenCount = 0;
int isFuncOrArray = -1;
int pointerCount = 0;
int paramCount = 0;

void **globalHash = NULL;
void **currentHash = NULL;

Function *functionList = NULL;

Program *AST = NULL;


#line 97 "sintatico.tab.c"

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
  YYSYMBOL_GLOBAL = 4,                     /* GLOBAL  */
  YYSYMBOL_VARIABLE = 5,                   /* VARIABLE  */
  YYSYMBOL_CONSTANT = 6,                   /* CONSTANT  */
  YYSYMBOL_PARAMETER = 7,                  /* PARAMETER  */
  YYSYMBOL_VALUE = 8,                      /* VALUE  */
  YYSYMBOL_RETURN_TYPE = 9,                /* RETURN_TYPE  */
  YYSYMBOL_TYPE = 10,                      /* TYPE  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_INT = 12,                       /* INT  */
  YYSYMBOL_CHAR = 13,                      /* CHAR  */
  YYSYMBOL_FUNCTION = 14,                  /* FUNCTION  */
  YYSYMBOL_END_FUNCTION = 15,              /* END_FUNCTION  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_DO_WHILE = 17,                  /* DO_WHILE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_PRINTF = 21,                    /* PRINTF  */
  YYSYMBOL_SCANF = 22,                     /* SCANF  */
  YYSYMBOL_EXIT = 23,                      /* EXIT  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_MINUS = 25,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 26,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 27,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 28,                 /* REMAINDER  */
  YYSYMBOL_INC = 29,                       /* INC  */
  YYSYMBOL_DEC = 30,                       /* DEC  */
  YYSYMBOL_ADD_ASSIGN = 31,                /* ADD_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 32,              /* MINUS_ASSIGN  */
  YYSYMBOL_ASSIGN = 33,                    /* ASSIGN  */
  YYSYMBOL_EQUAL = 34,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 35,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 36,                 /* LESS_THAN  */
  YYSYMBOL_LESS_EQUAL = 37,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_THAN = 38,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUAL = 39,             /* GREATER_EQUAL  */
  YYSYMBOL_BITWISE_AND = 40,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 41,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 42,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 43,               /* BITWISE_NOT  */
  YYSYMBOL_LOGICAL_AND = 44,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 45,                /* LOGICAL_OR  */
  YYSYMBOL_NOT = 46,                       /* NOT  */
  YYSYMBOL_TERNARY_CONDITIONAL = 47,       /* TERNARY_CONDITIONAL  */
  YYSYMBOL_COLON = 48,                     /* COLON  */
  YYSYMBOL_R_SHIFT = 49,                   /* R_SHIFT  */
  YYSYMBOL_L_SHIFT = 50,                   /* L_SHIFT  */
  YYSYMBOL_L_PAREN = 51,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 52,                   /* R_PAREN  */
  YYSYMBOL_L_SQUARE_BRACKET = 53,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 54,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_COMMA = 55,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 56,                 /* SEMICOLON  */
  YYSYMBOL_NUM_INT = 57,                   /* NUM_INT  */
  YYSYMBOL_STRING = 58,                    /* STRING  */
  YYSYMBOL_CHARACTER = 59,                 /* CHARACTER  */
  YYSYMBOL_ID = 60,                        /* ID  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_AstParse = 62,                  /* AstParse  */
  YYSYMBOL_Declaracoes = 63,               /* Declaracoes  */
  YYSYMBOL_DeclaraDefine = 64,             /* DeclaraDefine  */
  YYSYMBOL_DeclaraVarGlobal = 65,          /* DeclaraVarGlobal  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_DeclaraFuncao = 67,             /* DeclaraFuncao  */
  YYSYMBOL_68_2 = 68,                      /* $@2  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_70_4 = 70,                      /* $@4  */
  YYSYMBOL_ArrayCheck = 71,                /* ArrayCheck  */
  YYSYMBOL_Expression = 72,                /* Expression  */
  YYSYMBOL_BinaryExpr = 73,                /* BinaryExpr  */
  YYSYMBOL_TernaryExpr = 74,               /* TernaryExpr  */
  YYSYMBOL_UnaryExpr = 75,                 /* UnaryExpr  */
  YYSYMBOL_Ops = 76,                       /* Ops  */
  YYSYMBOL_Primaria = 77,                  /* Primaria  */
  YYSYMBOL_PosFixa = 78,                   /* PosFixa  */
  YYSYMBOL_ArrayCall = 79,                 /* ArrayCall  */
  YYSYMBOL_FunctionCall = 80,              /* FunctionCall  */
  YYSYMBOL_ParamExpression = 81,           /* ParamExpression  */
  YYSYMBOL_VarType = 82,                   /* VarType  */
  YYSYMBOL_Parameters = 83,                /* Parameters  */
  YYSYMBOL_84_5 = 84,                      /* $@5  */
  YYSYMBOL_DeclaracoesLocais = 85,         /* DeclaracoesLocais  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_Pointers = 87,                  /* Pointers  */
  YYSYMBOL_ListaComandos = 88,             /* ListaComandos  */
  YYSYMBOL_Comandos = 89,                  /* Comandos  */
  YYSYMBOL_AuxElse = 90,                   /* AuxElse  */
  YYSYMBOL_AuxPrint = 91,                  /* AuxPrint  */
  YYSYMBOL_AuxReturn = 92,                 /* AuxReturn  */
  YYSYMBOL_SemicolonDeSchrodinger = 93     /* SemicolonDeSchrodinger  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   131,   131,   137,   138,   139,   140,   142,   149,   149,
     161,   161,   161,   161,   177,   182,   184,   185,   186,   187,
     188,   190,   196,   202,   207,   212,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   244,   250,   281,   295,   296,   297,   299,   305,   310,
     314,   318,   320,   321,   322,   324,   324,   342,   344,   344,
     354,   356,   357,   359,   363,   365,   369,   373,   377,   381,
     386,   390,   395,   399,   404,   406,   407,   409,   413,   415,
     416,   418,   419
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
  "\"end of file\"", "error", "\"invalid token\"", "MyEOF", "GLOBAL",
  "VARIABLE", "CONSTANT", "PARAMETER", "VALUE", "RETURN_TYPE", "TYPE",
  "VOID", "INT", "CHAR", "FUNCTION", "END_FUNCTION", "RETURN", "DO_WHILE",
  "WHILE", "FOR", "IF", "PRINTF", "SCANF", "EXIT", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "REMAINDER", "INC", "DEC", "ADD_ASSIGN",
  "MINUS_ASSIGN", "ASSIGN", "EQUAL", "NOT_EQUAL", "LESS_THAN",
  "LESS_EQUAL", "GREATER_THAN", "GREATER_EQUAL", "BITWISE_AND",
  "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LOGICAL_AND", "LOGICAL_OR",
  "NOT", "TERNARY_CONDITIONAL", "COLON", "R_SHIFT", "L_SHIFT", "L_PAREN",
  "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "COMMA", "SEMICOLON",
  "NUM_INT", "STRING", "CHARACTER", "ID", "$accept", "AstParse",
  "Declaracoes", "DeclaraDefine", "DeclaraVarGlobal", "$@1",
  "DeclaraFuncao", "$@2", "$@3", "$@4", "ArrayCheck", "Expression",
  "BinaryExpr", "TernaryExpr", "UnaryExpr", "Ops", "Primaria", "PosFixa",
  "ArrayCall", "FunctionCall", "ParamExpression", "VarType", "Parameters",
  "$@5", "DeclaracoesLocais", "$@6", "Pointers", "ListaComandos",
  "Comandos", "AuxElse", "AuxPrint", "AuxReturn", "SemicolonDeSchrodinger", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     5,   -28,   -26,    32,    34,     3,     3,     3,   -13,
     -21,   -16,  -102,  -102,  -102,  -102,  -102,   -15,    39,  -102,
      41,     1,    43,     8,    -4,    10,     2,  -102,     2,  -102,
    -102,  -102,  -102,  -102,    33,    33,    33,     7,  -102,  -102,
       4,  -102,    55,     9,    16,    60,     7,     6,    20,   130,
    -102,    62,    13,    19,    23,    25,    27,    28,    31,    36,
      37,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,    40,  -102,  -102,   249,  -102,  -102,
     -35,    30,  -102,  -102,  -102,    42,  -102,  -102,    77,    30,
      46,    85,   286,   175,   286,   286,   286,    38,    45,   286,
     286,   286,   212,    52,   249,   286,  -102,  -102,  -102,  -102,
     175,   286,  -102,   130,     2,    50,  -102,    54,    53,    56,
      57,    58,    61,    63,    65,    66,   249,    -3,   249,  -102,
    -102,    68,  -102,   -44,  -102,  -102,     2,   175,   286,   175,
     286,   175,   286,    71,    67,   175,   286,  -102,  -102,  -102,
    -102,  -102,   286,    33,  -102,  -102,    72,    73,    74,    78,
      61,    30,    69,  -102,    79,    75,     7,    33,    30,    30,
     286,   175,    76,  -102,   175,    80,   286,  -102,    55,     7,
     175,   175,    81,  -102,    30,  -102,    83,  -102,  -102,    60,
    -102,  -102,   175,   175,    86,  -102,    87,  -102,    30,    30,
     175,   175,  -102,  -102
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     6,     6,     6,     0,
       0,     0,     1,     2,     3,     4,     5,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     7,     0,    64,
      62,    63,     8,    11,    72,    72,    72,    15,    12,    71,
       0,     9,    67,     0,     0,    70,    15,     0,     0,    74,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    47,    48,    45,    46,
      44,    36,    37,    38,    39,    40,    41,    31,    32,    33,
      50,    34,    35,    49,     0,    42,    43,    61,    51,    52,
      56,    92,    16,    17,    18,     0,    19,    20,     0,    92,
       0,     0,    90,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,    53,    54,    55,    91,
      84,     0,    13,    74,     0,     0,    89,     0,     0,     0,
       0,     0,    88,     0,     0,     0,    61,     0,    61,    59,
      58,     0,    83,     0,    73,    65,     0,    84,     0,    84,
       0,    84,     0,     0,     0,    84,     0,    60,    24,    25,
      57,    23,     0,    72,    68,    81,     0,     0,     0,    86,
      88,    92,     0,    82,     0,     0,    15,    72,    92,    92,
       0,    84,     0,    87,    84,     0,     0,    21,    67,    15,
      84,    84,     0,    85,    92,    79,     0,    22,    66,    70,
      76,    77,    84,    84,     0,    69,     0,    75,    92,    92,
      84,    84,    80,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,    35,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
     -46,   -81,  -102,  -102,  -102,  -102,  -102,  -102,  -102,    47,
    -100,   -27,   -62,  -102,   -67,  -102,   -32,    18,  -101,  -102,
      12,  -102,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    34,     8,    22,    35,    42,
      41,    91,    92,    93,    94,    95,    96,   116,   117,    97,
     113,    32,    45,   163,    49,   177,    37,    98,    99,   182,
     153,   127,   120
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    33,   128,    38,    39,   123,   112,     1,   161,     2,
       9,   162,   139,    29,    30,    31,   114,     3,   115,   142,
      10,   126,    11,   129,   130,   131,   158,   159,   134,   135,
     136,   138,    12,   138,   141,    17,   157,    13,   139,    18,
     143,    14,    15,    16,    19,    20,   165,    21,   167,    24,
     169,    23,    25,    27,   173,   138,    26,   138,    28,    36,
      40,    43,    44,    46,    47,    48,    51,   166,    52,   168,
     102,   170,   100,   101,   103,   174,   104,   184,   105,   106,
     193,   175,   107,   195,   190,   191,   119,   108,   109,   200,
     201,   110,   122,   121,   124,   125,   132,   145,   146,   192,
     203,   206,   207,   133,   140,   197,   147,   172,   148,   212,
     213,   149,   150,   151,   210,   211,   152,   155,   154,   164,
     185,   156,   160,   171,   178,   179,   198,   187,   194,   180,
     188,   176,   205,   181,   186,   204,   202,   118,   208,   209,
     196,   144,     0,   199,     0,   189,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
      86,    87,   183,     0,     0,     0,   -84,    88,     0,    89,
      90,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,    86,    87,     0,     0,     0,
       0,     0,    88,     0,    89,    90,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,    86,    87,   137,     0,     0,   111,     0,    88,
       0,    89,    90,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,     0,   111,     0,    88,     0,    89,    90,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,    86,    87,     0,     0,
       0,     0,     0,    88,     0,    89,    90
};

static const yytype_int16 yycheck[] =
{
      46,    28,   103,    35,    36,    99,    87,     4,    52,     6,
       5,    55,   112,    11,    12,    13,    51,    14,    53,   120,
      48,   102,    48,   104,   105,   106,    29,    30,   109,   110,
     111,   112,     0,   114,   115,    48,   136,     3,   138,    60,
     121,     6,     7,     8,    60,    60,   147,     8,   149,    48,
     151,    10,     9,    57,   155,   136,    48,   138,    48,    26,
      53,    57,     7,    54,    48,     5,    60,   148,    48,   150,
      51,   152,    10,    60,    51,   156,    51,   171,    51,    51,
     181,   162,    51,   184,   178,   179,    56,    51,    51,   190,
     191,    51,    15,    51,    48,    10,    58,   124,    48,   180,
     194,   202,   203,    58,    52,   186,    52,    40,    55,   210,
     211,    55,    55,    55,   208,   209,    55,    52,    55,   146,
      51,    55,    54,    52,    52,    52,   188,    52,    52,    55,
     176,   163,   199,    55,    55,    52,    55,    90,    52,    52,
      60,   123,    -1,   189,    -1,   177,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,   170,    -1,    -1,    -1,    56,    57,    -1,    59,
      60,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    59,    60,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    -1,    -1,    55,    -1,    57,
      -1,    59,    60,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      51,    -1,    -1,    -1,    55,    -1,    57,    -1,    59,    60,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     6,    14,    62,    63,    64,    65,    67,     5,
      48,    48,     0,     3,    63,    63,    63,    48,    60,    60,
      60,     8,    68,    10,    48,     9,    48,    57,    48,    11,
      12,    13,    82,    82,    66,    69,    26,    87,    87,    87,
      53,    71,    70,    57,     7,    83,    54,    48,     5,    85,
      71,    60,    48,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    49,    50,    51,    57,    59,
      60,    72,    73,    74,    75,    76,    77,    80,    88,    89,
      10,    60,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    55,    72,    81,    51,    53,    78,    79,    80,    56,
      93,    51,    15,    93,    48,    10,    72,    92,    89,    72,
      72,    72,    58,    58,    72,    72,    72,    52,    72,    81,
      52,    72,    89,    72,    88,    82,    48,    52,    55,    55,
      55,    55,    55,    91,    55,    52,    55,    81,    29,    30,
      54,    52,    55,    84,    82,    89,    72,    89,    72,    89,
      72,    52,    40,    89,    72,    72,    87,    86,    52,    52,
      55,    55,    90,    91,    93,    51,    55,    52,    71,    87,
      93,    93,    72,    89,    52,    89,    60,    72,    83,    71,
      89,    89,    55,    93,    52,    85,    89,    89,    52,    52,
      93,    93,    89,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    64,    66,    65,
      68,    69,    70,    67,    71,    71,    72,    72,    72,    72,
      72,    73,    74,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    77,    78,    78,    78,    79,    80,    81,
      81,    81,    82,    82,    82,    84,    83,    83,    86,    85,
      85,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     0,     6,     0,    10,
       0,     0,     0,    14,     4,     0,     1,     1,     1,     1,
       1,     6,     7,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     0,     3,     3,     2,
       3,     0,     1,     1,     1,     0,    10,     0,     0,    10,
       0,     2,     0,     3,     0,     9,     8,     8,    12,     7,
      11,     5,     5,     3,     0,     2,     0,     3,     0,     1,
       0,     1,     0
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
  case 2: /* AstParse: Declaracoes MyEOF  */
#line 131 "sintatico.y"
                            {
        Program *ast = createProgram(globalHash, functionList, NULL);
        AST = ast;
        return 0;
    }
#line 1352 "sintatico.tab.c"
    break;

  case 3: /* Declaracoes: DeclaraDefine Declaracoes  */
#line 137 "sintatico.y"
                                       { }
#line 1358 "sintatico.tab.c"
    break;

  case 4: /* Declaracoes: DeclaraVarGlobal Declaracoes  */
#line 138 "sintatico.y"
                                   { }
#line 1364 "sintatico.tab.c"
    break;

  case 5: /* Declaracoes: DeclaraFuncao Declaracoes  */
#line 139 "sintatico.y"
                                { }
#line 1370 "sintatico.tab.c"
    break;

  case 6: /* Declaracoes: %empty  */
#line 140 "sintatico.y"
      { }
#line 1376 "sintatico.tab.c"
    break;

  case 7: /* DeclaraDefine: CONSTANT COLON ID VALUE COLON NUM_INT  */
#line 142 "sintatico.y"
                                                     {
        void *node = insertHash(globalHash, (yyvsp[-3].token).valor, INT, 0);
        setKind(node, VAR);
        setIsConstant(node);
        setAssign(node, atoi((yyvsp[0].token).valor)); 
    }
#line 1387 "sintatico.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 149 "sintatico.y"
                                                              { pointerCount = 0; }
#line 1393 "sintatico.tab.c"
    break;

  case 9: /* DeclaraVarGlobal: GLOBAL VARIABLE COLON ID TYPE COLON VarType $@1 Pointers ArrayCheck  */
#line 149 "sintatico.y"
                                                                                                        {
        // printf("DeclaraVarGlobal global var\n");
        void *node = insertHash(globalHash, (yyvsp[-6].token).valor, (yyvsp[-3].token).type, pointerCount);
        if (!(yyvsp[0].dim)) {
            setKind(node, VAR);
        } else {
            setKind(node, VECTOR);
        }
        setDimensions(node, (yyvsp[0].dim));
        setIsGlobal(node);
    }
#line 1409 "sintatico.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 161 "sintatico.y"
                                 { currentHash = createHash(); }
#line 1415 "sintatico.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 161 "sintatico.y"
                                                                                           { pointerCount = 0; }
#line 1421 "sintatico.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 161 "sintatico.y"
                                                                                                                          { paramCount = 0; }
#line 1427 "sintatico.tab.c"
    break;

  case 13: /* DeclaraFuncao: FUNCTION COLON ID $@2 RETURN_TYPE COLON VarType $@3 Pointers $@4 Parameters DeclaracoesLocais ListaComandos END_FUNCTION  */
#line 161 "sintatico.y"
                                                                                                                                                                                                      {
        Function *func = createFunction(currentHash, (yyvsp[-7].token).type, pointerCount, (yyvsp[-11].token).valor, (yyvsp[-1].cmd), NULL);
        if (functionList) {
            functionList->next = func;
        } else {
            functionList = func;
        }
        
        // printf("Funcoes %s %p | %p -> %p \n", $3.valor, func, functionList, functionList->next);
        void *node = insertHash(globalHash, (yyvsp[-11].token).valor, (yyvsp[-7].token).type, pointerCount);
        setKind(node, FUNCTIONN);
        setQntdParams(node, paramCount);
        setParam(node, (yyvsp[-3].param));
        currentHash = NULL;
    }
#line 1447 "sintatico.tab.c"
    break;

  case 14: /* ArrayCheck: L_SQUARE_BRACKET NUM_INT R_SQUARE_BRACKET ArrayCheck  */
#line 177 "sintatico.y"
                                                                 {
        Dimension *dim = createDimension(atoi((yyvsp[-2].token).valor));
        dim->next = (yyvsp[0].dim);
        (yyval.dim) = dim;
    }
#line 1457 "sintatico.tab.c"
    break;

  case 15: /* ArrayCheck: %empty  */
#line 182 "sintatico.y"
      { (yyval.dim) = NULL; }
#line 1463 "sintatico.tab.c"
    break;

  case 16: /* Expression: BinaryExpr  */
#line 184 "sintatico.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 1469 "sintatico.tab.c"
    break;

  case 17: /* Expression: TernaryExpr  */
#line 185 "sintatico.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 1475 "sintatico.tab.c"
    break;

  case 18: /* Expression: UnaryExpr  */
#line 186 "sintatico.y"
                { (yyval.expr) = (yyvsp[0].expr); }
#line 1481 "sintatico.tab.c"
    break;

  case 19: /* Expression: Primaria  */
#line 187 "sintatico.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 1487 "sintatico.tab.c"
    break;

  case 20: /* Expression: FunctionCall  */
#line 188 "sintatico.y"
                   { (yyval.expr) = (yyvsp[0].param); }
#line 1493 "sintatico.tab.c"
    break;

  case 21: /* BinaryExpr: Ops L_PAREN Expression COMMA Expression R_PAREN  */
#line 190 "sintatico.y"
                                                            {
        // printf("bop %d\n", $1.type);
        Expression *bop = createExpression(BOP, (yyvsp[-5].token).type, (yyvsp[-3].expr), (yyvsp[-1].expr));
        (yyval.expr) = bop;
    }
#line 1503 "sintatico.tab.c"
    break;

  case 22: /* TernaryExpr: TERNARY_CONDITIONAL L_PAREN Expression COMMA Expression COMMA Expression  */
#line 196 "sintatico.y"
                                                                                      {
        Expression *ternary = createExpression(TERNARY, TERNARY_CONDITIONAL, (yyvsp[-2].expr), (yyvsp[0].expr));
        ternary->ternaryCondition = (yyvsp[-4].expr);
        (yyval.expr) = ternary;
    }
#line 1513 "sintatico.tab.c"
    break;

  case 23: /* UnaryExpr: Ops L_PAREN Expression R_PAREN  */
#line 202 "sintatico.y"
                                          {
        // printf("uop %d\n", $1.type);
        Expression *uop = createExpression(UOP, (yyvsp[-3].token).type, (yyvsp[-1].expr), NULL);
        (yyval.expr) = uop;
    }
#line 1523 "sintatico.tab.c"
    break;

  case 24: /* UnaryExpr: L_PAREN Expression R_PAREN INC  */
#line 207 "sintatico.y"
                                     {
        // printf("uop %d\n", $4.type);
        Expression *uop = createExpression(UOP, INC, (yyvsp[-2].expr), NULL);
        (yyval.expr) = uop;
    }
#line 1533 "sintatico.tab.c"
    break;

  case 25: /* UnaryExpr: L_PAREN Expression R_PAREN DEC  */
#line 212 "sintatico.y"
                                     {
        // printf("uop %d\n", $4.type);
        Expression *uop = createExpression(UOP, DEC, (yyvsp[-2].expr), NULL);
        (yyval.expr) = uop;
    }
#line 1543 "sintatico.tab.c"
    break;

  case 26: /* Ops: PLUS  */
#line 218 "sintatico.y"
          { (yyval.token) = yylval.token; }
#line 1549 "sintatico.tab.c"
    break;

  case 27: /* Ops: MINUS  */
#line 219 "sintatico.y"
            { (yyval.token) = yylval.token; }
#line 1555 "sintatico.tab.c"
    break;

  case 28: /* Ops: MULTIPLY  */
#line 220 "sintatico.y"
               { (yyval.token) = yylval.token; }
#line 1561 "sintatico.tab.c"
    break;

  case 29: /* Ops: DIVIDE  */
#line 221 "sintatico.y"
             { (yyval.token) = yylval.token; }
#line 1567 "sintatico.tab.c"
    break;

  case 30: /* Ops: REMAINDER  */
#line 222 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 1573 "sintatico.tab.c"
    break;

  case 31: /* Ops: BITWISE_AND  */
#line 223 "sintatico.y"
                  { (yyval.token) = yylval.token; }
#line 1579 "sintatico.tab.c"
    break;

  case 32: /* Ops: BITWISE_OR  */
#line 224 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1585 "sintatico.tab.c"
    break;

  case 33: /* Ops: BITWISE_XOR  */
#line 225 "sintatico.y"
                  { (yyval.token) = yylval.token; }
#line 1591 "sintatico.tab.c"
    break;

  case 34: /* Ops: LOGICAL_AND  */
#line 226 "sintatico.y"
                  { (yyval.token) = yylval.token; }
#line 1597 "sintatico.tab.c"
    break;

  case 35: /* Ops: LOGICAL_OR  */
#line 227 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1603 "sintatico.tab.c"
    break;

  case 36: /* Ops: EQUAL  */
#line 228 "sintatico.y"
            { (yyval.token) = yylval.token; }
#line 1609 "sintatico.tab.c"
    break;

  case 37: /* Ops: NOT_EQUAL  */
#line 229 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 1615 "sintatico.tab.c"
    break;

  case 38: /* Ops: LESS_THAN  */
#line 230 "sintatico.y"
                { (yyval.token) = yylval.token; }
#line 1621 "sintatico.tab.c"
    break;

  case 39: /* Ops: LESS_EQUAL  */
#line 231 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1627 "sintatico.tab.c"
    break;

  case 40: /* Ops: GREATER_THAN  */
#line 232 "sintatico.y"
                   { (yyval.token) = yylval.token; }
#line 1633 "sintatico.tab.c"
    break;

  case 41: /* Ops: GREATER_EQUAL  */
#line 233 "sintatico.y"
                    { (yyval.token) = yylval.token; }
#line 1639 "sintatico.tab.c"
    break;

  case 42: /* Ops: R_SHIFT  */
#line 234 "sintatico.y"
              { (yyval.token) = yylval.token; }
#line 1645 "sintatico.tab.c"
    break;

  case 43: /* Ops: L_SHIFT  */
#line 235 "sintatico.y"
              { (yyval.token) = yylval.token; }
#line 1651 "sintatico.tab.c"
    break;

  case 44: /* Ops: ASSIGN  */
#line 236 "sintatico.y"
             { (yyval.token) = yylval.token; }
#line 1657 "sintatico.tab.c"
    break;

  case 45: /* Ops: ADD_ASSIGN  */
#line 237 "sintatico.y"
                 { (yyval.token) = yylval.token; }
#line 1663 "sintatico.tab.c"
    break;

  case 46: /* Ops: MINUS_ASSIGN  */
#line 238 "sintatico.y"
                   { (yyval.token) = yylval.token; }
#line 1669 "sintatico.tab.c"
    break;

  case 47: /* Ops: INC  */
#line 239 "sintatico.y"
          { (yyval.token) = yylval.token; }
#line 1675 "sintatico.tab.c"
    break;

  case 48: /* Ops: DEC  */
#line 240 "sintatico.y"
          { (yyval.token) = yylval.token; }
#line 1681 "sintatico.tab.c"
    break;

  case 49: /* Ops: NOT  */
#line 241 "sintatico.y"
          { (yyval.token) = yylval.token; }
#line 1687 "sintatico.tab.c"
    break;

  case 50: /* Ops: BITWISE_NOT  */
#line 242 "sintatico.y"
                  { (yyval.token) = yylval.token; }
#line 1693 "sintatico.tab.c"
    break;

  case 51: /* Primaria: NUM_INT  */
#line 244 "sintatico.y"
                  {
        Expression *expr = createExpression(PRIMARIA, INT, NULL, NULL);
        expr->assign = atoi((yyvsp[0].token).valor);
        // printf("primaria %p %d\n", expr, expr->assign);
        (yyval.expr) = expr;
    }
#line 1704 "sintatico.tab.c"
    break;

  case 52: /* Primaria: CHARACTER  */
#line 250 "sintatico.y"
                {
        Expression *expr = createExpression(PRIMARIA, CHAR, NULL, NULL);
        if ((yyvsp[0].token).valor[1] == '\\') {
            switch ((yyvsp[0].token).valor[2]) {
                case 'n':
                    expr->assign = '\n';
                    break;
                case 't':
                    expr->assign = '\t';
                    break;
                case 'r':
                    expr->assign = '\r';
                    break;
                case '0':
                    expr->assign = '\0';
                    break;
                case '\\':
                    expr->assign = '\\';
                    break;
                case '\'':
                    expr->assign = '\'';
                    break;
                case '\"':
                    expr->assign = '\"';
                    break;
            }
        } else {
            expr->assign = (yyvsp[0].token).valor[1];
        }
        (yyval.expr) = expr;
    }
#line 1740 "sintatico.tab.c"
    break;

  case 53: /* Primaria: ID PosFixa  */
#line 281 "sintatico.y"
                 {
        Expression *expr = createExpression(PRIMARIA, ID, NULL, NULL);
        if (isFuncOrArray == 1) {
            printf("pos fixa %s [%p]  \n", (yyvsp[-1].token).valor, (yyvsp[0].posfixa));
            setDimensionExpression(expr, ((Dimension*)(yyvsp[0].posfixa)));
        
        } else if (isFuncOrArray == 2) {
            printf("pos fixa %s (%p)  \n", (yyvsp[-1].token).valor, (yyvsp[0].posfixa));
            expr->param = (ExpParam*)(yyvsp[0].posfixa);
        }
        isFuncOrArray = -1;
        (yyval.expr) = expr;
    }
#line 1758 "sintatico.tab.c"
    break;

  case 54: /* PosFixa: ArrayCall  */
#line 295 "sintatico.y"
                   { isFuncOrArray = 1; (yyval.posfixa) = (yyvsp[0].dim); }
#line 1764 "sintatico.tab.c"
    break;

  case 55: /* PosFixa: FunctionCall  */
#line 296 "sintatico.y"
                   { isFuncOrArray = 2; (yyval.posfixa) = (yyvsp[0].param); }
#line 1770 "sintatico.tab.c"
    break;

  case 56: /* PosFixa: %empty  */
#line 297 "sintatico.y"
      { isFuncOrArray = 0; (yyval.posfixa) = NULL; }
#line 1776 "sintatico.tab.c"
    break;

  case 57: /* ArrayCall: L_SQUARE_BRACKET Expression R_SQUARE_BRACKET  */
#line 299 "sintatico.y"
                                                        {
        Dimension *dim = createDimensionWithExp((yyvsp[-1].expr));
        // Expression *expr = createExpression(ARRAY_CALL, ID, NULL, NULL);
        (yyval.dim) = dim;
    }
#line 1786 "sintatico.tab.c"
    break;

  case 58: /* FunctionCall: L_PAREN ParamExpression R_PAREN  */
#line 305 "sintatico.y"
                                              {
        // Expression *expr = createExpression(FUNCTION_CALL, L_PAREN, NULL, NULL);
        (yyval.param) = (yyvsp[-1].param);
    }
#line 1795 "sintatico.tab.c"
    break;

  case 59: /* ParamExpression: Expression ParamExpression  */
#line 310 "sintatico.y"
                                            {
        ExpParam *aux = createExpParam((yyvsp[-1].expr), (yyvsp[0].param));
        (yyval.param) = aux;
    }
#line 1804 "sintatico.tab.c"
    break;

  case 60: /* ParamExpression: COMMA Expression ParamExpression  */
#line 314 "sintatico.y"
                                       {
        ExpParam *aux = createExpParam((yyvsp[-1].expr), (yyvsp[0].param));
        (yyval.param) = aux;
    }
#line 1813 "sintatico.tab.c"
    break;

  case 61: /* ParamExpression: %empty  */
#line 318 "sintatico.y"
      { (yyval.param) = NULL; }
#line 1819 "sintatico.tab.c"
    break;

  case 62: /* VarType: INT  */
#line 320 "sintatico.y"
             { (yyval.token) = yylval.token; }
#line 1825 "sintatico.tab.c"
    break;

  case 63: /* VarType: CHAR  */
#line 321 "sintatico.y"
           { (yyval.token) = yylval.token; }
#line 1831 "sintatico.tab.c"
    break;

  case 64: /* VarType: VOID  */
#line 322 "sintatico.y"
           { (yyval.token) = yylval.token; }
#line 1837 "sintatico.tab.c"
    break;

  case 65: /* $@5: %empty  */
#line 324 "sintatico.y"
                                                  { pointerCount = 0; }
#line 1843 "sintatico.tab.c"
    break;

  case 66: /* Parameters: PARAMETER COLON ID TYPE COLON VarType $@5 Pointers ArrayCheck Parameters  */
#line 324 "sintatico.y"
                                                                                                       {
        // printf("Parmetro ID %s type %d\n", $3.valor, $6.type);
        void *node = insertHash(currentHash, (yyvsp[-7].token).valor, (yyvsp[-4].token).type, pointerCount);
        setQntdParams(node, paramCount);
        // setSRegisterInHash(node, paramsQntd-1);
        paramCount++;
        Param *param = createParam((yyvsp[-4].token).type, (yyvsp[-7].token).valor, pointerCount, (yyvsp[0].param));
        if (!(yyvsp[-1].dim)) {
            setKind(node, VAR);
            param->kindParam = VAR;
        } else {
            setKind(node, VECTOR);
            param->kindParam = VECTOR;
        }
        setDimensions(node, (yyvsp[-1].dim));
        param->next = (yyvsp[0].param);
        (yyval.param) = param;
    }
#line 1866 "sintatico.tab.c"
    break;

  case 67: /* Parameters: %empty  */
#line 342 "sintatico.y"
      { (yyval.param) = NULL; }
#line 1872 "sintatico.tab.c"
    break;

  case 68: /* $@6: %empty  */
#line 344 "sintatico.y"
                                                        { pointerCount = 0; }
#line 1878 "sintatico.tab.c"
    break;

  case 69: /* DeclaracoesLocais: VARIABLE COLON ID TYPE COLON VarType $@6 Pointers ArrayCheck DeclaracoesLocais  */
#line 344 "sintatico.y"
                                                                                                                    {
        // printf("DeclaracoesLocais local var %s %d\n", $3.valor, $6.type);
        void *node = insertHash(currentHash, (yyvsp[-7].token).valor, (yyvsp[-4].token).type, pointerCount);
        if (!(yyvsp[-1].dim)) {
            setKind(node, VAR);
        } else {
            setKind(node, VECTOR);
        }
        setDimensions(node, (yyvsp[-1].dim));
    }
#line 1893 "sintatico.tab.c"
    break;

  case 70: /* DeclaracoesLocais: %empty  */
#line 354 "sintatico.y"
      { }
#line 1899 "sintatico.tab.c"
    break;

  case 71: /* Pointers: MULTIPLY Pointers  */
#line 356 "sintatico.y"
                            { pointerCount++; }
#line 1905 "sintatico.tab.c"
    break;

  case 72: /* Pointers: %empty  */
#line 357 "sintatico.y"
      { }
#line 1911 "sintatico.tab.c"
    break;

  case 73: /* ListaComandos: Comandos SemicolonDeSchrodinger ListaComandos  */
#line 359 "sintatico.y"
                                                             {       
        (yyvsp[-2].cmd)->next = (yyvsp[0].cmd);
        (yyval.cmd) = (yyvsp[-2].cmd);
    }
#line 1920 "sintatico.tab.c"
    break;

  case 74: /* ListaComandos: %empty  */
#line 363 "sintatico.y"
      { }
#line 1926 "sintatico.tab.c"
    break;

  case 75: /* Comandos: IF L_PAREN Expression COMMA Comandos AuxElse R_PAREN SemicolonDeSchrodinger Comandos  */
#line 365 "sintatico.y"
                                                                                               {
        Command *cmd = createIfStatement((yyvsp[-6].expr), (yyvsp[-4].cmd), (yyvsp[-3].cmd), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 1935 "sintatico.tab.c"
    break;

  case 76: /* Comandos: DO_WHILE L_PAREN Comandos COMMA Expression R_PAREN SemicolonDeSchrodinger Comandos  */
#line 369 "sintatico.y"
                                                                                         {
        Command *cmd = createDoWhileStatement((yyvsp[-3].expr), (yyvsp[-5].cmd), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 1944 "sintatico.tab.c"
    break;

  case 77: /* Comandos: WHILE L_PAREN Expression COMMA Comandos R_PAREN SemicolonDeSchrodinger Comandos  */
#line 373 "sintatico.y"
                                                                                      {
        Command *cmd = createWhileStatement((yyvsp[-5].expr), (yyvsp[-3].cmd), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 1953 "sintatico.tab.c"
    break;

  case 78: /* Comandos: FOR L_PAREN Expression COMMA Expression COMMA Expression COMMA Comandos R_PAREN SemicolonDeSchrodinger Comandos  */
#line 377 "sintatico.y"
                                                                                                                      {
        Command *cmd = createForStatement((yyvsp[-9].expr), (yyvsp[-7].expr), (yyvsp[-5].expr), (yyvsp[-3].cmd), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 1962 "sintatico.tab.c"
    break;

  case 79: /* Comandos: PRINTF L_PAREN STRING AuxPrint R_PAREN SemicolonDeSchrodinger Comandos  */
#line 381 "sintatico.y"
                                                                             {
        // printf("Comandos print %s \n", $3.valor);
        Command *cmd = createPrintStatement((yyvsp[-4].token).valor, (yyvsp[-3].expr), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 1972 "sintatico.tab.c"
    break;

  case 80: /* Comandos: SCANF L_PAREN STRING COMMA BITWISE_AND L_PAREN ID R_PAREN R_PAREN SemicolonDeSchrodinger Comandos  */
#line 386 "sintatico.y"
                                                                                                        {
        Command *cmd = createScanStatement((yyvsp[-8].token).valor, (yyvsp[-4].token).valor, (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 1981 "sintatico.tab.c"
    break;

  case 81: /* Comandos: RETURN L_PAREN AuxReturn R_PAREN Comandos  */
#line 390 "sintatico.y"
                                                {
        // printf("@@@@@@@ retunr  %d\n", $3 ? $3->type : -1);
        Command *cmd = createReturnStatement((yyvsp[-2].expr), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 1991 "sintatico.tab.c"
    break;

  case 82: /* Comandos: EXIT L_PAREN Expression R_PAREN Comandos  */
#line 395 "sintatico.y"
                                               {
        Command *cmd = createExitStatement((yyvsp[-2].expr), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 2000 "sintatico.tab.c"
    break;

  case 83: /* Comandos: Expression SemicolonDeSchrodinger Comandos  */
#line 399 "sintatico.y"
                                                 {
        // printf("000000000000000 Comandos expression\n");
        Command *cmd = createCommandExpression((yyvsp[-2].expr), (yyvsp[0].cmd));
        (yyval.cmd) = cmd;
    }
#line 2010 "sintatico.tab.c"
    break;

  case 84: /* Comandos: %empty  */
#line 404 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 2016 "sintatico.tab.c"
    break;

  case 85: /* AuxElse: COMMA Comandos  */
#line 406 "sintatico.y"
                        { (yyval.cmd) = (yyvsp[0].cmd); }
#line 2022 "sintatico.tab.c"
    break;

  case 86: /* AuxElse: %empty  */
#line 407 "sintatico.y"
      { (yyval.cmd) = NULL; }
#line 2028 "sintatico.tab.c"
    break;

  case 87: /* AuxPrint: COMMA Expression AuxPrint  */
#line 409 "sintatico.y"
                                    {
        (yyvsp[-1].expr)->nextExpr = (yyvsp[0].expr);
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2037 "sintatico.tab.c"
    break;

  case 88: /* AuxPrint: %empty  */
#line 413 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2043 "sintatico.tab.c"
    break;

  case 89: /* AuxReturn: Expression  */
#line 415 "sintatico.y"
                      { (yyval.expr) = (yyvsp[0].expr); }
#line 2049 "sintatico.tab.c"
    break;

  case 90: /* AuxReturn: %empty  */
#line 416 "sintatico.y"
      { (yyval.expr) = NULL; }
#line 2055 "sintatico.tab.c"
    break;

  case 91: /* SemicolonDeSchrodinger: SEMICOLON  */
#line 418 "sintatico.y"
                                  { }
#line 2061 "sintatico.tab.c"
    break;

  case 92: /* SemicolonDeSchrodinger: %empty  */
#line 419 "sintatico.y"
      { }
#line 2067 "sintatico.tab.c"
    break;


#line 2071 "sintatico.tab.c"

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

#line 421 "sintatico.y"


void yyerror(void *s) {
    printf("Erro na gramatica %d [ %s ]:%d:%d \n", yychar, yylval.token.valor, yylval.token.line, yylval.token.col);
}

int main(int argc, char *argv[]) {
    globalHash = createHash();
    yyparse();
    void **hash = NULL;

    printf("\n>>>>>>>> End Parse <<<<<<<<\n");
    if (AST) {
        Program *ast = (Program*)AST;
        printf("AST %p\n", ast);
        hash = ast->hashTable;
    } else {
        printf("AST NULL\n");
        exit(1);
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *node = (HashNode*)hash[i];
        while (node) {
            printf("%d Global hash %s %d\n", i, node->varId, node->typeVar);
            node = node->next;
        }
    }
    
    printf("\n");
    Function *func = (Function*)AST->functionsList;
    while (func) {
        printf("Function %s %d hash %p\n", func->name, func->returnType, func->hashTable);

        for (int i = 0; i < HASH_SIZE; i++) {
            HashNode *node = (HashNode*)func->hashTable[i];
            while (node) {
                printf("%d Local hash var %s %d\n", i, node->varId, node->typeVar);
                node = node->next;
            }
        }
        printf("\n");
        Command *cmd = (Command*)func->commandList;
        while (cmd) {
            printf("Command %d\n", cmd->type);
            cmd = cmd->next;
        }
        printf("\n");
        func = func->next;
    }
    
    return 0;
}
