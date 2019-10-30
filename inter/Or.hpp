#pragma once

#include "Logical.hpp"

class Or : public Logical
{
public:
	Or(Token token, Expr *expr1, Expr *expr2) : Logical(token, expr1, expr2) {}

	std::string getNodeStr() { return "OR"; }
};