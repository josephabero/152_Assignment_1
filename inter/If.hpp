#pragma once

#include "Stmt.hpp"
#include <assert.h>

class If : public Stmt
{
public:
	If(Expr *x, Stmt *s) : stmt(s), expr(x)
	{
		// Type Error: Boolean is Required in IF
		assert(!(expr->type == Type::Bool()));

		std::cout << "push_back in If" << std::endl;
		std::cout << "I1: " << expr->getNodeStr() << std::endl;
        std::cout << "I2: " << stmt->getNodeStr() << std::endl;
        children.push_back(expr);
        children.push_back(stmt);

        for(int i = 0; i < children.size(); i++)
        {
        	std::cout << "HI: " << children[i]->getNodeStr() << std::endl;
        }
	}

	std::string getNodeStr() { return "IF"; }

	Expr *expr;
	Stmt *stmt;
};