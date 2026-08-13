#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;

    char str[n+2];

    cin >> str;

    cout << str[1];

    int p[2][3];//[player number][set/game/point]

    int server = 0;//player who serves. 0 player 1, 1 player 2

    int point(int p[][3]){
        p[server][3]++;
        if
    }
    


    for(char c : str){
        if(c == 'W') point(p[server][2]);
        else point(p[1-server][2]);
    }


    return 0;
}