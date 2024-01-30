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

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULTIPLY = 260,                /* MULTIPLY  */
    DIVIDE = 261,                  /* DIVIDE  */
    POWER = 262,                   /* POWER  */
    REMAINDER = 263,               /* REMAINDER  */
    ASSIGN = 264,                  /* ASSIGN  */
    SEMICOLON = 265,               /* SEMICOLON  */
    COMMA = 266,                   /* COMMA  */
    COLON = 267,                   /* COLON  */
    COLON_ASSIGN = 268,            /* COLON_ASSIGN  */
    L_PAREN = 269,                 /* L_PAREN  */
    R_PAREN = 270,                 /* R_PAREN  */
    L_SQUARE_BRACKET = 271,        /* L_SQUARE_BRACKET  */
    R_SQUARE_BRACKET = 272,        /* R_SQUARE_BRACKET  */
    ABOUT = 273,                   /* ABOUT  */
    ABS = 274,                     /* ABS  */
    AXIS = 275,                    /* AXIS  */
    CONNECT_DOTS = 276,            /* CONNECT_DOTS  */
    COS = 277,                     /* COS  */
    DETERMINANT = 278,             /* DETERMINANT  */
    ERASE = 279,                   /* ERASE  */
    EULER = 280,                   /* EULER  */
    FLOAT = 281,                   /* FLOAT  */
    H_VIEW = 282,                  /* H_VIEW  */
    INTEGRAL_STEPS = 283,          /* INTEGRAL_STEPS  */
    INTEGRATE = 284,               /* INTEGRATE  */
    LINEAR_SYSTEM = 285,           /* LINEAR_SYSTEM  */
    MATRIX = 286,                  /* MATRIX  */
    OFF = 287,                     /* OFF  */
    ON = 288,                      /* ON  */
    PI = 289,                      /* PI  */
    PLOT = 290,                    /* PLOT  */
    PRECISION = 291,               /* PRECISION  */
    QUIT = 292,                    /* QUIT  */
    RESET = 293,                   /* RESET  */
    RPN = 294,                     /* RPN  */
    SEN = 295,                     /* SEN  */
    SET = 296,                     /* SET  */
    SETTINGS = 297,                /* SETTINGS  */
    SHOW = 298,                    /* SHOW  */
    SOLVE = 299,                   /* SOLVE  */
    SUM = 300,                     /* SUM  */
    SYMBOLS = 301,                 /* SYMBOLS  */
    TAN = 302,                     /* TAN  */
    V_VIEW = 303,                  /* V_VIEW  */
    VAR_X = 304,                   /* VAR_X  */
    ID = 305,                      /* ID  */
    NUM_INT = 306,                 /* NUM_INT  */
    NUM_FLOAT = 307,               /* NUM_FLOAT  */
    EOL = 308                      /* EOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "sintatico.y"

    int op;
    char *value;
    Expression *expr;
    ResultExpression *result;
    Function *func;

#line 125 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
