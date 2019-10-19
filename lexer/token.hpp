#pragma once

#include <iostream>

// enum TokenTag {
//  AND,
//  BASE_TYPE,
//  BREAK,
//  DO,
//  ELSE,
//  EQ,
//  FALSE,
//  FOR,
//  GE,
//  ID,
//  IF,
//  LE,
//  NE,
//  NUM,
//  OR,
//  REAL,
//  TRUE,
//  WHILE,
//  EOF
// };

class Token {
    public: 
        Token() { 
            value   = ""; 
            tokenTag = "";
        };

        bool operator <(const Token& rhs) const
        {
        	return value < rhs.value;
        }

        Token(std::string value, std::string tokenTag) : value(value), tokenTag(tokenTag) {}


        std::string value;
        std::string tokenTag;
};