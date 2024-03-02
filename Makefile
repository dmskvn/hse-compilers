.PHONY: all clean

all: basic.tab.c lex.yy.c \
		program.h expr.h basic.h basic.cpp double.h double.cpp let.h let.cpp print.h print.cpp 
	g++ -std=c++17 basic.tab.c lex.yy.c basic.cpp let.cpp print.cpp -o basic

basic.tab.c: basic.y basic.h
	bison -d basic.y
	
basic.tab.h: basic.y
	bison -d basic.y

lex.yy.c: basic.tab.h basic.l
	flex basic.l

clean:
	rm basic.tab.c basic.tab.h lex.yy.c basic *.o