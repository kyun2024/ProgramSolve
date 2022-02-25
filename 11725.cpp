#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj_list[100001];
bool visited[100001];
int parent[100001];

struct qt{
    int c, p;
};

int main(){
    int n;
    int i,j,a,b;
    cin >> n;
    for(i=1;i<n;i++){
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    queue<qt> q;
    q.push({1,0});
    visited[1] = 1;
    while(!q.empty()){
        qt x = q.front();
        q.pop();
        parent[x.c] = x.p;
        visited[x.c] = 1;
        for(auto node : adj_list[x.c])
        {
            if(!visited[node])q.push({node, x.c});
        }
    }
    for(i=2;i<=n;i++){
        cout << parent[i] << '\n';
    }
    return 0;
}