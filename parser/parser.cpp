#include "parser.hpp"
#include <assert.h>
using namespace std;

void Parser::move()
{ 
    cout << "Move From: " << look.value;
    look = lexer.getNextToken(); 
    cout << " To: " << look.value << endl;
}

void Parser::error(string errorMessage)
{
    cout << "near line " << Lexer::line << ": " << errorMessage << endl;
}

void Parser::match(string t)
{
    // if(look.tokenTag == t)  move();
    // else                    error("Syntax error");
    cout << "match: " << look.tokenTag << " == " << t << endl;
    ASSERT(look.tokenTag == t, "SYNTAX ERROR");   
    // assert(look.tokenTag == t);  
    move(); 
}

Prog* Parser::program()
{
    cout << "Program" << endl;
    Block *s = block();

    Prog *tempProg = new Prog(s);
    cout << "End Program" << endl;
    return tempProg;
}

Block* Parser::block()
{
    cout << "Block" << endl;
    match("{");
    Env* savedEnv = top;
    decls();
    Stmt *s = stmts();
    match("}");
    top = savedEnv;

    Block *tempBlock = new Block(s);
    cout << "End Block" << endl;
    return tempBlock;
}

void Parser::decls()
{
    cout << "decls" << endl;
    while(look.tokenTag == "BASE_TYPE")
    {
        Type *t = type();
        Token tok = look;
        match("ID");
        match(";");
        Id *id = new Id(tok, *t, used);
        top->put(tok, id);
        used = used + t->width;
    }
    cout << "End decls" << endl;
}

Type* Parser::type()
{
    cout << "Type" << endl;

    Type *p = new Type(look.value, look.tokenTag, 0);
    match("BASE_TYPE");
    return p;
    cout << "End type" << endl;
}

Stmt* Parser::stmts()
{
    // Stmt result;
    // return result;
    // cout << "stmts" << endl;
    if(look.tokenTag == "}") 
    {
        Stmt *null = new Stmt();
        return null;    // returning null/empty statement
    }
    else
    {
        Seq *resultSeq = new Seq(stmt(), stmts());
        return resultSeq;
    }
}

Stmt* Parser::stmt()
{
    // Stmt result;
    // return result;

    Expr *expr;
    Stmt *s, *s1, *s2;

    cout << "stmt: " << look.tokenTag << endl;
    if(look.tokenTag == ";")
    {
        // cout << "if worked: " << look.tokenTag << endl;
        move();

        Stmt *nullStmt = new Stmt();
        return nullStmt;
    }
    else if(look.tokenTag == "IF")
    {
        match("IF");
        match("(");
        expr = allexpr();
        match(")");

        s1 = stmt();
        if(look.tokenTag != "ELSE")
        {
            If *tempIf = new If(expr, s1);
            return tempIf;
        }
        match("ELSE");
        s2 = stmt();

        Else *tempElse = new Else(expr, s1, s2);
        return tempElse;
    }

    else if(look.tokenTag == "WHILE")
    {
        While *whilenode = new While();
        //savedStmt = Stmt.Enclosing
        //Stmt.Enclosing = whilenode
        match("WHILE");
        match("(");
        expr = allexpr();
        match(")");
        s1 = stmt();
        cout << "WHILE s1: " << s1->getNodeStr() << endl;
        whilenode->init(expr, s1);
        //Stmt.Enclosing = savedStmt;
        cout << "WHILE init: " << whilenode->expr->getNodeStr() << " " << whilenode->stmt->getNodeStr() << endl;
        cout << "return from stmt: WHILE" << endl;
        return whilenode;
    }

    else if(look.tokenTag == "DO")
    {
        Do *donode = new Do();
        // savedStmt = Stmt.Enclosing
        // Stmt.Enclosing = donode;
        match("DO");
        s1 = stmt();
        match("WHILE");
        match("(");
        expr = allexpr();
        match(")");
        donode->init(s1, expr);
        // Stmt.Enclosing = savedStmt;
        return donode;
    }

    else if(look.tokenTag == "BREAK")
    {
        match("BREAK");
        match(";");
        Break *tempBreak = new Break();
        return tempBreak;
    }

    else if(look.tokenTag == "{")
    {
        return block();
    }

    else
    {
        cout << "return from stmt: assign()" << endl;
        return assign();
    }

    cout << "return from stmt()" << endl;
    return s;
}

