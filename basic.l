%option case-insensitive
%option yylineno

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
"\""{ALPHA}+"\""	    { std::cout << "L TEXT" << std::endl; yylval.sVal = strdup(yytext); return TEXT; }
{DIGIT}+		{ yylval.iVal = atoi(yytext); return INTEGER; }
IF		        { std::cout << "L IF" << std::endl;  return IF; }
THEN		    { std::cout << "L THEN" << std::endl; return THEN; }
ELSE		    { std::cout << "L ELSE" << std::endl; return ELSE; }
END             { std::cout << "L END" << std::endl; return END; }
FOR             { std::cout << "L FOR" << std::endl; return FOR; }
TO              { std::cout << "L TO" << std::endl; return TO; }
NEXT            { std::cout << "L NEXT" << std::endl; return NEXT; }
\=				{ return EQUAL; }
\<				{ return LESS; }
\>				{ return GREATER; }
\<\=			{ return LESSEQUAL; }
\>\=			{ return GREATEREQUAL; }
\<\>			{ return NOTEQUAL; }
PRINT			{ return PRINT; }
LET				{ std::cout << "L LET" << std::endl; return LET; }
LIST			{ return LIST; }
LOAD			{ return LOAD; }
EXEC			{ return EXEC; }
\=				{ std::cout << "L EQUAL" << std::endl; return EQUAL; }
.	;

%%