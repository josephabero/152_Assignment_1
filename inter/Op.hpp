#pragma once

#include "Expr.hpp"
#include "../lexer/token.hpp"

class Op : public Expr
{
public:
	Op(Token token, Type p) : Expr(token, p) {}
};