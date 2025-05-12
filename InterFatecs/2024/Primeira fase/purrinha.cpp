#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <limits>// contém o método ignore usado para iguinorar determinadas linhas do buffer. 

using namespace std;

/* 
Problemas enfrentados e o que aprendi com eles:

Meu objetivo inicial era, enquanto a leitura era realizada, o programa já calcularia os pontos e determinaria o ganhador, sendo uma abordagem
eficiente, porém, causaria problemas de execução e ou de leituras das próximas rodadas. Isso aconteceu no exemplo 2: o programa lia todos os
dados das mãos dos jogadores tranquilamente, quando chegava na parte de ler os palpites caso o primeiro palpite determinasse já o vencedor da
rodada, o programa pararia de ler os próximos palpites. Por mais de essa estratégia ser eficiente, isso causa problema. 
Todos os dados fornecidos ao programa são armazenados no buffer na ordem em que foram dados e são lidos pelo cin um a um (já que estão 
separados por espaço), como o algoritmo parava de ler os dados assim que determinava o vencedor da rodada, o dado que era para ser lido como 
plapite, será lido como mão de jogador. Para essa estratégia funcionar, percisar usar alguma instrução que limpa somente o restante da linha 
sendo lida do buffer. Essa instrução existe e usa métodos da biblioteca limits. 
*/

int main(void){
    int qjog, rod, minp, m, totalm, pal;
    bool ganhoujog = false, ganhourod;
    cin >> qjog;
    int pont[qjog] = {};// array todo zerado
    string nomes[qjog];
    set<int, greater<int>> result;// vai ta vazio, sem nenhum elemento;
    for(int i = 0; i < qjog; i++){
        cin >> nomes[i];
    }

    cin >> rod;
    minp = rod/2 + 1;

    while(rod){
        rod--;
        totalm = 0;
        ganhourod = false;
        for(int i = 0; i < qjog; i++){
            cin >> m;
            totalm += m;
        }

        for(int i = 0; i < qjog; i++){
            cin >> pal;

            if(ganhoujog or ganhourod){
                continue;
            }
            if(pal == totalm){
                pont[i]++;
                ganhourod = true;
                if(pont[i] >= minp){
                    ganhoujog = true;
                }
            }   
        }
    }

    for(int i = 0; i < qjog; i++){
        result.insert(pont[i]);
    }

    cout << result.size() << "\n";
    if(result.size() == 1){
        cout << "EMPATE\n";
    }
    else{
        cout << nomes[find(pont, pont + qjog, *(result.begin())) - pont] << " GANHOU\n";
    }
    return 0;
}   