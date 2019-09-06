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
    int string_index = 0;
};


/*
    Iterates through Lexer string value and tries to find end of token value.
    Returns token value if valid.

    Steps:
    1. Remove whitespace
    2. Check for basic Tokens (&, &&, |, ||, etc..)
    3. Check for digits
    4. Check for letters
    5. Return token
*/
Token Lexer::getNextToken()
{
    char peek = ' ';
    Token temp_token;

    // for(auto it = input.begin(); it < input.end(); ++it, ++index)
    // {
    //     peek = *it;

    //     if( peek == ' ' || peek == '\t' ) continue;
    //     else if( peek == '\n') line_length = line_length + 1;
    //     else break;
    // }


    for(int i = string_index; i < input.length(); i++)
    {
        peek = input[string_index];

        cout << endl << peek << " " << string_index << endl;

        if( peek == ' ' || peek == '\t' || peek == '\n')
        {
            string_index++;
            continue;
        }
        else break;
    }

    switch(peek)
    {
        case '&':
            if( input[string_index + 1] == '&' )
            {
                string_index++;
                temp_token.value = "&&";
            }
            else
            {
                temp_token.value = "&";
            }
        case '|':
            if( input[string_index + 1] == '|' )
            {
                string_index++;
                temp_token.value = "||";
            }
            else
            {
                temp_token.value = '|';
            }
        case '=':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = "==";
            }
            else
            {
                temp_token.value = '=';
            }
        case '!':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = "!=";
            }
            else
            {
                temp_token.value = '!';
            }
        case '<':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = "<=";
            }
            else
            {
                temp_token.value = '<';
            }
        case '>':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = ">=";
            }
            else
            {
                temp_token.value = '>';
            }
    }


    if(isdigit(peek))
    {
        string_index++;
        do
        {
            temp_token.value += peek;
            peek = input[string_index++];
        } while(isdigit(peek));
        string_index--;
    }
    else if(isalpha(peek))
    {
        string_index++;
        do
        {
            temp_token.value += peek;
            peek = input[string_index++];
        } while(isalpha(peek));
        string_index--;
    }
    else
    {
        string_index++;
        temp_token.value = peek;
    }

    return temp_token;
}