#pragma once

class Constant : public Expr
{
public:
	Constant() {}
	Constant(Token token, Type type) : Expr(token, type) {}

	static Constant* True()
	{
		Token tok;
		tok.value = "true";
		tok.value = "TRUE";
		Constant* constant = new Constant(tok, Type::Bool());
		
		return constant;
	}

	static Constant* False()
	{
		Token tok;
		tok.value = "false";
		tok.value = "FALSE";
		Constant* constant = new Constant(tok, Type::Bool());
		
		return constant;
	}


	std::string getNodeStr() { return "Token " + op.value; }
};