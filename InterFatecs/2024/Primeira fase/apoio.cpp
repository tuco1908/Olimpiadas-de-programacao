#include <iostream>
#include <string>

using namespace std;

int main(void){
    int len;
    cin >> len;
    int grupo[len], perfil, reg, smaller;
    string cod;
    for(int i = 0; i < len; i++){
        cin >> perfil;
        grupo[i] = perfil;
    }
    cin >> reg;
    while(reg){
        reg--;
        cin>>cod;
        smaller = 300;
        for(int i = 0; i < len; i++){
            cin >> perfil;
            perfil /= grupo[i];
            if(smaller > perfil){
                smaller = perfil; 
            }
        }
        cout << cod << " " << smaller << "\n";
    }
    return 0;
}