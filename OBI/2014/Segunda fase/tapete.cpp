#include <iostream>

using namespace std;

int main(void){
    int comp, tap;
    long long unsigned quad, max;
    cin >> comp >> tap;
    quad = 0;
    max = comp - tap + 1; //número máximo possível que pode ser includído na soma
    quad = max*max + 1*(tap-1); 
    cout << quad << "\n";
    return 0;        
}