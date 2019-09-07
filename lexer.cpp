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

        // cout << endl << peek << " " << string_index << endl;

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
                temp_token.tokenTag = "AND";
            }
            else
            {
                temp_token.value = "&";
                temp_token.tokenTag = "&";
            }
        case '|':
            if( input[string_index + 1] == '|' )
            {
                string_index++;
                temp_token.value = "||";
                temp_token.tokenTag = "OR";
            }
            else
            {
                temp_token.value = '|';
                temp_token.tokenTag = "|";
            }
        case '=':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = "==";
                temp_token.tokenTag = "EQ";
            }
            else
            {
                temp_token.value = '=';
                temp_token.tokenTag = "=";
            }
        case '!':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = "!=";
                temp_token.tokenTag = "NE";
            }
            else
            {
                temp_token.value = '!';
                temp_token.tokenTag = "!";
            }
        case '<':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = "<=";
                temp_token.tokenTag = "LE";
            }
            else
            {
                temp_token.value = '<';
                temp_token.tokenTag = "<";
            }
        case '>':
            if( input[string_index + 1] == '=' )
            {
                string_index++;
                temp_token.value = ">=";
                temp_token.tokenTag = "GE";
            }
            else
            {
                temp_token.value = '>';
                temp_token.tokenTag = ">";
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
        temp_token.tokenTag = "NUM";

        if(peek == '.')
        {
            do
            {
                temp_token.value += peek;
                peek = input[string_index++];
            } while(isdigit(peek));
            temp_token.tokenTag = "REAL";
        }

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
        temp_token.tokenTag = "ID";

        // switch(temp_token.value)
        // {
        //     case "int": temp_token.tokenTag = "BASE_TYPE";
        //     case "float": temp_token.tokenTag = "BASE_TYPE";
        //     case "bool": temp_token.tokenTag = "BASE_TYPE";
        //     case "break": temp_token.tokenTag = "BREAK";
        //     case "do": temp_token.tokenTag = "DO";
        //     case "else": temp_token.tokenTag = "ELSE";
        //     case "false": temp_token.tokenTag = "FALSE";
        //     case "true": temp_token.tokenTag = "TRUE";
        //     case "while": temp_token.tokenTag = "WHILE";
        // }
        if(temp_token.value == "int") temp_token.tokenTag = "BASE_TYPE";
        else if(temp_token.value == "float") temp_token.tokenTag = "BASE_TYPE";
        else if(temp_token.value == "bool") temp_token.tokenTag = "BASE_TYPE";
        else if(temp_token.value == "break") temp_token.tokenTag = "BREAK";
        else if(temp_token.value == "do") temp_token.tokenTag = "DO";
        else if(temp_token.value == "else") temp_token.tokenTag = "ELSE";
        else if(temp_token.value == "false") temp_token.tokenTag = "FALSE";
        else if(temp_token.value == "true") temp_token.tokenTag = "TRUE";
        else if(temp_token.value == "while") temp_token.tokenTag = "WHILE";
        
        string_index--;
    }

    // 5. Store any other symbol ( {, }, ;, (, ), etc... )
    else
    {
        string_index++;
        temp_token.value = peek;
        temp_token.tokenTag = peek;
    }

    // 6. Return token value that was found
    return temp_token;
}