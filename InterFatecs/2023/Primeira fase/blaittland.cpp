#include <iostream>

using namespace std;

int main(){

    int n, total, count;

    cin >> n;
    char str[n];
    cin >> str;

    for(int i=0; i<n; i++){
        count = 0;
        for(int j = i+1; j<n; j++){
            if(str[i] > str[j]){
                count++;
            }
            else{
                break;
            }
            if(count > 5){
                cout << "A Database Systems student read a book.\n";
                return 0;
            }
        }
        total += count;
    }
    cout << total;
    return 0;
}