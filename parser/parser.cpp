#include "parser.hpp"
using namespace std;

void Parser::move()
{ 
 	look = lexer.getNextToken(); 
 	cout << "Move: " << look.value << " " << look.tokenTag << endl;
}

void Parser::error(string errorMessage)
{
	cout << "near line " << Lexer::line << ": " << errorMessage << endl;
}

void Parser::match(string t)
{
	if(look.tokenTag == t) 	move();
	else					error("Syntax error");		
}

Prog Parser::program()
{
	cout << "Program" << endl;
	Block s = block();

	Prog tempProg(s);
	return tempProg;
}

Block Parser::block()
{
	cout << "Block" << endl;
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
	cout << "decls" << endl;
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
	cout << "Type" << endl;
	match("BASE_TYPE");
	// return Type
}

Stmt Parser::stmts()
{
	cout << "stmts" << endl;
	if(look.tokenTag == "}") 
	{
		Stmt null;
		return null;	// returning null/empty statement
	}
	else
	{
		Seq resultSeq(stmt(), stmt());
		return resultSeq;
	}
}

Stmt Parser::stmt()
{
	cout << "stmt" << endl;
	// Stmt result;
	// return result;

	Expr expr;
	Stmt s, s1, s2;

	cout << "stmt: " << look.tokenTag << endl;
	if(look.tokenTag == ";")
	{
		cout << "if worked: " << look.tokenTag << endl;
	}
	return s;
}
