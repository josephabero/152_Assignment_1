#pragma once

#include "Stmt.hpp"

class Block : public Stmt
{
public:
	Stmt *stmt;

	Block(Stmt *stmt) : stmt(stmt)
	{
		std::cout << "push_back from Block\n";
		children.push_back(stmt);
	}

	std::string getNodeStr() { return "BLOCK"; };
};