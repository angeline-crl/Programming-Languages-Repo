//lexcial analyzer
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

string keys [100];
int number = 0;

void store_keyword(){
    short loop=0; 
    string line; 
    ifstream myfile ("listOfKeywords.txt");
    if (myfile.is_open()) 
    {
        while(getline(myfile,line)){
            keys[loop] = line;
            loop++;
        }
        myfile.close(); 
    }
}

void numberOfElements(){
	int numbers = 1;
    ifstream myfile ("listOfKeywords.txt");
    string elements;
    while (getline(myfile, elements))
        number = numbers+1;
    myfile.close();
}

bool isKeyword (string a){
	//gets the size of the key array
	for (int i = 0; i < number ; i++) {
		if (keys[i] == a) {
			return true;
		}
	}
	return false;
}

int main (){
	//initialization the array ---> keys[100]
	// will get from notpad
	store_keyword();
	numberOfElements();

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
                s = "";
            } else if (isKeyword (s)){
				cout << s <<" is a keyword"<<endl;
				s = "";
			} else if (s == "(" || s == "{" || s == "[" || s == ")" || 
            s == "}" || s == "]" || s == "<" || s == ">" ||
            s == "()" || s == ";" || s == "<<" || s == ">>" ||
            s == "," || s == "#"){
				cout << s <<" is a symbol"<<endl;
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
						s = "";
					}		
			} else {
				cout << s <<" is an identifier"<<endl;
				s = "";
			}		
		}	
	}
}