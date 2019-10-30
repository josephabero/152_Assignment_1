#pragma once

#include "Node.hpp"

class Stmt : public Node
{
public:
	Stmt() { Node(); }

	int after = 0;

	// static Stmt Null = new Stmt()
	// static Stmt Enclosing = Stmt.Null
};