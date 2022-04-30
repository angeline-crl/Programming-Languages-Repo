//lexcial analyzer
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <list> 
using namespace std;

string arr[] = { "void", "using", "namespace", "int", 
    "include", "iostream", "std", "main", 
    "cin", "cout", "return", "float", 
    "double", "string" 
};

bool isKeyword (string a)
{
	for (int i = 0; i < 14; i++) {
		if (arr[i] == a) {
			return true;
		}
	}
	return false;
}

void print(list<string> const &list, string label)
{
	cout<<"-----------"<<label<<"-----------"<<endl;
    for (auto const &i: list) {
        cout << i << endl;
    }
}

int main (){
	//storage
	list<string> operators = list<string>();
	list<string> keywords = list<string>();
	list<string> symbols = list<string>();
	list<string> identifiers = list<string>();
	list<string> constants = list<string>();
	
    ifstream file("prog.txt");
    string x;
    string code = "";

    while(getline(file,x)){
        code+=x;
    }

    string s = "";
    for(int i = 0; i<code.size(); i++){
		if(code[i] != ' '){
            s += code[i];
        }
		else {
			if (s == "+" || s == "-" || s == "*" || s == "/" || 
            s == "^" || s == "&&" || s == "||" || s == "=" || 
            s == "==" || s == "&" || s == "|" || s == "%" || 
            s == "++" || s == "--" || s == "+=" || s == "-=" || 
            s == "/=" || s == "*=" || s == "%=") {
                cout << s <<" is an operator"<<endl;
				operators.push_back(s);
                s = "";
            } else if (isKeyword (s)){
				cout << s <<" is a keyword"<<endl;
				keywords.push_back(s);
				s = "";
			} else if (s == "(" || s == "{" || s == "[" || s == ")" || 
            s == "}" || s == "]" || s == "<" || s == ">" ||
            s == "()" || s == ";" || s == "<<" || s == ">>" ||
            s == "," || s == "#"){
				cout << s <<" is a symbol"<<endl;
				symbols.push_back(s);
				s = "";
			} else if (s == "\n" || s == "" || s == "") {
				s = "";
			} else if (isdigit (s[0])) {
				int x = 0;
					if (!isdigit (s[x++])) {
						continue;
					}
					else {
						cout << s <<" is a constant"<<endl;
						constants.push_back(s);
						s = "";
					}		
			} else {
				cout << s <<" is an identifier"<<endl;
				identifiers.push_back(s);
				s = "";
			}		
		}	
	}
	//print the answers
	print(operators, "Operators");
	print(keywords, "Keywords");
	print(constants, "Constants");
	print(identifiers, "Identifiers");
	print(symbols, "Symbols");
}