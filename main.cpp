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
    // lexer.input = "Hello 123";
    cout << lexer.input;
 
    Token token_peek[100];
 
 	// Iterate through each token to determine the type of token
    int index = 0;
    for(auto it = lexer.input.begin(); it < lexer.input.end(); ++it, ++index)
    {
    	token_peek[index] = lexer.getNextToken();
    }
    

    // cout << endl << endl << endl
    //     << "TAG: " << lexer.token.tokenTag << endl
    //     << "VALUE: " << lexer.token.value << endl;

    // Print final values
    for(int i = 0; i < 100; i++)
    {
    	cout << "VALUE: " << token_peek[i].value << endl;
    }
    
    // exit(1)
}