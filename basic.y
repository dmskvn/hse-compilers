// A BASIC grammar interpreter

%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yywrap();

void yyerror(const char *s);

%}

// token type definition
%union {
	int iVal;
	double dVal;
	char* sVal;
}

// constant tokens
%token PRINT
%token LET
%token EQUAL


// terminal symbols
%token <iVal> INTEGER
%token <dVal> DOUBLE
%token <sVal> VARNAME

%% /* Grammar rules and actions follow */

program:
	PRINT INTEGER		{}
	| LET VARNAME EQUAL DOUBLE
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