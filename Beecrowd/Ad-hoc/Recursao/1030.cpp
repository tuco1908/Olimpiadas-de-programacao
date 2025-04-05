/*
Explicação do código: 
    As operações acontecerão em um array que muda de tamanho, ou seja, será um vetor. Pelo enunciado do exercício, os valores armazenados no 
vetor são determinados por n, o vetor conterá de 1 a n elementos e o primeiro ciclo começará a partir de n.
    O grande desafio é fazer o vetor funcionar como um ciclo. Para isso, além dos elementos determinados por n, o vetor vai conter dois valores
fora do intervalo 1 a n, que vão funcionar como bordas do vetor. Se um ciclo terminar ou passar em uma dessas bordas, significa que deve ou
começar o próximo ciclo (caso o anterior termine em um borda) a partir da outra borda, ou continuar o mesmo ciclo a partir da outra borda.
    Outro grande problema que foi facilmente evitado foi em relação ao número de passos (k). Considerando um vetor com 5 elementos, no qual 
precisa dar 233 passos para determinar o próximo item a ser apagado, ao invés de criar um loop com muitos ifs e elses somando cada passo, 
dividimos k por n (tamanho atual do vetor) e pagamos o seu resto, atribuindo à index. O resultado da divisão será o número de vezes que o 
ciclo, partindo de onde itr aponta, será repetido, o que não pe importante. Assim, sabendo a quantidade de passos restantes que não completam 
um ciclo, conseguimos descobrir o endereço do elemento a ser apagado, basta somar o resto (index) à itr. 
*/

#include <vector>
#include <iostream>

using namespace std;

int main(void){
    int n, k, nc, index;
    cin >> nc;
    for (int i = 1; i <= nc; i++) {
        cin >> n >> k;

        // construção do vetor
        vector<int>arr = {0, n}; //inicio um vetor com 2 elementos 0 e n, que não fará parte dos elementos do ciclo 
        for (int j = 1; j < n; j++){
            arr.push_back(j); //método igual ao append, vai adicionar o elemento j no final do vetor, depois do zero. 
        }
        arr.push_back(-1);

        /*
        O vetor vai ter exatamente esses elementos no exemplo do exercício: [0, n, 1, 2, ..., n-1, 0, '0']. O último zero é o
        sistema que coloca.
        */ 

        vector <int>::iterator itr; /*criamos um iterador chamado itr. iterador não é um ponteiro, mas, essencialmente, funciona como um: 
        guarda o endereço de uma célula da memória, com a diferença de que só pode guardar a célula de um tipo de estrutura de dados,
        neste caso é o vector(vetor)*/
        itr = arr.begin() + 1; /*ao somar um número inteiro a um endereço de memória guardado por um ponteiro ou iterador, conseguimos o 
        das próximas células de memória. Neste linha de código begin() da o início do vetor, onde é a borda, com valor 0, mas o primeiro
        elemento do vetor é o próximo, por isso, soamamos 1 ao endereço.*/

        while (n > 1){
            index = k%n;

            // ifs de verificação da posição do itr:

            if(itr == arr.begin()){
                itr = arr.end() - 2; //se itr tá na borda do ínicio do vetor, que tem valor 0, significa que deveria estar no último elemento. 
            }
            
            else if ((itr == arr.end() - 2) and index != 0){
                itr = arr.begin(); /*este caso é o oposto, se itr tá no último elemento do vetor (ver NOTA), significa que a soma vai resultar 
                num endereço de um elemento do início do vetor. Aqui eu movo para a borda do início porque ela vai substuir o último elemento,
                vai agir como ele.
                Nota: itr nunca vai estar na borda final porque sempre assume o endereço do elemento anterior ao apagado, como nunca vai apagar
                o elemento depois da borda(os ifs de verificação da posição do que será apagado impedem isso), nunca vai apontar para a borda.
                */ 
            }

            // ifs de verificação da posição do que será apagado:
            
            if ((itr + index) == (arr.end()-1)){                    
                itr = arr.begin() + 1;
                index = 0;
                arr.erase(arr.begin() + 1); //se itr + index resultar para a borda do vetor, significa que deveria estar no inicio

            }

            else if((itr + index) > (arr.end()-1)){ 
                index = (itr + index) - (arr.end() - 1); /*se itr + index resultar para um enredeço fora da borda do vetor, ou seja, um 
                maior que esta, precisamos descontar o endereço da borda, resultando num número inteiro que corresponde a quantidade de 
                passos restantes. Como a borda já foi contada nos passos, continuamos a soma dos passos a partir do inicio do vetor, 
                porque o passo dado para ir até a  borda é o mesmo passo para chegar no inicio do vetor (lembre-se de que o vetor funciona
                como um ciclo). 
                Neste ponto teremos a garantia de que, no mínimo o proxímo elemento depois do início do vetor será apagado. Ou seja, é 
                impossível apagar o inicio do vetor nesse caso, porque a soma deveria ter parado na borda do final, exectuando o if acima.
                como o if de cima não foi executado, a soma não parou na borda, sendo um lemento depois do primeiro que deve ser apagado.
           */
                itr = arr.begin() + 1;
                arr.erase(itr + index);
            }

            else{

                arr.erase(itr + index);  
            }

            itr = itr + index - 1;// itr sempre apontará para o elemento antecessor ao elemento apagado
            n -= 1;
        }

        cout << "Case " << i << ": " << arr[n] << "\n";
    }

    return 0;
}
