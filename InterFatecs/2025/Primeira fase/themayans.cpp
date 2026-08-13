#include <iostream>
#include <string>
#include <cmath> //necessary to use pow()

using namespace std;

int main(){

    string str;
    int expo, number;
    long long resp; 


    while(getline(std::cin, str) && str[0] != '*'){

        expo = number = resp = 0;

        for(int i=str.length()-1; i >= 0; i--){
            if(str[i] == ' '){
                resp += pow(20, expo) * number;/*fucntion to power something with pow
                and multiplying it by number
                */
                expo ++;
                number = 0;
            }
            else if(str[i] == '.'){
                number += 1;
            }
            else if(str[i] == '-'){
                number += 5;
            }
        }
        resp += pow(20, expo) * number;
        cout << resp << "\n";
    }
    return 0;
}