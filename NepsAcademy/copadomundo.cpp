#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main(void){

    queue<int> q;
    list<char> teams = {'A', 'B', 'C', 'D', 'E',
        'F', 'G', 'H', 'I', 'J', 'K', 'L',
         'M', 'N', 'O', 'P'};
    int a, b;

    for(int i = 1; i<16; i++){
        cin >> a >> b;
        q.push(a);
        q.push(b);
    }

    for(int matches = 8; matches >= 1; matches /= 2){

        list<char>::iterator it = teams.begin();
        
        for (int i = 0; i < matches; i++){
            
            auto left = it;
            auto right = next(it); // cannot be it++

            a = q.front();
            q.pop();
            b = q.front();
            q.pop();

            if(a > b){
                teams.erase(right);

                it = next(left);
            }
            else{ //b<a impossible to be tie
                teams.erase(left);

                it = next(right);
            }
        }
    }
    cout << *(teams.begin()) << "\n"; //prints what lasted
}
