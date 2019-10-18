all: main

main: main.o lexer/lexer.o
	 g++ -std=c++11 -o main.exe main.o lexer/lexer.o

main.o: main.cpp
	 g++ -std=c++11 -c main.cpp main.o

lexer.o:
	 g++ -std=c++11-c lexer/lexer.o lexer.o

run:
	 ./main.exe

clean:
	 rm main.o main.exe