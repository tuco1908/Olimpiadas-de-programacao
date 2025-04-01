#include <iostream>

using namespace std;

bool comp(int a, int b) {
    //ordenando primeiro os pares: devem vir antes dos ímpares e estar,
    //em ordem crescente.
    //na função comp a vai assumir o elemento que vem antes de b.
    if (a % 2 == 0) {
        if (b % 2 == 0) {
            return a < b; // pode ser b > a tbm, dá na mesma. 
            // ou seja, deve organizar de modo que o menor venha primeiro
        }
        else{
            return true; 
            // b ainda deve vir depois do ar, porque é ímpar
        }
    }
    //ordenando os ímpares, se a não for par, só pode ser ímpar. 
    else if (b % 2 == 0) {
        return false; 
        // b, neste caso, deve vir antes, já que a é ímpar
    }
    else {
        return a > b;
        //como ambos são ímpares, o primeiro deve ser maior
        //que o segundo
    }
}

int main() {
    int n, len;
    cin >> n;
    int numbers[n];
    
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    
    len = sizeof(numbers)/sizeof(numbers[0]); 
    // tá o tamanho total do array
    
    sort(numbers, numbers+len, comp); 
    //numbers + len dá o endereço do último elemento + 1
    
    for (int i = 0; i < n; i++){
        cout << numbers[i] << "\n";
    }
    
    return 0;
}
