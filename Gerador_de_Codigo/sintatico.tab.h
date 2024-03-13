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
    MyEOF = 258,                   /* MyEOF  */
    GLOBAL = 259,                  /* GLOBAL  */
    VARIABLE = 260,                /* VARIABLE  */
    CONSTANT = 261,                /* CONSTANT  */
    PARAMETER = 262,               /* PARAMETER  */
    VALUE = 263,                   /* VALUE  */
    RETURN_TYPE = 264,             /* RETURN_TYPE  */
    TYPE = 265,                    /* TYPE  */
    VOID = 266,                    /* VOID  */
    INT = 267,                     /* INT  */
    CHAR = 268,                    /* CHAR  */
    FUNCTION = 269,                /* FUNCTION  */
    END_FUNCTION = 270,            /* END_FUNCTION  */
    RETURN = 271,                  /* RETURN  */
    DO_WHILE = 272,                /* DO_WHILE  */
    WHILE = 273,                   /* WHILE  */
    FOR = 274,                     /* FOR  */
    IF = 275,                      /* IF  */
    PRINTF = 276,                  /* PRINTF  */
    SCANF = 277,                   /* SCANF  */
    EXIT = 278,                    /* EXIT  */
    PLUS = 279,                    /* PLUS  */
    MINUS = 280,                   /* MINUS  */
    MULTIPLY = 281,                /* MULTIPLY  */
    DIVIDE = 282,                  /* DIVIDE  */
    REMAINDER = 283,               /* REMAINDER  */
    INC = 284,                     /* INC  */
    DEC = 285,                     /* DEC  */
    ADD_ASSIGN = 286,              /* ADD_ASSIGN  */
    MINUS_ASSIGN = 287,            /* MINUS_ASSIGN  */
    ASSIGN = 288,                  /* ASSIGN  */
    EQUAL = 289,                   /* EQUAL  */
    NOT_EQUAL = 290,               /* NOT_EQUAL  */
    LESS_THAN = 291,               /* LESS_THAN  */
    LESS_EQUAL = 292,              /* LESS_EQUAL  */
    GREATER_THAN = 293,            /* GREATER_THAN  */
    GREATER_EQUAL = 294,           /* GREATER_EQUAL  */
    BITWISE_AND = 295,             /* BITWISE_AND  */
    BITWISE_OR = 296,              /* BITWISE_OR  */
    BITWISE_XOR = 297,             /* BITWISE_XOR  */
    BITWISE_NOT = 298,             /* BITWISE_NOT  */
    LOGICAL_AND = 299,             /* LOGICAL_AND  */
    LOGICAL_OR = 300,              /* LOGICAL_OR  */
    NOT = 301,                     /* NOT  */
    TERNARY_CONDITIONAL = 302,     /* TERNARY_CONDITIONAL  */
    COLON = 303,                   /* COLON  */
    R_SHIFT = 304,                 /* R_SHIFT  */
    L_SHIFT = 305,                 /* L_SHIFT  */
    L_PAREN = 306,                 /* L_PAREN  */
    R_PAREN = 307,                 /* R_PAREN  */
    L_SQUARE_BRACKET = 308,        /* L_SQUARE_BRACKET  */
    R_SQUARE_BRACKET = 309,        /* R_SQUARE_BRACKET  */
    COMMA = 310,                   /* COMMA  */
    SEMICOLON = 311,               /* SEMICOLON  */
    NUM_INT = 312,                 /* NUM_INT  */
    STRING = 313,                  /* STRING  */
    CHARACTER = 314,               /* CHARACTER  */
    ID = 315                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "sintatico.y"

    Program *prog;
    Function *func;
    Dimension *dim;
    Expression *expr;
    Command *cmd;
    void *param;
    void *posfixa;
    int sinalAux;
    struct {
        char *valor;
        int type;
        int line;
        int col;
    } token;

#line 141 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
