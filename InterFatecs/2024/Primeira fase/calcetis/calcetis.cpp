#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int v, n, p, max;
    cin >> v >> n;
    vector<int> prod;
    if (v <= 110){
        max = 140-v;/* 200-60-v resulta no max possível, 140 = 200-60. Uso 60 porque são os dois valores mínimos 30,
        possiveis*/
        while (n != 0){
            n--;
            cin >> p;
            if(p <=  max){
                prod.push_back(p);
            }
        }
        n = prod.size();
        
        for (int i = 0; i < n-2; i++){
            for (int j = i+1 ; j < n-1; j++){
                for (int k = j+1; k < n; k++){
                    if (v + prod[i] + prod[j] + prod[k] == 200){
                        cout << "fretegratis" << "\n";
                        return 0; 
                    }
                }
                
            }
            
        }
        
    }
    cout << "fretepago\n"; 
    return 0; 
}