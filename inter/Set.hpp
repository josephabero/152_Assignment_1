#pragma once

#include "Stmt.hpp"
#include "Id.hpp"
#include "Expr.hpp"
#include "../symbols/Type.hpp"
using namespace std;

class Set : public Stmt
{
public:
	Set(Id i, Expr x): id(i), expr(x)
	{
		if(check(id.type, expr.type) == Type::Null()) cout << "Set: Type Error" << endl;
		else
		{
			children.push_back(&id);
			children.push_back(&expr);
		}
	}

	std::string getNodeStr() { return "ASSIGN"; };

	Type check(Type p1, Type p2)
	{
		if(Type::numeric(p1) && Type::numeric(p2)) 			return p2;
		else if(p1 == Type::Bool() && p2 == Type::Bool())	return p2;
		else												return Type::Null();
	}

	Id id;
	Expr expr;
};