#include <iostream>
#include <algorithm>//contém find(), copy() e sort()
#include <string>

using namespace std;

int main(void){
    int n, p, anssorted[5], ind;
    int ans[5] = {0, 0, 0, 0, 0};
    string ansstr[5] = {"superior", "esquerda", "centro", "direita", "inferior"};
    cin >> n;
    while(n!=0){
        n--;
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 3; j++){
                cin >> p;

                if(p == 0){
                    continue;
                }

                if(i == 0){
                    ans[0] += p;
                }

                else if(i == 5){
                    ans[4] += p;
                }

                else if (i > 0 and i < 5 and j == 0){
                    ans[1] += p;
                }

                else if (i > 0 and i < 5 and j == 2){
                    ans[3] += p; 
                }
                
                else {
                    ans[2] += p;
                }
            }
        }
    }
    
    copy(ans, ans + 5, anssorted);
    sort(anssorted, anssorted + 5);
    ind = find(ans, ans + 5, anssorted[4]) - ans;/* o nome do ans é um ponteiro apontando para o seu primeiro elemento
    e, como find retorna um ponteiro apontando para o maior elemento de ans, subtraindo estes dois obtementos o endereço 
    do maior elemento do vettor.*/

    cout << ansstr[ind] << "\n";

    /* ans está organizado segundo uma ordem específica que é a mesma do ansstr, desse modo, se o maior estiver
    no índice um, então será a região da esquerda (ansstr[1] = esquerda). Porém, para descorbrir o maior, precisamos
    ordenar o vetor em ordem decrescente, mas não podemos fazer no original, porque perderíamos a ordem por completo,
    assim, fazemos uma cópiua que servirá somente para isso. Após ordená-la, vamos pegar o maior valor, que sempre
    estará no último indíce e encontrar o seu índice com a função find(), esse valor será usado para printar a resposta.
    O find(), caso haja dois valores iguais, encontrará o primeiro índice com este elemento, respeitando a ordem imposta
    pelo exercício. Exemplo: se esquerda e direita tem valores iguais, find() vai encontrar primeiro o índice do esquerda
    porque, no vetor ans, é o que vem primeiro.*/

    return 0;
}