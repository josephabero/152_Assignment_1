all: main

main: main.o lexer.o
	 g++ -std=c++11 -o main.exe main.o lexer.o

main.o: main.cpp
	 g++ -std=c++11 -c main.cpp

lexer.o:
	 g++ -std=c++11 -c lexer/lexer.cpp

run:
	 ./main.exe

clean:
	 rm main.o lexer.o main.exe