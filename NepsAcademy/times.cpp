#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, t, h;
    string name;
    priority_queue<int> hab;
    map <int, string> jgdrs;

    cin >> n >> t;

    vector <string> teams[t]; //array that stores the teams;

    for (int i = n; i > 0; i--){
        cin >> name >> h;
        jgdrs[h] = name;
        hab.push(h);
    }

    for (int i = 0; !(hab.empty()); i++){
        i = i%t;
        int x = hab.top();
        teams[i].push_back(jgdrs[x]);
        hab.pop();
    }

    for (int i = 0; i<t; i++){

        sort(teams[i].begin(), teams[i].end());

        cout << "Time " << i+1 << "\n";
        for (string jgdr : teams[i]){
            cout << jgdr << "\n";
        }
        cout << "\n";
    }

}
