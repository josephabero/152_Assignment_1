all: main

main: main.o lexer.o parser.o
	 g++ -std=c++11 -o main.exe main.o lexer.o parser.o

main.o: main.cpp
	 g++ -std=c++11 -c main.cpp

lexer.o:
	 g++ -std=c++11 -c lexer/lexer.cpp

parser.o:
	 g++ -std=c++11 -c parser/parser.cpp

run:
	 ./main.exe

clean:
	 rm main.o lexer.o parser.o main.exe