#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

unordered_map<string, int> graph_pos;
vector<vector<int>> graph;
int pos = 0;
int len = 0;

int createPos(char a[17]){
    if ((graph_pos.find(a)) == graph_pos.end()){
        graph_pos[a] = pos;
        pos++;
    }
    return 0;
}

int addInGraph(char a[17], char b[17]){
    graph[graph_pos[a]].push_back(graph_pos[b]);

    graph[graph_pos[b]].push_back(graph_pos[a]);

    return 0;
}

// int distance(int root, int search, set<int> memo){
//     int connection;
//     memo.insert(root);
//     cout << "tamanho do root " << graph[root].size() << "\n";
//     for(int i = 0; i<graph[root].size(); i++){
//         connection = graph[root][i];
//         if (memo.find(connection) == memo.end()){//not in memo
//             if (connection == search){
//                 len++;
//                 cout << "achei de primeira, encontrei no " << root << "\n";
//                 cout << "len: " << len << "\n";
//                 return 1;
//             }
//             else {
//                 cout << "procurando no " << connection << "\n";
//                 if(distance(connection, search, memo)){
//                     len++;
//                     cout << "encontrei no " << connection << "\n";
//                     cout << "len: " << len << "\n";
//                     return 1;
//                 }
//             }
//         }
//     }
//     return 0;
// }

int main (void){
    char n[3];

    char a[17];
    char b[17];

    cin >> n;
    while(cin >> a and a[0] != '-'){
        cin >> b;

        createPos(a);
        createPos(b);

        graph.resize(pos);//vectors never resize with the [] operator

        addInGraph(a, b);
    }


    while(cin >> a and a[0] != '*'){
        cin >> b;

        vector<int> dist(pos, -1);

        int root = graph_pos[a];

        int end = graph_pos[b];

        queue<int> order;

        order.push(root);

        dist[root] = 0;

        int first = 0;

        //BFS Breadth-First Search
        while(!order.empty()){
            first = order.front(); order.pop();
            for(int rel : graph[first]){// for each element of the array in graph[first], do the following
                if(dist[rel] == -1){
                    dist[rel] = dist[first] + 1;
                    if(rel == end){
                        break;
                    }
                    order.push(rel);
                }
            }
        }

        if(dist[end] == -1){
            printf("%s-%s = sem conexão\n", a, b);
        }
        else{
            printf("%s-%s = %d\n", a, b, dist[end]);
        }
    }
    return 0;
}

/*
recusive function
called
store the root in the memo
o iº não está dentro do memo?
    se não: continua
    se sim: é igual ao que estamos procurando?
            se sim: retorna 1, achou e soma +1 no contador
            se não se: if (se chama de novo, procura nesse)
                se achou: soma +1 no contador e
                retorna
                se não: continua

se sair do for, retorna 0; 


*/

