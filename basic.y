// A BASIC grammar interpreter

%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" char *yytext;
extern "C" int yywrap();

extern int yylineno;

void yyerror(const char *s);

#include "basic.h"
#include "let.h"
#include "ifthen.h"
#include "else.h"
#include "print.h"
#include "endif.h"
#include "for.h"
#include "next.h"
#include "program.h"
#include "printtext.h"
#include "expression.h"
#include "operatorexpression.h"
#include "doubleexpression.h"
#include "parenexpression.h"
%}

// token type definition
%union {
	int iVal;
	double dVal;
	IProgram *progVal;
	IExpression *eVal;
	char *sVal;
}

// constant tokens
%token PRINT
%token LET
%token EQUAL
%token LESS
%token GREATER
%token LESSEQUAL
%token GREATEREQUAL
%token NOTEQUAL
%token EXEC
%token LOAD
%token ENDL
%token LIST
%token IF
%token ELSE
%token END
%token THEN
%token FOR
%token TO
%token NEXT
%token PLUS
%token MINUS
%token MULT
%token DIV
%token OPENPAREN
%token CLOSEPAREN

// terminal symbols
%token <iVal> INTEGER
%token <dVal> DOUBLE
%token <sVal> VARNAME
%token <sVal> TEXT
%type <eVal> doubleExpr
%type <eVal> addExpr
%type <eVal> mulExpr
%type <eVal> term

// non-terminal symbols
%type <progVal> program 
%type <sVal> cmp

%% /* Grammar rules and actions follow */

input:
	/* empty */
	| input line
;

line:
	ENDL {
		std::cout << "ENDL" << std::endl;
		}
	| statement ENDL {
		//std::cout << "Y STM ENDL" << std::endl;
		// char c = fgetc(yyin); 
		// std::cout << (c == EOF) << std::endl;
    	// while (c != EOF) 
    	// { 
        //	printf ("%c", c); 
        //	c = fgetc(yyin); 
    	// } 
	}
;

statement:
	LIST {Basic::instance()->list();}
	| LOAD {Basic::instance()->load();}
	| EXEC {Basic::instance()->exec();}
	| program {Basic::instance()->add($1);}
;

program:
	LET VARNAME {$$ = new Let($2);}
	| LET VARNAME EQUAL DOUBLE {$$ = new Let($2, $4);}
	| VARNAME EQUAL doubleExpr {$$ = new Let($1, $3);}
	| FOR VARNAME EQUAL DOUBLE TO VARNAME {$$ = new For($2, $4, $6);}
	| IF VARNAME cmp VARNAME THEN {$$ = new IfThen($2, $3, $4);}
	| ELSE {$$ = new Else();}
	| END IF {$$ = new EndIf();}
	| NEXT {$$ = new Next();}
	| PRINT VARNAME {$$ = new Print($2);}
	| PRINT TEXT {$$ = new PrintText($2);}
;

doubleExpr:
	addExpr
;

addExpr:
	mulExpr
	| mulExpr PLUS mulExpr	{ $$ = new OperatorExpression($1, $3, '+'); }
	| mulExpr MINUS mulExpr	{ $$ = new OperatorExpression($1, $3, '-'); }
;

mulExpr:
	term
	| term MULT term	{ $$ = new OperatorExpression($1, $3, '*'); }
	| term DIV term	{ $$ = new OperatorExpression($1, $3, '/'); }
;

term:
	DOUBLE			{ $$ = new DoubleExpression($1); }
	| VARNAME       { $$ = new DoubleExpression($1); }
	| OPENPAREN addExpr CLOSEPAREN	{ $$ = new ParenExpression($2); }
;

cmp:
	EQUAL					{ $$ = "="; }
	| LESS					{ $$ = "<"; }
	| GREATER				{ $$ = ">"; }
	| LESSEQUAL				{ $$ = "<="; }
	| GREATEREQUAL			{ $$ = ">="; }
	| NOTEQUAL				{ $$ = "<>"; }
;

%%

int main(int argc, char **argv){
	std::cout << "Welcome to BASIC!\n";
	do {
		yyparse();
	} while( !feof(yyin) );
	
	return 0;
}

void yyerror(const char *s){
	std::cout << "Error: " << s << std::endl;
}

int yywrap(){
	if( yyin == stdin )
		return 1;
	fclose(yyin);
	yyin = stdin;
	return 0;
}
