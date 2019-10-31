#include <iostream>
#include "token.hpp"
#include "lexer.hpp"
using namespace std;


int Lexer::line = 0;

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
    // -I- Initialize variables
    char peek = input[current_lexer_index];
    Token temp_token;

    // 1. Ignore Token if it is whitespace (iterates input until no whitespace is found)
    while(peek == ' ' || peek == '\t' || peek == '\n')
    {
        if(peek == '\n') Lexer::line += 1;
        peek = input[++current_lexer_index];
    }

    // 2. Check if character is a basic token (&, &&, |, ||, etc...)
    // If not a basic character, default to 3, 4, 5
    switch(peek)
    {
        case '&':
            if( input[current_lexer_index + 1] == '&' )
            {
                current_lexer_index += 2;
                temp_token.value = "&&";
                temp_token.tokenTag = "AND";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = "&";
                temp_token.tokenTag = "&";
            }
            break;
        case '|':
            if( input[current_lexer_index + 1] == '|' )
            {
                current_lexer_index += 2;
                temp_token.value = "||";
                temp_token.tokenTag = "OR";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = '|';
                temp_token.tokenTag = "|";
            }
            break;
        case '=':
            if( input[current_lexer_index + 1] == '=' )
            {
                current_lexer_index += 2;
                temp_token.value = "==";
                temp_token.tokenTag = "EQ";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = '=';
                temp_token.tokenTag = "=";
            }
            break;
        case '!':
            if( input[current_lexer_index + 1] == '=' )
            {
                current_lexer_index += 2;
                temp_token.value = "!=";
                temp_token.tokenTag = "NE";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = '!';
                temp_token.tokenTag = "!";
            }
            break;
        case '<':
            if( input[current_lexer_index + 1] == '=' )
            {
                current_lexer_index += 2;
                temp_token.value = "<=";
                temp_token.tokenTag = "LE";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = '<';
                temp_token.tokenTag = "<";
            }
            break;
        case '>':
            if( input[current_lexer_index + 1] == '=' )
            {
                current_lexer_index += 2;
                temp_token.value = ">=";
                temp_token.tokenTag = "GE";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = '>';
                temp_token.tokenTag = ">";
            }
            break;
        case '+':
            if( input[current_lexer_index + 1] == '+' )
            {
                current_lexer_index += 2;
                temp_token.value = "++";
                temp_token.tokenTag = "++";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = '+';
                temp_token.tokenTag = '+';
            }
            break;
        case '-':
            if( input[current_lexer_index + 1] == '-' )
            {
                current_lexer_index += 2;
                temp_token.value = "--";
                temp_token.tokenTag = "--";
            }
            else
            {
                current_lexer_index++;
                temp_token.value = '-';
                temp_token.tokenTag = '-';
            }
            break;
        default:
            // 3. Check for digits
            if(isdigit(peek))
            {
                current_lexer_index++;

                // -I- Iterate until full number is stored
                do
                {
                    temp_token.value += peek;
                    peek = input[current_lexer_index++];
                } while(isdigit(peek));

                // -I- Assume it is a generic number, then check if it's REAL
                temp_token.tokenTag = "NUM";
        
                // -I- Check if number is REAL
                if(peek == '.')
                {
                    do
                    {
                        temp_token.value += peek;
                        peek = input[current_lexer_index++];
                    } while(isdigit(peek));
                    temp_token.tokenTag = "REAL";
                }
        
                current_lexer_index--;
            }
        
            // 4. Check for letters
            else if(isalpha(peek))
            {
                current_lexer_index++;

                // -I- Iterate until full word is stored
                do
                {
                    temp_token.value += peek;
                    peek = input[current_lexer_index++];
                } while(isalpha(peek));

                // -I- Assume it is an ID, then check if it's a keyword
                temp_token.tokenTag = "ID";

                // -I- Check if word is a keyword
                if(temp_token.value == "int")           temp_token.tokenTag = "BASE_TYPE";
                else if(temp_token.value == "float")    temp_token.tokenTag = "BASE_TYPE";
                else if(temp_token.value == "bool")     temp_token.tokenTag = "BASE_TYPE";
                else if(temp_token.value == "break")    temp_token.tokenTag = "BREAK";
                else if(temp_token.value == "do")       temp_token.tokenTag = "DO";
                else if(temp_token.value == "else")     temp_token.tokenTag = "ELSE";
                else if(temp_token.value == "false")    temp_token.tokenTag = "FALSE";
                else if(temp_token.value == "true")     temp_token.tokenTag = "TRUE";
                else if(temp_token.value == "while")    temp_token.tokenTag = "WHILE";
                else if(temp_token.value == "if")       temp_token.tokenTag = "IF";
                
                current_lexer_index--;
            }

            else if(peek == std::cin.eof())
            {
                // cout << current_lexer_index << " EOF" << endl;
                current_lexer_index++;
                temp_token.value = "null";
                temp_token.tokenTag = "EOF";
            }
        
            // 5. Store any other symbol ( {, }, ;, (, ), etc... )
            else
            {
                current_lexer_index++;
                temp_token.value = peek;
                temp_token.tokenTag = peek;
            }
    }


    // 6. Return token value that was found
    return temp_token;
}