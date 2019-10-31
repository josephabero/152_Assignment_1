#pragma once

#include "Op.hpp"
#include "Expr.hpp"
#include <assert.h>

class IncDec : public Op
{
public:
	IncDec(Token token, Expr *expr1/*, Expr *expr2*/) : Op(token, Type::Null()), expr1(expr1)//, expr2(expr2)
	{
		//type = Type::max(expr1->type, expr2->type);
		type = expr1->type;
		ASSERT(type == Type::Null(), "TYPE ERROR");
		std::cout << "push_back from Increment/Decrement" << std::endl;
		children.push_back(expr1);
		//children.push_back(expr2);
	}

	std::string getNodeStr() { return "Token " + op.tokenTag; };

	Expr *expr1;
	//Expr *expr2;
};