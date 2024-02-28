%option case-insensitive

%{
    
#include <cstdio>
#include <iostream>
#include <vector>

#define YY_DECL extern "C" int yylex()

#include "basic.tab.h"

%}

ALPHA [A-Z]
DIGIT [0-9]

%%

[ \t]+	;
{ALPHA}{DIGIT}?	{ yylval.sVal = strdup(yytext); return VARNAME; }
{DIGIT}+		{ yylval.iVal = atoi(yytext); return INTEGER; }
PRINT			{ return PRINT; }
LET				{ return LET; }
\=				{ return EQUAL; }
.	;

%%