Stmt* Parser::assign()
{
    cout << "assign" << endl;
    Stmt *stmt;
    Token token = look;
    match("ID");
    Id *id = top->get(token);

    move();
    stmt = new Set(id, allexpr());
    match(";");
    cout << "return assign(): " << stmt->getNodeStr() << endl;
    return stmt;
}

Expr* Parser::allexpr()
{
    cout << "allexpr" << endl;
    Expr *expr = andexpr();
    while(look.tokenTag == "OR")
    {
        Token token = look;
        move();
        expr = new Or(token, expr, andexpr());
    }
    cout << "return allexpr(): " << expr->op.tokenTag << endl;
    return expr;
}

Expr* Parser::andexpr()
{
    cout << "andexpr" << endl;
    Expr *expr = equality();
    while(look.tokenTag == "AND")
    {
        Token token = look;
        move();
        expr = new And(token, expr, equality());
    }
    cout << "return andexpr(): " << expr->op.tokenTag << endl;
    return expr;
}

Expr* Parser::equality()
{
    cout << "equality" << endl;
    Expr *expr = rel();
    while(look.tokenTag == "EQ" || look.tokenTag == "NE")
    {
        Token token = look;
        move();
        expr = new Rel(token, expr, rel());
    }
    cout << "return equality: " << expr->op.tokenTag << endl;
    return expr;
}

Expr* Parser::rel()
{
    cout << "rel" << endl;
    Expr *expr = expression();

    if(look.tokenTag == "<" ||
        look.tokenTag == "LE" ||
        look.tokenTag == "GE" ||
        look.tokenTag == ">")
    {
        Token token = look;
        cout << "move in rel()" << endl;
        move();
        expr = new Rel(token, expr, term());
        cout << "LE Rel: " << expr->op.tokenTag << endl;
    }
    cout << "return rel(): " << expr->op.tokenTag << endl;
    return expr;
}

/*Expr* Parser::IncrementDecrement()
{
    cout << "IncrementDecrement" << endl;
    Expr *expr = term();
    while(look.tokenTag == "++" || look.tokenTag == "--")
    {
        cout << "move in IncrementDecrement()" << endl;
        Token token = look;
        move();
        expr = new IncDec(token, expr/*, expression()*//*);
    }
    cout << "return IncrementDecrement(): " << expr->op.tokenTag << endl;
    return expr;
}*/

Expr* Parser::expression()
{
    cout << "expression" << endl;
    Expr *expr = term();
    while(look.tokenTag == "++" || look.tokenTag == "--")
    {
        cout << "move in IncrementDecrement()" << endl;
        Token token = look;
        move();
        expr = new IncDec(token, expr);
    }
    while(look.tokenTag == "+" || look.tokenTag == "-")
    {
        cout << "move in expression()" << endl;
        Token token = look;
        move();
        expr = new Arith(token, expr, term());
    }
    cout << "return expression(): " << expr->op.tokenTag << endl;
    return expr;
}

Expr* Parser::term()
{
    cout << "term" << endl;
    Expr *expr = factor();
    while(look.tokenTag == "*" || look.tokenTag == "/")
    {
        cout << "move in term()" << endl;
        Token token = look;
        move();
        expr = new Arith(token, expr, factor());
        cout << "term() * or /: " << expr->op.tokenTag << endl;
    }
    cout << "return term(): " << expr->op.tokenTag << endl;
    return expr;
}

Expr* Parser::factor()
{
    cout << "factor" << endl;
    Expr *expr; // Expr initialized as null
    if(look.tokenTag == "(")
    {
        move();
        expr = allexpr();
        match(")");
        return expr;
    }
    else if(look.tokenTag == "NUM")
    {
        expr = new Constant(look, Type::Int());
        move();
        return expr;
    }
    else if(look.tokenTag == "REAL")
    {
        expr = new Constant(look, Type::Float());
        move();
        return expr;
    }
    else if(look.tokenTag == "true")
    {
        expr = Constant::True();
        move();
        return expr;
    }
    else if(look.tokenTag == "false")
    {
        expr = Constant::False();
        move();
        return expr;
    }
    else if(look.tokenTag == "ID")
    {
        cout << "ID" << endl;
        string s = look.tokenTag;
        Id *id = top->get(look);
        cout << "move in factor(): ID" << endl;
        move();
        cout << "return factor(): " << id->op.tokenTag << endl;
        return id;
    }
    else
    {
        expr = new Expr();
    }
    cout << "return factor(): " << expr->op.tokenTag << endl;
    return expr;
}