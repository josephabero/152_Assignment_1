#pragma once

#include "Logical.hpp"

class Rel : public Logical
{
public:
    Rel(Token token, Expr *expr1, Expr *expr2) : Logical(token, expr1, expr2) {}

    Type check(Type p1, Type p2)
    {
        if(p1 == p2) return Type::Bool();
        else         return Type::Null();
    }
};
