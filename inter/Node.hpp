#pragma once

#include "../lexer/lexer.hpp"
#include <vector>

#define ASSERT(condition, message) { if(!(condition)){ std::cerr << "assert: " << #message << " (LINE: " << __LINE__ << ")" << " in file " << __FILE__ << std::endl; exit(0); } }

class Node
{
public:
	int lexline = 0;
	std::vector<Node*> children;
	Node() 
	{
		lexline = Lexer::line;
	}

	std::vector<Node*> getChildren() { return children; }

	virtual std::string getNodeStr() { return ""; };
};