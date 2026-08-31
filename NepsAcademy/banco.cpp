#include <iostream>
#include <queue>

using namespace std;

int main(){

    int c, n, t, d, top, resp = 0;

    cin >> c >> n;

    priority_queue<int, vector<int>, greater<int>> q;  //the vector is mandatory in order to change the comparator  

    //greater comparator if false, make the lowest value go to the top, if true, make the greatest (bigger) go down

    if(c >= n){
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i<c; i++){

        cin >> t >> d;

        q.push(t+d);
    }
        
    for(int i = c; i<n; i++){ //executed n-c times

        cin >> t >> d;

        if((q.top() - t) > 20){
            resp++;
        }
            
        top = q.top();
        q.pop();
        q.push(max(top, t)+ d);

    }
    
    cout << resp << "\n";

    return 0;
}
