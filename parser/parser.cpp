#include "parser.hpp"
using namespace std;

void Parser::move()
{ 
 	look = lexer.getNextToken(); 
}

void Parser::error(string errorMessage)
{
	cout << "near line " << Lexer::line << ": " << errorMessage;
}

void Parser::match(string t)
{
	if(look.tokenTag == t) 	move();
	else					error("Syntax error");		
}

Prog Parser::program()
{
	Block s = block();
	Prog tempProg(s);
	return tempProg;
}

Block Parser::block()
{
	match("{");
	//Env
	decls();
	Stmt s = stmts();
	match("}");
	// Env
	Block tempBlock(s);
	return tempBlock;
}

void Parser::decls()
{
	while(look.tokenTag == "BASE_TYPE")
	{
		// Type = type();
		type();
		Token tok = look;
		match("ID");
		match(";");
	}
}

void Parser::type()
{
	match("BASE_TYPE");
	// return Type
}

Stmt Parser::stmts()
{
	if(look.tokenTag == "}") 
	{
		Stmt null;
		return null;	// returning null/empty statement
	}
	else
	{
		Seq resultSeq(stmt(), stmts());
		return resultSeq;
	}
}

Stmt Parser::stmt()
{
	Stmt result;
	return result;
}
