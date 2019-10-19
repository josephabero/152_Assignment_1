#pragma once

class Id : public Expr
{
public:
    Id() {}
    Id(Token id, Type p, int b) : Expr(id, p), offset(b) {}

    int offset;
};