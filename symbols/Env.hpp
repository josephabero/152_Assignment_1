#pragma once

#include <map>
#include <iterator>
#include "../lexer/token.hpp"
#include "../inter/Id.hpp"

class Env
{
public:
	Env() {}

	void put(Token w, Id *i)
	{
		table.insert(std::pair<Token, Id>(w, *i));
	}

	Id get(Token w)
	{
		Id found;

		std::map<Token, Id>::iterator itr;
		for(itr = table.begin(); itr != table.end(); ++itr)
		{
			found = itr->second; // get Id
			break;
		}
		return found;
	}
private:
	std::map<Token, Id> table;
protected:
	static Env prev;
};