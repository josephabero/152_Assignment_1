#pragma once

#include "../lexer/token.hpp"

class Type : public Token
{
public:
    Type(std::string s, std::string tag, int w) : type(s, tag), width(w)
    {}

    Token Int()
    {
        Token comp;
        comp.value = "int";
        comp.tokenTag = "BASE_TYPE";
        return comp;
    };

    Token Float()
    {
        Token comp;
        comp.value = "float";
        comp.tokenTag = "BASE_TYPE";
        return comp;
    };

    Token Bool()
    {
        Token comp;
        comp.value = "bool";
        comp.tokenTag = "BASE_TYPE";
        return comp;
    };

    Token type;
    int width;
};