#pragma once

#include "Stmt.hpp"
#include <assert.h>

class Do : public Stmt
{
public:
    Do() {}

    void init(Stmt *s, Expr *x)
    {
        expr = x;
        stmt = s;

        // Boolean required in Do
        // assert(!(expr->type == Type::Bool()));
        ASSERT(!(expr->type == Type::Bool()), "TYPE ERROR");

        std::cout << "push_back from Do" << std::endl;
        std::cout << "D1: " << expr->getNodeStr() << std::endl;
        std::cout << "D2: " << stmt->getNodeStr() << std::endl;
        children.push_back(expr);
        children.push_back(stmt);

    }

    std::string getNodeStr() { return "DO"; };

    Expr *expr;
    Stmt *stmt;
};
