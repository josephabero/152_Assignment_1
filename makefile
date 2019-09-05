all: lexer.exe

lexer.exe: lexer.o
	 g++ -o lexer.exe lexer.o

lexer.o: lexer.cpp
	 g++ -c lexer.cpp

run:
	 ./lexer.exe

clean:
	 rm lexer.o lexer.exe