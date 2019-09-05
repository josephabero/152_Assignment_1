#include <iostream>
#include "token.cpp"
using namespace std;

class Lexer {
public:
	Lexer() { 
		input = "";
	};
	Token getNextToken();
	Token token;
	string input;
};


/*
	Iterates through Lexer string value and tries to find end of token value.
	Returns token value if valid.
*/
Token Lexer::getNextToken()
{
	int index = 0;
	for(auto it = input.begin(); it < input.end(); ++it, ++index)
	{
		cout << index << " " << *it << endl;
		token.value += *it;
	}

	return token;
}

int main ()
{
	// Token token;
	// string test = "Hello World\n";
	// cout << test;
	// token.value = test;
	// cout << token.value;
	Lexer lexer;
	lexer.input = "Hello World";
	cout << lexer.input;
	lexer.getNextToken();

	cout << lexer.token.value;
	// exit(1);
}