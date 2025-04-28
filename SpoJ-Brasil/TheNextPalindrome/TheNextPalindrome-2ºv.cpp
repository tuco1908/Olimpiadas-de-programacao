#include <iostream>
#include <string>
#include <algorithm>//contém a função reverse
#include <set>

using namespace std;

/*Comparação de strings numéricas é igual a comparação entre números. */

bool allnine(string str){
    set<char>s (str.begin(), str.end()); //vai ser um conjunto de chars, porque a string é um array de chars. 
    auto it = s.begin(); /*auto determina o tipo da variável que virá após. Faz o compilador determinar o tipo durante
    execução do programa */
    if(*it == '9'){
        return true;
    }
    return false;
}

void plus1(string &strpart,long lenpart){
    for (int i = lenpart - 1 ; i >= 0; i--){
        if (strpart[i] == '9'){
            strpart[i] = '0';
        }

        else{
            strpart[i] = strpart[i] + 1;
            return;
        }
    }
    return;
}

int main(void){
    int t;
    long len, lenpart;
    string str, strleft, strright, revleft;
    cin >> t;
    while (t != 0){
        t--;
        cin >> str; /* não importa o tamanho do dado fornecido na entrada, x vai guardá-lo como string, separando cada
        caractere em uma célula do array de caracteres*/
        len = str.length();/*A função length retorna o tamanho da string, não considerando o caractere nulo.*/
        
        if(allnine(str)){
            cout << '1';
            for(int i = 0; i < len-1; i++){
                cout << '0';
            }
            cout << '1' << "\n";
            continue;
        }

        if (len == 1){
            str[0] = str[0] + 1;
            cout << str << "\n"; 
            continue; 
        }

        lenpart = len/2;
        if (len%2 == 0){//número com casas par
            strleft = str.substr(0, lenpart);
            strright = str.substr(lenpart);// se não der a quantidade de caracteres a função vai até o final da string. 
            revleft = strleft;
            reverse(revleft.begin(), revleft.end());
   
            if(revleft > strright){
                strright = revleft;
            }
                
            else{
                plus1(strleft, lenpart);
                strright = strleft;
                reverse(strright.begin(), strright.end());
            }
            
            cout << strleft + strright << "\n";// vai imprimir uma string em seguida da outra.

        }

        else{//número com casas impar
            strleft = str.substr(0, lenpart);
            strright = str.substr(lenpart+1); 
            str = str.substr(lenpart, 1);
            revleft = strleft;
            reverse(revleft.begin(), revleft.end());

            if(revleft > strright){
                strright = revleft;
            }
                
            else{
                plus1(str, 1);
                if (str[0] == '0'){
                    plus1(strleft, lenpart);
                }
                strright = strleft;
                reverse(strright.begin(), strright.end());
            }
            
            cout << strleft + str + strright << "\n";
        }
    }

    return 0;
}