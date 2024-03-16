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

%}

// token type definition
%union {
	int iVal;
	double dVal;
	IProgram *progVal;
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

// terminal symbols
%token <iVal> INTEGER
%token <dVal> DOUBLE
%token <sVal> VARNAME

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
		std::cout << "Y STM ENDL" << std::endl;
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
	LIST {std::cout << "Y LIST" << std::endl; Basic::instance()->list();}
	| LOAD {std::cout << "Y LOAD" << std::endl; Basic::instance()->load();}
	| EXEC {std::cout << "Y EXEC" << std::endl; Basic::instance()->exec();}
	| program { std::cout << "!!PROGRAM " << std::endl; Basic::instance()->add($1);}
;

program:
	LET VARNAME EQUAL DOUBLE { std::cout << "!! LET " << std::endl; $$ = new Let($2, $4);}
	| FOR VARNAME EQUAL DOUBLE TO VARNAME {std::cout << "!! FOR " << std::endl; $$ = new For($2, $4, $6);}
	| IF VARNAME cmp VARNAME THEN {std::cout << "!! IF " << std::endl; $$ = new IfThen($2, $3, $4);}
	| ELSE {std::cout << "!! ELSE " << std::endl; $$ = new Else();}
	| END IF {std::cout << "!! END IF" << std::endl; $$ = new EndIf();}
	| NEXT {std::cout << "!! NEXT" << std::endl; $$ = new Next();}
	| PRINT VARNAME {  std::cout << "!! PRINT" << std::endl; $$ = new Print($2);}
;

cmp:
	EQUAL					{ std::cout << "!! EQ " << std::endl;  $$ = "="; }
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