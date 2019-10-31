#include <iostream>
#include <iomanip>
#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "inter/Node.hpp"

using namespace std;

string printTree(Node *root);
void printTree(Node *root, int indent, string *sb);
string getIndentString(int indent);

int main ()
{
    cout << "Start" << endl;
    Lexer lexer;

    lexer.input = 
      // DECLS & ASSIGN Test
      // "{ int b;\n int dd;\n b = dd;}";

    	// Parser Test #1
    	// "{ \
     //        int b; int a; b = a; \
     //        { \
     //            a = b; \
     //            do a = a+1; while(a < 100); \
     //        } \
     //    }";

    //Parser Test #2
  //   "{ \
		// 	int b; b = 1; \
		// 	bool yes = false; \
		// 	bool no = true; \
		// 	int cool = 0, lame = 1; \
		// 	{ \
		// 		int a; a = 2; do a = a+1; while(a >= 100); \
		// 		if(a == 100) { \
		// 			for(int i = 0; i == 4000; i = i + 1) { \
		// 				if(yes != true && no == false) { \
		// 					if(cool || lame) { \
		// 						float real = 1.2789 + 5.98; \
		// 					} \
		// 				} \
		// 			} \
		// 		} \
		// 	} \
		// }";

    // IF Test
    // "{ int r; int dd; int a; int d; \
    // r = a; dd = d;  \
    // if( dd <= r ) {a = d;} }";

    // WHILE Test
    // "{ int r; int dd; int a; int d; \
    // r = a; dd = d;  \
    // while( dd <= r ) {a = d; d = a; } }";

    // WHILE Test
    "{ int r; int dd; int a; int d; \
    r = a; dd = d; r = false; \
    do { a = d; d = a; } while( dd <= r ); }";

    Parser parser(lexer);
    Prog *tree = parser.program();
    // cout << tree->getNodeStr() << endl;
    // cout << "statement test" << endl;
    // Stmt *null = new Stmt();
    // cout << "st: " << null->getNodeStr() << endl;
    cout << "Syntax tree:" << endl;
    string treeStr = printTree(tree);

    // Final Tree Printed
    cout << endl << "--------------------" << endl
        << "FINAL TREE: " 
        << endl << "--------------------" << endl;
    cout << treeStr << endl;

    // for(int i = 0; i < tree->children.size(); i++)
    // {
    //   cout << tree->children[i]->getNodeStr() << endl;
    // }
}

string printTree(Node *root)
{
    // cout << "ROOT" << endl;
    // cout << "root: " << root->getNodeStr() << endl;
    int indent = 0;
    string result;
    printTree(root, indent, &result);
    // cout << "root: " << result << endl;
    return result;
}

void printTree(Node *root, int indent, string *sb)
{
    //  cout << "printTree: " << indent << endl;
    *sb += getIndentString(indent);
    *sb += "+--";
    *sb += root->getNodeStr();
    *sb += "\n";
    cout << *sb << endl;

    cout << "root: " << root->getNodeStr() << endl;
    cout << "size: " << root->children.size() << endl;
    // for(int i = 0; i < root->children.size(); i++)
    // {
    //     printTree(root->children[i], indent + 1, sb);
    // }
    for( auto i : root->children )
    {
      printTree(i, indent + 1, sb);
    }
}

string getIndentString(int indent)
{
    string result;
    for(int i = 0; i < indent; i++)
    {
        result += "|  ";
    }
    return result;
}