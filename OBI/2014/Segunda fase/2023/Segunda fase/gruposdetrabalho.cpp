#include <iostream>
#include <algorithm>

using namespace std;

void maior(int &e1, int &e2){
    if(e1 > e2){
        return;
    }
    int c;
    c = e1;
    e1 = e2;
    e2 = c;
    return;
}

int main(void){
    int est, gost, ngost, e1, e2, ncont = 0;

    cin >> est >> gost >> ngost;

    int vgost[gost][2] = {}, vngost[ngost][2] = {}, trio[3];

    for(int j = 0; j < gost; j++){
        cin >> e1 >> e2;
        maior(e1, e2);
        for(int i=0; i < 2; i++){
            if (vgost[e1][i] == 0){
                vgost[e1][i] = e2;
                cout << "vgost: " << vgost[e1][i] << "\n";
            }
        }
    }    
    
    //leitura dos pares que n querem estar juntos
    for(int i=0; i < ngost; i++){
        cin >> e1 >> e2;
        maior(e1, e2);
        for(int i=0; i < 2; i++){
            if (vngost[e1][i] == 0){
                vngost[e1][i] = e2;
            }
        }        
    }

    //leitura dos trios
    
    for(int i=0; i < est/3; i++){
        cin >> trio[0] >> trio[1] >> trio[2];
        sort(trio, trio+3);

        for(int j = 0; j < 2; j++){
            if(vgost[trio[j]][0] == 0){
                continue;
            }
            
            else if(vngost[trio[j]][0] == 0){
                continue;
            }

            if(vgost[trio[j]][0] != trio[j+1] or vgost[trio[j]][1] != trio[j+1]){
                ncont++;
            }   

            else if(vgost[trio[j]][0] != trio[j+2] or vgost[trio[j]][1] != trio[j+2]){
                ncont++;
            }
            
            else if(vngost[trio[j]][0] != trio[j+1] or vngost[trio[j]][1] != trio[j+1]){
                ncont++;
            }

            else if(vgost[trio[j]][0] != trio[j+2] or vgost[trio[j]][1] != trio[j+2]){
                ncont++;
            }
            
        }
        
    }
    
    cout << ncont << "\n";

}