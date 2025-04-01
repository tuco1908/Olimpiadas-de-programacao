#include <iostream>

using namespace std;

int main(void){
    int val, v[20105], n, x, k = 0;

    while (cin>>val) {
        x = 0;
        k++;
        if (val == 0) {
            n = 1;
        }
        
        else {
            n = (((1.0 + val)/2)*val)+1;

            for (val; val >= 0; val--){
                int c = 0; 
                while (c != val){
                    v[x] = val;
                    x++;
                    c++;
                }
            }
        }

        v[x] = 0;

        if (n == 1){
            cout << "Caso "<< k << ": " << n << " numero\n";
            cout << v[x] << "\n" << "\n";
        }
        
        else {
            cout << "Caso "<< k << ": " << n << " numeros\n";
            cout << v[x];
            x--;

            for (x; x >= 0; x--){
                cout << " " << v[x]; 
            }

            cout << "\n" << "\n";
        }

    }
    return 0;
}
