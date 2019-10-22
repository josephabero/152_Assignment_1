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
    if(look.tokenTag == t)  move();
    else                    error("Syntax error");      
}

Prog* Parser::program()
{
    cout << "Program" << endl;
    Block s = block();

    Prog *tempProg = new Prog(s);
    cout << "End Program" << endl;
    return tempProg;
}

Block Parser::block()
{
    cout << "Block" << endl;
    match("{");
    Env savedEnv = top;
    decls();
    Stmt s = stmts();
    match("}");
    top = savedEnv;

    Block tempBlock(s);
    cout << "End Block" << endl;
    return tempBlock;
}

void Parser::decls()
{
    cout << "decls" << endl;
    while(look.tokenTag == "BASE_TYPE")
    {
        Type t = type();
        Token tok = look;
        match("ID");
        match(";");
        Id id(tok, t, used);
        top.put(tok, id);
        used = used + t.width;
    }
    cout << "End decls" << endl;
}

Type Parser::type()
{
    cout << "Type" << endl;

    Type p(look.value, look.tokenTag, 0);
    match("BASE_TYPE");
    return p;
    cout << "End type" << endl;
}

Stmt Parser::stmts()
{
    // Stmt result;
    // return result;
    // cout << "stmts" << endl;
    if(look.tokenTag == "}") 
    {
        Stmt null;
        return null;    // returning null/empty statement
    }
    else
    {
        Seq resultSeq(stmt(), stmts());
        return resultSeq;
    }
}

Stmt Parser::stmt()
{
    // Stmt result;
    // return result;

    Expr expr;
    Stmt s, s1, s2;

    cout << "stmt: " << look.tokenTag << endl;
    if(look.tokenTag == ";")
    {
        cout << "if worked: " << look.tokenTag << endl;
        move();

        Stmt nullStmt;
        return nullStmt;
    }
    else if(look.tokenTag == "if")
    {
        match("if");
        match("(");
        expr = allexpr();
        match(")");

        s1 = stmt();
        if(look.tokenTag != "else") //return If(expr, s1);
        match("else");
        s2 = stmt();
        // return Else(expr, s1, s2);
    }

    else if("{")
    {
        return block();
    }
    else
    {
        return assign();
    }

    return s;
}

Stmt Parser::assign()
{
    cout << "assign" << endl;
    Stmt stmt;
    Token token = look;
    match("ID");
    Id id = top.get(token);

    move();
    // stmt = Set(id, allexpr());
    match(";");
    return stmt;
}

Expr Parser::allexpr()
{
    cout << "allexpr" << endl;
    Expr expr = andexpr();
    while(look.tokenTag == "OR")
    {
        Token token = look;
        move();
        // expr = OR(token, expr, andexpr())
    }
    return expr;
}

Expr Parser::andexpr()
{
    cout << "andexpr" << endl;
    Expr expr = equality();
    while(look.tokenTag == "AND")
    {
        Token token = look;
        move();
        // expr = AND(token, expr, equality());
    }
    return expr;
}

Expr Parser::equality()
{
    Expr expr = rel();
    while(look.tokenTag == "EQ" || look.tokenTag == "NE")
    {
        Token token = look;
        move();
        // expr = Rel(token, expr, rel());
    }
    return expr;
}

Expr Parser::rel()
{
    Expr expr = expression();

    if(look.tokenTag == "<" ||
        look.tokenTag == "LE" ||
        look.tokenTag == "GE" ||
        look.tokenTag == ">")
    {
        Token token = look;
        move();
        // expr = Rel(token, expr, expr());
    }
    return expr;
}

Expr Parser::expression()
{
    Expr expr = term();
    while(look.tokenTag == "+" || look.tokenTag == "-")
    {
        Token token = look;
        move();
        // expr = Arith(token, expr, term());
    }
    return expression();
}

Expr Parser::term()
{
    Expr expr = factor();
    while(look.tokenTag == "*" || look.tokenTag == "/")
    {
        Token token = look;
        move();
        // expr = Arith(token, expr, factor());
    }
    return expr;
}

Expr Parser::factor()
{
    Expr expr; // Expr initialized as null
    if(look.tokenTag == "(")
    {
        move();
        expr = allexpr();
        match(")");
        return expr;
    }
    else if(look.tokenTag == "NUM")
    {
        //expr = Constant(look, Type::Int());
        move();
        return expr;
    }
    else if(look.tokenTag == "REAL")
    {
        //expr = Constant(look, Type::Float());
        move();
        return expr;
    }
    else if(look.tokenTag == "true")
    {
        //expr = Constant::True();
        move();
        return expr;
    }
    else if(look.tokenTag == "false")
    {
        //expr = Constant::False();
        move();
        return expr;
    }
    else if(look.tokenTag == "ID")
    {
        string s = look.tokenTag;
        Id id = top.get(look);
        move();
        return id;
    }
}