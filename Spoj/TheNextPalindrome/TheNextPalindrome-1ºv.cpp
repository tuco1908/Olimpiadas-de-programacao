#include <iostream>
#include <cmath>

using namespace std;

int numberdigitis(long long int x){
    int digitis = 0;
    while(x){
        x /= 10; //produz divisão inteira, nunca vai guardar o resto. 
        digitis++;
    }
    return digitis;
}

long long int reverse(long long x, int n){//número x e sua quantidade de digitos n;
    int resp = 0; 
    while(n >= 1){
        n--;
        resp += x%10 * pow(10, n);
        x /= 10;
        cout << "n do reverse: " << n << "\n";
        cout << "número do reverse: " << resp << "\n";
    }
    return resp;
}

int main(void){
    long long int number, fpart, spart, divider, rev;
    int t, dig;
    cin >> t;
    while (t!=0){
        cin >> number;
        
        // se number tem o final > que o início, e o seu igualamos o final ao início
        
        dig = numberdigitis(number);//guarda a quantidade total de caracteres de number 
        cout << "dig: " << dig << "\n";

        divider =  pow(10, dig/2);/* pow retorna 10 elevado a dig/2 é da biblioteca <cmath>. divider é o divisor que
        separa o number nas duas partes iguais, fpart e spart*/

        if (dig%2 == 0){//se o número de dígitos for par
            fpart = number/divider;
            rev = reverse(fpart, dig/2);
            spart = number%divider;
            cout << "spart: " << spart << "\n";
            cout << "fpart: " << fpart << "\n";


            if(rev > spart){
                spart = rev;
                cout << "spart = rev: " << spart << "\n";

            }
            else{
                fpart++; 
                spart = rev + divider/10;
                cout << "spart = rev + divider/10: " << spart << "\n";


            }
            fpart = fpart * divider + spart;
            cout << "resp: " << fpart << "\n";
            }
        
        else{//se o número de dígitos for ímpar. 
            fpart = number/(divider*10);
            rev = reverse(fpart, dig/2);
            spart = number%divider;

            if(rev > spart){
                spart = rev;
                fpart = fpart * divider * 10 + spart;
                cout <<  "resp: " << fpart << "\n";
            }

            else if(rev < spart){
                spart = rev;
                fpart = fpart * divider * 10 + spart + divider;
                cout << "resp: " << fpart << "\n";
            }

            else{
                fpart = fpart * divider * 10 + spart + divider;
                cout << "resp: " << fpart << "\n";
            }
        }
        t--;
   }
}