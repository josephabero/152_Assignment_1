#pragma once

#include "../lexer/token.hpp"

class Type : public Token
{
public:
	Type() {}
	
    Type(std::string s, std::string tag, int w) : type(s, tag), width(w)
    {}

    static Type Int()
    {
        Type comp;
        comp.value = "int";
        comp.tokenTag = "BASE_TYPE";
        return comp;
    };

    static Type Float()
    {
        Type comp;
        comp.value = "float";
        comp.tokenTag = "BASE_TYPE";
        return comp;
    };

    static Type Bool()
    {
        Type comp;
        comp.value = "bool";
        comp.tokenTag = "BASE_TYPE";
        return comp;
    };

    static Type Null()
    {
    	Type comp;
    	comp.value = "";
    	comp.tokenTag = "";
    	return comp;
    };

    static bool numeric(Type p)
    {
    	return (p == Type::Int() || p == Type::Float());
    };

    static Type max(Type p1, Type p2)
    {
    	if( ! numeric(p1) || ! numeric(p2) ) 					return Null();
    	else if ( p1 == Type::Float() || p2 == Type::Float()) 	return Float();
    	else if( p1 == Type::Int() || p2 == Type::Int()) 		return Int();
    };

    bool operator ==(const Type& rhs)
    {
    	return((type.value == rhs.value) && (type.tokenTag == rhs.tokenTag));
    };

    Token type;
    int width;
};