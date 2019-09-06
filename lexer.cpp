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

    // -- REQUIRED -- : Label Tags
    // -- REQUIRED -- : Data struct to store tokens (HashMap?, Array?, etc...)
};


/*
    Iterates through Lexer string value and tries to find end of token value.
    Returns token value if valid.

    Steps:
    1. Remove whitespace
    2. Check for basic Tokens (&, &&, |, ||, etc..)
    3. Check for digits
    4. Check for letters
    5. Store any other symbol ( {, }, ;, (, ), etc...)
    6. Return token
*/
Token Lexer::getNextToken()
{
    char peek = ' ';
    Token temp_token;

    // 1. Ignore Token if it is whitespace
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

    // 2. Check for basic tokens (&, &&, |, ||, etc...)
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

    // 3. Check for digits (iterate until full number is stored)
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

    // 4. Check for letters (iterate until full word is stored)
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

    // 5. Store any other symbol ( {, }, ;, (, ), etc... )
    else
    {
        string_index++;
        temp_token.value = peek;
    }

    // 6. Return token value that was found
    return temp_token;
}