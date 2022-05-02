#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isKeyword(string input){
    string keywords[] = { "if", "else","while","break",
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
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (keywords[i] == input) {
            return true;
	}
    }
    
    return false;
}

bool isOperator(string input){
    string operators[] = {
		"+", "-", "*", "/",
		"^", "&&", "||", "=",
		"==", "&", "|", "%",
		"++", "--", "+=", "-=",
		"/=", "*=", "%="
	};


    for(int i = 0; i < sizeof(operators)/sizeof(operators[0]); ++i){
	if(input == operators[i])
            return true;
	}
    
    return false;
}

bool isSymbol(string input){
    string symbol[] = {
		"(", ")", "{", "}", "[", "]",
		"<", ">", "<<",">>", ";", ",",
		"#", "()"
	};

    for(int i = 0; i < sizeof(symbol)/sizeof(symbol[0]); ++i){
        if(input == symbol[i])
            return true;
        }
    
    return false;
}

bool isIdentifier(string input, int i){
    if(!((input[0] >= 'a' && input[0] <= 'z')
        || (input[0] >= 'A' && input[0] <= 'Z')
        || input[0] == '_'))
            return false;
    
    for (int i = 1; i < input.length(); i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z')
              || (input[i] >= 'A' && input[i] <= 'Z')
              || (input[i] >= '0' && input[i] <= '9')
              || input[i] == '_'))
            return false;
    }
    return true;
}

bool isConstant(string input){
    for (int i = 0; i < input.length(); i++){
        if (isdigit(input[i]) == false)
            return false;
    }
    return true;
}

int main(int argc, char** argv) {
    fstream file;
    
    file.open("inp.txt",ios::in);
    if (!file.is_open()){ 
        file.open("inp.txt",ios::out);
        
        file << "# include < iostream >" << endl
            << "using namespace std ;" << endl
            << "int main () {" << endl
            << "    int a , b , c , d ;" << endl
            << "    a = 1 ;" << endl
            << "    b = 2 ;" << endl
            << "    c = 3 ;" << endl
            << "    d = a + b + c ;" << endl
            << "    cout << d ;" << endl
            << "    return 0 ;" << endl
            << "}";
    }else{
        string word;
        while(file >> word){
            
            if(isKeyword(word)){
                cout << word << " is a keyword" << endl;
            }
            else if(isOperator(word)){
                cout << word << " is an operator" << endl;
            }
            else if(isSymbol(word)){
                cout << word << " is a symbol" << endl;
            }
            else if(isIdentifier(word,word.length())){
                cout << word << " is an identifier" << endl;
            }
            else if(isConstant(word)){
                cout << word << " is a constant" << endl;
            }
            else
                cout << word << endl;
        }
    }
    file.close();
    
    return 0;
}
