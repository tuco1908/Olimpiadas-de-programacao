/*solução feita com ajuda do chat gpt*/

#include <iostream>
#include <string>

using namespace std;

string complementary(const string &dna, int len){ //const impede de modificar a string é apenas para leitura
    string compdna;
    for(int i = 0; i < len; i++){
        if(dna[i] == 'A'){
            compdna.push_back('T');
        }

        else if(dna[i] == 'T'){
            compdna.push_back('A');
        }

        else if(dna[i] == 'C'){
            compdna.push_back('G');
        }

        else{
            compdna.push_back('C');
        }
    }
    return compdna;
}

bool is_palindrome(string &compdna, string &dna, int start, int len){
    int end = len - 1 + start;
    while(start < end){
        if(dna[start] != compdna[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main(void){
    string dna, compdna;
    int n;

    while(cin >> dna){

        int len = dna.size();

        compdna = complementary(dna, len);

        if(len%2 != 0){
            n = len - 1;
        }

        else{
            n = len;
        }

        int ans[2] = {-1, 0};
        bool founded = false;
        
        for(n; n >= 4; n -= 2){
            if(founded){
                break;    
            }
            for(int i = 0; i <= len-n; i++){
                if(is_palindrome(compdna, dna, i, n)){
                ans[0] = i+1;
                ans[1] = n;
                founded = true;
                break;
                }
            }
        }
        
        if(ans[0] == -1){
            cout << "false\n";
        }

        else{
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}