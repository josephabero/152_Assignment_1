#pragma once

#include "Stmt.hpp"

class Seq : public Stmt
{
public:
	Stmt stmt1;
	Stmt stmt2;

	Seq(Stmt s1, Stmt s2) : stmt1(s1), stmt2(s2)
	{
		std::cout << "push_back from Seq\n";
		children.push_back(s1);
		children.push_back(s2);
	}

	std::string getNodeStr() { return "STMTS"; }
};