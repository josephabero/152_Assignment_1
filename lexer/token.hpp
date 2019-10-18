#pragma once

#include <iostream>
using namespace std;

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
        string value;
        string tokenTag;
};