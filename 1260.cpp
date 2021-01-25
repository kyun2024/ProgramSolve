#include <iostream>
#include <queue>

using namespace std;

bool adj[1001][1001];
bool visited[1001];
int p_a[1001];

int n,m,start_n;

void dfs(int i){
    cout << i << " ";
    for(int j=1;j<=n;j++){
        if(!visited[j] && adj[i][j]){
            visited[j]=true;
            dfs(j);
        }
    }
}
void bfs(){
    int i;
    queue<int> q;
    visited[start_n]=true;
    q.push(start_n);
    while(!q.empty()){
        cout << q.front() << " ";
        for(i=1;i<=n;i++){
            if(!visited[i] && adj[q.front()][i]){
                visited[i]=true;
                q.push(i);
            }
        }
        q.pop();
    }
}

int main(){
    int n_s,n_e,i;
    cin >> n >> m >> start_n;
    for(i=0;i<m;i++){
        cin >> n_s >> n_e;
        adj[n_s][n_e]=adj[n_e][n_s]=true;
    }
    visited[start_n]=true;
    dfs(start_n);
    cout << '\n';
    fill_n(visited,n+1,false);
    bfs();
    cout << '\n';
    return 0;
}