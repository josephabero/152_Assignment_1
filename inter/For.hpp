#pragma once

#include "Stmt.hpp"
#include <assert.h>

class For : public Stmt
{
public:
    For() {}

    void init(Expr *x1, Expr *x2, Stmt *s)
    {
        expr = x;
        stmt = s;

        // Boolean required in While
        // assert(!(expr->type == Type::Bool()));
        ASSERT(!(expr->type == Type::Bool()), "TYPE ERROR");

        std::cout << "push_back from While" << std::endl;
        std::cout << "W1: " << expr->getNodeStr() << std::endl;
        std::cout << "W2: " << stmt->getNodeStr() << std::endl;
        children.push_back(expr);
        children.push_back(stmt);

    }

    std::string getNodeStr() { return "WHILE"; };

    Expr *expr;
    Stmt *stmt;
};
