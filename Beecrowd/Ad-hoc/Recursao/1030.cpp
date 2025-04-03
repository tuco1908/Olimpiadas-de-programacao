/*
Explicação do código: 
Será criado um array que terá todos os elementos em ordem decrescente e vai simular um círculo utilizando o operador %.
Os elementos começarão a ser inseridos no array a partir do índice 1, o índice 0 não terá nenhum valor. 
Para isso, terá uma variável chamada index que conterá o índice do próximo elemento a ser morto.  Este dado sofrerá 
sempre a  oferação de resto de divisão (%) com o tamanho atual do array. O resultado da operação será 
o índice de um elemento.
Exemplo: 6 % 5 - 1 = 1  =  | Index é maior do que o tamanho do array circular, por isso precisa dividir pelo seu
tamanho, que vai resultar na quantidade de ciclos completos. O resto da divisão será um valor menor que o tamanho do
vetor, mas como o númerosendo correspondente a
number = quantidade total de elementos do array. Podemos ir diminuindo até ficar menor que o step, os elementos que 
sobrarem serão os que vão ser printados. 
step = inteiro, que somado ao ínidice de um elemento do array resulta no próximo elemento a ser retirado do array. 
*/

#include <vector>

using namespace std;

int remaning(int n, int k, vector<int>arr){
    if (n == 1) {
        return arr[n];
    }
    
}
