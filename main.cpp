#include <iostream>
#include <iomanip>
#include "lexer.cpp"
using namespace std;

int main ()
{
    Lexer lexer;

    lexer.input = 
    	// TEST INPUT 1
    	"{ \
            int b; b = 1; \
            { \
                int a; a = 2; \
                do a = a+1; while(a < 100); \
            } \
        }";

    	// TEST INPUT 2
    	//    "{ \
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

    // -- REQUIRED -- : Find data struct for tokens & implement in Lexer class
    Token token_peek[lexer.input.length()];
 
 	// -I- Iterate through each token to determine the TYPE and VALUE of token
    int index = 0;
    for(auto it = lexer.input.begin(); it < lexer.input.end(); it++, index++)
    {
    	token_peek[index] = lexer.getNextToken();
    }
    


    // -I- Print final token TAG and VALUE

    cout << endl << endl << "----- FINAL OUTPUT -----" << endl << "------------------------" << endl
    	<< setw(10) << right << "TAG " << "|\tVAL" << endl << "------------------------" << endl;


    for(int i = 0; i < lexer.input.length(); i++)
    {
    	cout << setw(10) << left << token_peek[i].tokenTag  << "|\t" << token_peek[i].value << endl;

    	// -I- Finish printing if EOF token is found
    	if(token_peek[i].tokenTag == "EOF") break; 
    }
}