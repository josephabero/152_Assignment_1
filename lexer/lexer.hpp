#pragma once

#include <iostream>
#include "token.hpp"

class Lexer {
	static int line;
public:
    Token token;
    string input;
    int current_lexer_index = 0;

    Lexer() { 
        input = "";
    };
    
    Token getNextToken();

    // -- REQUIRED -- : Label Tags
    // -- REQUIRED -- : Data struct to store tokens (HashMap?, Array?, etc...)
};