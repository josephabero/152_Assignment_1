#pragma once

#include "Expr.hpp"
#include "../lexer/token.hpp"
#include "../symbols/Type.hpp"

class Logical : public Expr
{
public:
	Logical(Token token, Expr expr1, Expr expr2) : Expr(token, NULL), expr1(expr1), expr2(expr2)
	{
		type = check(expr1.type, expr2.type); // uses Expr's type member var
		if(type == NULL) error("Type Error");
		cout << "push_back from Logical" << endl;
		children.push_back(expr1);
		children.push_back(expr2);
	}

	Type check(Type p1, Type p2)
	{
		if(p1 == Type::bool() && p2 == Type::bool()) return Type::bool();
		else return NULL;
	}

	Expr expr1;
	Expr expr2;
}