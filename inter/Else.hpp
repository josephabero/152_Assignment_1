#pragma once

#include "Stmt.hpp"
#include <assert.h>

class Else : public Stmt
{
public:
	Else(Expr *x, Stmt *s1, Stmt *s2) : stmt2(s2), stmt1(s1), expr(x)
	{
		// Type Error: Boolean is Required in Else
		assert(!(expr->type == Type::Bool()));

		std::cout << "push_back in Else" << std::endl;
		std::cout << "E1: " << expr->getNodeStr() << std::endl;
        std::cout << "E2: " << stmt1->getNodeStr() << std::endl;
        std::cout << "E3: " << stmt2->getNodeStr() << std::endl;
        children.push_back(expr);
        children.push_back(stmt1);
        children.push_back(stmt2);
	}

	std::string getNodeStr() { return "IF-ELSE"; }

	Expr *expr;
	Stmt *stmt1;
	Stmt *stmt2;
};