.PHONY: all clean

all: basic.tab.c lex.yy.c \
		program.h expr.h endif.h ifthen.h else.h basic.h let.h print.h  \
		basic.cpp else.cpp double.h double.cpp let.cpp print.cpp \
		endif.cpp ifthen.cpp
	g++ -std=c++17 basic.tab.c lex.yy.c basic.cpp let.cpp print.cpp else.cpp endif.cpp ifthen.cpp -o basic

basic.tab.c: basic.y basic.h
	bison -d basic.y
	
basic.tab.h: basic.y
	bison -d basic.y

lex.yy.c: basic.tab.h basic.l
	flex basic.l

clean:
	rm basic.tab.c basic.tab.h lex.yy.c basic *.o