%option case-insensitive

%{
    
#include <cstdio>
#include <iostream>
#include <vector>

#define YY_DECL extern "C" int yylex()

class IProgram;

#include "basic.tab.h"

%}

ALPHA [A-Z]
DIGIT [0-9]

%%

(({DIGIT}+"."?)|("."{DIGIT}+)){DIGIT}*(E-?{DIGIT}+)?	{ std::cout << "L DOUBLE" << std::endl; yylval.dVal = atof(yytext); return DOUBLE; }

[ \t]+	;
\n              { return ENDL; }
{ALPHA}{DIGIT}?	{ std::cout << "L VARNAME" << std::endl; yylval.sVal = strdup(yytext); return VARNAME; }
{DIGIT}+		{ yylval.iVal = atoi(yytext); return INTEGER; }
PRINT			{ return PRINT; }
LET				{ std::cout << "L LET" << std::endl; return LET; }
LIST			{ return LIST; }
LOAD			{ return LOAD; }
EXEC			{ return EXEC; }
\=				{ std::cout << "L EQUAL" << std::endl; return EQUAL; }
.	;

%%