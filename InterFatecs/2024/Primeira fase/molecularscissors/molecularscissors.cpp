#include <iostream>
#include <string>//contém clear()
#include <algorithm>//contem a função reverse()

using namespace std;

int main(void){
    string dna, compdna;
    int len;

    while(cin>>dna){// input até eof.
        len = dna.size();
        int count[2] = {-1, 0}, ans[2] = {-1, 0};
        compdna.clear();
        for (int i = 0; i < len; i++){
            if (dna[i] == 'A'){
                compdna.push_back('T');
            }

            else if (dna[i] == 'T'){
                compdna.push_back('A');
            }

            else if (dna[i] == 'G'){
                compdna.push_back('C');
            }

            else{
                compdna.push_back('G');
            }
        }
        
        reverse(compdna.begin(), compdna.end());

        cout << "compdna: " << compdna << "\n";
        for(int i = 0; i < len; i++){
            if(dna[i] == compdna[i]){
                if(count[0] == -1){
                    count[0] = i;
                    count[1] = 1;
                } 

                else{
                    count[1]++;
                }

                cout << "i dentro do if: " << i << "\n";
                cout << "dna["<< i << "]: " << dna[i] << "\n";
                cout << "compdna[" << i << "]: " << compdna[i] << "\n";

                for (int u = 0; u < 2; u++)
            {
                cout << "count dentro do primeiro if[" << u << "]: " << count[u] << "\n";
                cout << "ans dentro do primeiro if[" << u << "]: " << ans[u] << "\n";
            }
                cout << "\n";
            }
            
            else if(count[0] >= 0){
                    if(ans[1] < count[1]){
                        ans[0] = count[0];
                        ans[1] = count[1];

                        count[0] = -1;
                        count[1] = 0;
                    }
                    else if(ans[1] == count[1] and ans[0] > count[0]){
                        ans[0] = count[0];

                        count[0] = -1;
                        count[1] = 0;
                    }
                    cout << "i dentro do elseif: " << i << "\n";

                    for (int u = 0; u < 2; u++)
                {
                    cout << "count dentro do elseif[" << u << "]: " << count[u] << "\n";
                    cout << "ans dentro do elseif[" << u << "]: " << ans[u] << "\n";
                }
                    cout << "\n";
                }
        }
        for (int i = 0; i < 2; i++)
        {
            cout << "count[" << i << "]: " << count[i] << "\n";
            cout << "ans[" << i << "]: " << ans[i] << "\n";
        }
        
    
        if (count[0] >= 0){
            if(ans[1] < count[1]){
                ans[0] = count[0];
                ans[1] = count[1];

                count[0] = -1;
                count[1] = 0;
            }
            else if(ans[1] == count[1] and ans[0] > count[0]){
                ans[0] = count[0];

                count[0] = -1;
                count[1] = 0;
            }
        }

        if(ans[0] == -1){
            cout << "false\n";
        }

        else{
            cout << ans[0]+1 << " " << ans[1] << "\n";
        }

    }
    return 0;
}