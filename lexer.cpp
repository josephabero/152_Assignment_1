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
    char peek;
    int index = 0;

    
    for(auto it = input.begin(); it < input.end(); ++it, ++index)
    {
        // cout << index << " " << *it << endl;
        if(isalpha(*it))
        {
            token.value += *it;
        }
        else if(isdigit(*it))
        {
            token.value += *it;
        }
    }

    return token;
}