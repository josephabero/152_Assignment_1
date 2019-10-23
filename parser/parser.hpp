#pragma once

#include "../lexer/lexer.hpp"
#include "../lexer/token.hpp"
#include "../inter/Prog.hpp"
#include "../inter/Seq.hpp"
#include "../inter/Expr.hpp"
#include "../inter/Stmt.hpp"
#include "../inter/Set.hpp"
#include "../symbols/Env.hpp"

class Parser
{
public:
	Parser(Lexer lexer) : lexer(lexer) 
	{
		used = 0;
		move();
	}

	void error(std::string errorMessage);

	void move();
	void match(std::string t);
	
	Prog* program();
	Block* block();
	void decls();
	Type* type();
	Stmt* stmt();
	Stmt* stmts();

	Stmt* assign();
	Expr* allexpr();
	Expr* andexpr();
	Expr* equality();
	Expr* rel();
	Expr* expression();
	Expr* term();
	Expr* factor();

private:
	Lexer lexer;
	Token look;
	Env top;
	int used;
};