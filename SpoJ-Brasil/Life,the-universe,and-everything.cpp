#include <iostream>

using std::cout;
using std::cin;

int main(void){
    int number;
    while(true){
        cin >> number;
        if(number == 42){
            break;//termina e sai do laço
        }
        cout << number << "\n";
    }
    return 0;
}