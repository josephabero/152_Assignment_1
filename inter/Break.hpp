#pragma once

#include "Stmt.hpp"

class Break : public Stmt
{
public:
	Break()
	{
		// if(Stmt.Enclosing == Stmt.Null) error("unenclosed break;")
		// stmt = Stmt.Enclosing
	}

	std::string getNodeStr() { return "BREAK"; }

	Stmt stmt;
};