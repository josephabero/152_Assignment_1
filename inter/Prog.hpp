#pragma once

#include "Node.hpp"
#include "Block.hpp"

class Prog : public Node
{
public:
	Prog(Block block) : block(block)
	{
		std::cout << "push_back from Program\n";
		children.push_back(block);
	}

	std::string getNodeStr() { return "PROGRAM"; };

	
	Block block;
};