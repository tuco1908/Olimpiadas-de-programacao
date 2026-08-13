#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std;

int main(){

    map<char, char> dic = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'},
    };

    int qtd;
    string exp;
    stack<char> stk;

    cin >> qtd;
    getline(cin, exp); //consumes the left \n character
    
    for(int i = 1; i<=qtd; i++){

        bool valid = true;

        getline(cin, exp);

        for(int j = 0; j < exp.size(); j++){
            
        }

}