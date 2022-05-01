//lexcial analyzer
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <list> 
#include <bits/stdc++.h>
using namespace std;

bool isKeyword (string a);
bool isOperator (string a);
bool isSymbols (string a);
void print(list<string> const &list, string label);

int main (){
	//storage
	list<string> operators = list<string>();
	list<string> keywords = list<string>();
	list<string> symbols = list<string>();
	list<string> identifiers = list<string>();
	list<string> constants = list<string>();
	
	//getting the words from the text files
    ifstream file("prog.txt");
    string x;
    string code = "";

	//if the file can't be open
	if (!file.is_open()){
		cout << "Sorry there is a problem opening the file.."<<endl;
	}

	//transfer to a string
	//per line reading
    while(getline(file,x)){
        code+=x;
		code+=" ";
    }
	
	string s = "";
	int i = 0;
	//reading per character
	while (i < code.size()){
		s += code[i];
		//Operators
		if (isOperator(s)) {
			cout << s <<" is an operator"<<endl;
			operators.push_back(s);
			s = "";
		} 

		//Keyword
		else if (isKeyword (s)){
			cout << s <<" is a keyword"<<endl;
			keywords.push_back(s);
		} 

		//Symbols
		else if (isSymbols(s)){
			cout << s <<" is a symbol"<<endl;
			symbols.push_back(s);
			s = "";
		} 
		
		//Spaces
		else if (s == "\n" || s == "" || s == " ") {
			s = "";
		} 
		
		//Numbers
		else if (isdigit (s[0])) {
			int x = 0;
				if (!isdigit (s[x++])) {
					continue;
				}
				else {
					cout << s <<" is a constant"<<endl;
					constants.push_back(s);
					s = "";
				}		
		} 
		
		//Identifier
		else {
			cout << s <<" is an identifier"<<endl;
			identifiers.push_back(s);
			s = "";
		}
		i++;			
	}

	//print the answers
	// print(operators, "Operators");
	// print(keywords, "Keywords");
	// print(constants, "Constants");
	// print(identifiers, "Identifiers");
	// print(symbols, "Symbols");
}

bool isKeyword (string a)
{
	string arr[] = { "if", "else","while","break",
		"do", "continue", "int", "double",
		"float", "return", "char", "case",
		"long", "short", "typedef", "switch",
		"unsigned", "void", "static", "struct",
		"sizeof", "long", "volatile", "enum",
		"const", "union", "extern", "bool", 
		"using", "namespace","include", "std",
		"iostream","main", "cin","cout", "return",
		"auto", "goto", "for", "const",
		"char", "signed", "register"
	};


	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		if (arr[i] == a) {
			return true;
		}
	}
	return false;
}

bool isOperator (string a)
{
	string operators[] = {
		"+", "-", "*", "/",
		"^", "&&", "||", "=",
		"==", "&", "|", "%",
		"++", "--", "+=", "-=",
		"/=", "*=", "%="
	};


	for(int i = 0; i < sizeof(operators)/sizeof(operators[0]); ++i){
		if(a == operators[i])
			return true;
	}
	return false;
}

bool isSymbols (string a)
{
	string symbol[] = {
		"(", ")", "{", "}", "[", "]",
		"<", ">", "<<",">>", ";", ",",
		"#", "()"
	};

	for(int i = 0; i < sizeof(symbol)/sizeof(symbol[0]); ++i){
		if(a == symbol[i])
			return true;
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