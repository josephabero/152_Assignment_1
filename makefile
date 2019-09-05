all: lex.exe

lex.exe: lex.o
	 g++ -o lex.exe lex.o

lex.o: lex.cpp
	 g++ -c lex.cpp

clean:
	 rm lex.o lex.exe