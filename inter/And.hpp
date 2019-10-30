#pragma once

#include "../lexer/token.hpp"
#include "Logical.hpp"

class And : public Logical
{
public:
	And(Token token, Expr *expr1, Expr *expr2) : Logical(token, expr1, expr2) {}

	std::string getNodeStr() { return "AND"; };
};