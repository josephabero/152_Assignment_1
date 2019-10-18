#pragma once

#include "../lexer/lexer.hpp"
#include <vector>

class Node
{
public:
	int lexline = 0;
	vector<Node> children;
	Node() 
	{
		lexline = Lexer::line;
	}

	vector<Node> getChildren() { return children; }

	std::string getNodeStr() { return ""; }
};