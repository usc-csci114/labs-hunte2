#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatching(char open, char close){
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']') || (open == '<' && close == '>');
}

void checkBrackets(const string& input){
    stack<char> stack;
    for(size_t i = 0; i < input.length(); ++i){
        char charBracks = input[i];
        if(charBracks == ' ' || charBracks == '\t'){
            continue;
        }
        if (charBracks == '{' || charBracks == '(' || charBracks == '[' || charBracks == '<'){
            stack.push(charBracks);
        }
        else if (charBracks == '}' || charBracks == ')' || charBracks == ']' || charBracks == '>'){
            if (stack.empty()){
                cout << "Error, Found " << charBracks << " at position " << i << ", expecting any open." << endl;
                return;
            }
            char top = stack.top();
            stack.pop();
            if (!isMatching(top, charBracks)) {
                cout << "Error, Found " << charBracks << " at position " << i << ", but expecting " << top << "." << endl;
                return;
            }
        } else{
            cout << "Invalid character at position " << i << "." << endl;
            return;
        }
    }
    if (!stack.empty()){
        cout << "Error. Unmatched open parens/brackets." << endl;
    }
    else{
        cout << "The sequence is correctly nested." << endl;
    }
}

int main() {
    cout << "Enter a string containing only open/close parens/brackets and whitespace: " << endl;
    string input;
    getline(cin, input);
    checkBrackets(input);
    return 0;
}
