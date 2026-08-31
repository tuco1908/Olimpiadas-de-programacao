#include <iostream>
#include <map>

using namespace std;

int main(){
    int c, n, pc, pn, vc, vn;

    map<long int, long int> app;
    map<long int, long int> resp;

    cin >> c >> n;

    for(int i = 0; i < c; i++){
        cin >> pc >> pn;
        app[pc] = pn;
    }

    for(int i = 0; i < n; i++){
        cin >> vc >> vn;
        if(!(app[vc]) || app[vc] < vn){
            app[vc] = vn;
            resp[vc] = vn;
        }
    }

    for (auto& key : resp){
        cout << key.first << ' ' << key.second << "\n";
    }

    return 0;
}