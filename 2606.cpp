#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt = 0;
vector<int> visit;
int node,edge;
vector<vector<int>> adj;

void recur(int host){
    visit[host]=1;
    cnt++;
    for(int i=0;i<node;i++){
        if(adj[host][i] && !visit[i]){
            recur(i);
        }
    }
}

int main(){
    cin >> node >> edge;
    visit.resize(node,0);
    adj.resize(node,vector<int>(node,0));
    for(int i=0;i<edge;i++){
        int a,b;
        cin >> a >> b;
        adj[a-1][b-1] = adj[b-1][a-1] = 1;
    }
    recur(0);
    cout << cnt-1 << endl;
}