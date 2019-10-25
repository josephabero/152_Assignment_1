#pragma once

#include "Expr.hpp"
#include "../lexer/token.hpp"
#include "../symbols/Type.hpp"
#include <assert.h>

class Logical : public Expr
{
public:
	Logical(Token token, Expr expr1, Expr expr2) : Expr(token, Type::Null()), expr1(expr1), expr2(expr2)
	{
		type = check(expr1.type, expr2.type); // uses Expr's type member var
		// if(type == Type::Null()) error("Type Error");

		// Type Error
		assert(type == Type::Null());
		std::cout << "push_back from Logical" << std::endl;
		children.push_back(&expr1);
		children.push_back(&expr2);
	}

	Type check(Type p1, Type p2)
	{
		if(p1 == Type::Bool() && p2 == Type::Bool()) return Type::Bool();
		else return Type::Null();
	}

	Expr expr1;
	Expr expr2;
};