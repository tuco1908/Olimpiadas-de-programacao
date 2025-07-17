#include <iostream>
#include <algorithm>

//not solved yet

using namespace std;

bool eq(int n, long long a[], long long cop[]){
    bool equal = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != cop[i])
        {
            equal = false;
            break;
        }
    }
    return equal;
}

int main(void){
    int n;
    bool nofound = true, iguais;
    cin >> n;
    long long a[n+5], cop[n+5];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    copy(a, a+n, cop);
    sort(cop, cop+n);

    //pegando o primeiro segmento que encontrar;
    int indf = 0, indl = 0;
    for (int i = 0; i < n-1; i++)
    {        
        if (nofound){
            if(a[i] > a[i+1])
            {
                indf = i;
                nofound = false;
            }
        }

        else {
            if (a[i] < a[i+1])
            {
                indl = i;
                break;
            }

            if ((i == n-2) and (a[i] > a[i+1]))
            {
                indl = i+1;
            }
            
        }
    }
   
    if (indf == 0 and indl == 0)
    {
        iguais = eq(n, a, cop);

        if(iguais){
            indf = indl = 1;
            cout << "yes\n" << indf << " " << indl << "\n";
        }
        else{
            cout << "no\n";
        }
        
    }
    
    else{

        reverse(a+indf, a+indl+1);
        
        iguais = eq(n, a, cop);
        
        if(iguais){
            cout << "yes\n" << indf+1 << " " << indl+1 << "\n";
        }

        else {
            cout << "no\n";
        }
        
    }
    
   return 0; 
}