#pragma once

#include "Node.hpp"

class Stmt : public Node
{
public:
	Stmt() { Node(); after = 0; }

	int after;

	// static Stmt Null = new Stmt()
	// static Stmt Enclosing = Stmt.Null
};