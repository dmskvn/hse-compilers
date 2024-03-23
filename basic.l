%option case-insensitive
%option yylineno

%{
    
#include <cstdio>
#include <iostream>
#include <vector>

#define YY_DECL extern "C" int yylex()

class IProgram;
class IExpression;

#include "basic.tab.h"

%}

ALPHA [A-Z]
DIGIT [0-9]
%%

(({DIGIT}+"."?)|("."{DIGIT}+)){DIGIT}*(E-?{DIGIT}+)?	{ yylval.dVal = atof(yytext); return DOUBLE; }

[ \t]+	;
\n              { return ENDL; }
{ALPHA}{DIGIT}?	{ yylval.sVal = strdup(yytext); return VARNAME; }
"\""{ALPHA}+"\""	    { yylval.sVal = strdup(yytext); return TEXT; }
{DIGIT}+		{ yylval.iVal = atoi(yytext); return INTEGER; }
IF		        { return IF; }
THEN		    { return THEN; }
ELSE		    { return ELSE; }
END             { return END; }
FOR             { return FOR; }
TO              { return TO; }
NEXT            { return NEXT; }
\=				{ return EQUAL; }
\<				{ return LESS; }
\>				{ return GREATER; }
\<\=			{ return LESSEQUAL; }
\>\=			{ return GREATEREQUAL; }
\<\>			{ return NOTEQUAL; }
PRINT			{ return PRINT; }
LET				{ return LET; }
LIST			{ return LIST; }
LOAD			{ return LOAD; }
EXEC			{ return EXEC; }
\=				{ return EQUAL; }
\+				{ return PLUS; }
-				{ return MINUS; }
\*				{ return MULT; }
\(				{ return OPENPAREN; }
\)				{ return CLOSEPAREN; }
\/				{ return DIV; }
.	;

%%