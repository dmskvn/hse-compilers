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

#ifndef YY_YY_BASIC_TAB_H_INCLUDED
# define YY_YY_BASIC_TAB_H_INCLUDED
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
    PRINT = 258,                   /* PRINT  */
    LET = 259,                     /* LET  */
    EQUAL = 260,                   /* EQUAL  */
    LESS = 261,                    /* LESS  */
    GREATER = 262,                 /* GREATER  */
    LESSEQUAL = 263,               /* LESSEQUAL  */
    GREATEREQUAL = 264,            /* GREATEREQUAL  */
    NOTEQUAL = 265,                /* NOTEQUAL  */
    EXEC = 266,                    /* EXEC  */
    LOAD = 267,                    /* LOAD  */
    ENDL = 268,                    /* ENDL  */
    LIST = 269,                    /* LIST  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    END = 272,                     /* END  */
    THEN = 273,                    /* THEN  */
    FOR = 274,                     /* FOR  */
    TO = 275,                      /* TO  */
    NEXT = 276,                    /* NEXT  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    MULT = 279,                    /* MULT  */
    DIV = 280,                     /* DIV  */
    OPENPAREN = 281,               /* OPENPAREN  */
    CLOSEPAREN = 282,              /* CLOSEPAREN  */
    INTEGER = 283,                 /* INTEGER  */
    DOUBLE = 284,                  /* DOUBLE  */
    VARNAME = 285,                 /* VARNAME  */
    TEXT = 286                     /* TEXT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "basic.y"

	int iVal;
	double dVal;
	IProgram *progVal;
	IExpression *eVal;
	char *sVal;

#line 103 "basic.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BASIC_TAB_H_INCLUDED  */
