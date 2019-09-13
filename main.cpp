#include <iostream>
#include "lexer.cpp"
using namespace std;

int main ()
{
    Lexer lexer;
    lexer.input = "Hello 123";
    cout << lexer.input;
    lexer.getNextToken();

    cout << endl << endl << endl
        << "TAG: " << lexer.token.tokenTag << endl
        << "VALUE: " << lexer.token.value << endl;
    // exit(1)
        "VALUE: ";
}