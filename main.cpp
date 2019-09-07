#include <iostream>
#include "lexer.cpp"
using namespace std;

int main ()
{
    Lexer lexer;
    lexer.input = 
    	"{ \
    		int b; b = 1; \
    		{ \
    			int a; a = 2; do a = a+1; while(a < 100); \
    		} \
    	}";
    // cout << lexer.input << " length: " << lexer.input.length() << endl;


    // -- REQUIRED -- : Find data struct for tokens & implement in Lexer class
    Token token_peek[lexer.input.length()];
 
 	// Iterate through each token to determine the TYPE and VALUE of token
    int index = 0;
    for(auto it = lexer.input.begin(); it < lexer.input.end(); ++it, ++index)
    {
    	token_peek[index] = lexer.getNextToken();
    }
    

    // Print final token VALUES 
    // -- REQUIRED -- : Print final token TYPE
    for(int i = 0; i < lexer.input.length(); i++)
    {
    	cout << token_peek[i].tokenTag << " " << token_peek[i].value << endl;
    }
}