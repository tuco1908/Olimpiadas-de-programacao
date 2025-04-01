#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct entrada {
    int p, s, t;
};

bool soma (entrada i) {
    return i.p + i.s == i.t;
} 

bool sub (entrada i) {
    return i.p - i.s == i.t;
}

bool mult (entrada i) {
    return i.p * i.s == i.t;
}


int main() {

    int t, ind;
    char mv;
    string nome;
    entrada eq;
    vector<entrada> contas;
    vector<string> jog;

    while(cin >> t) {
        contas.clear();
        jog.clear();

        for(int i = 0; i < t; i++) {
            scanf("%d %d=%d", &eq.p, &eq.s, &eq.t);   
            contas.push_back(eq);
        }

        for(int i = 0; i < t; i++) {
            cin >> nome >> ind >> mv;

            switch (mv) {
                case '+':
                    if (!soma(contas[ind - 1])) jog.push_back(nome);
                    break;

                case '-':
                    if (!sub(contas[ind - 1])) jog.push_back(nome);
                    break;

                case '*':
                    if(!mult(contas[ind - 1])) jog.push_back(nome);
                    break;
                
                case 'I':
                    if (soma(contas[ind - 1]) || sub(contas[ind - 1]) || mult(contas[ind - 1]))
                    {
                        jog.push_back(nome);
                    }
                    break;
            }
        }

        int tam = jog.size();
        if(tam == 0){
            cout << "You Shall All Pass!\n";
        }

        else if(tam == t){
            cout << "None Shall Pass!\n";
        }

        else {
            sort(jog.begin(), jog.end());
            cout << jog[0];
            for (int i = 1; i < tam; i++){
                cout << " " << jog[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
