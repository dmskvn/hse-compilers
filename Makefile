.PHONY: all clean

all: basic.tab.c lex.yy.c \
		program.h endif.h ifthen.h else.h basic.h let.h print.h for.h next.h printtext.h expression.h doubleexpression.h operatorexpression.h parenexpression.h\
		basic.cpp else.cpp double.h double.cpp let.cpp print.cpp for.cpp next.cpp printtext.cpp doubleexpression.cpp operatorexpression.cpp parenexpression.cpp \
		endif.cpp ifthen.cpp
	g++ -std=c++17 basic.tab.c lex.yy.c basic.cpp let.cpp print.cpp else.cpp endif.cpp printtext.cpp ifthen.cpp for.cpp \
	next.cpp doubleexpression.cpp operatorexpression.cpp parenexpression.cpp -o basic

basic.tab.c: basic.y basic.h
	bison -d basic.y
	
basic.tab.h: basic.y
	bison -d basic.y

lex.yy.c: basic.tab.h basic.l
	flex basic.l

clean:
	rm basic.tab.c basic.tab.h lex.yy.c basic *.o