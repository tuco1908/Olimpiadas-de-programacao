#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std; 

int main()
{
    
    map <char, char> dic = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };

    string expr;
    int t;
    bool valid;
    
    cin >> t;
    
    getline(cin, expr);
    
    for(int i = 0; i < t; i++){
        
        getline(cin, expr);
        
        stack <char> stk;

        valid = true;
        
        for(int j = 0; j < expr.size(); j++){

            if(dic[expr[j]]){
                stk.push(expr[j]);
            }
            else if(stk.size() == 0){ 
                valid = false; 
                break;
            }
            else if(dic[stk.top()] == expr[j]){
                stk.pop();
            }
            else{
                valid = false;
                break;
            }
        }
        
        if(stk.size() != 0){ // se igual a zero, da false
            valid = false;
        }
        
        if(valid){
            cout << "S\n";
        }
        else{
            cout << "N\n";
        }
    }
    return 0;
}