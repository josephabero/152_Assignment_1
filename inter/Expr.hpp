#pragma once

#include "../symbols/Type.hpp"
#include "../lexer/token.hpp"

class Expr : public Node
{
public:
	Expr() : type("", "", 0)
	{}

	Expr(Token token, Type type) : op(token), type(type)
	{}

	std::string getNodeStr() { return "Token " +  op.tokenTag; };

	Token op;
	Type type;
};