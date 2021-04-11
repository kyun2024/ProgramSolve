#include <iostream>
#include <queue>

using namespace std;

int adj[1001][1001];
bool check[1001];

int main(){
    queue<pair<int,int>> q;
    int a,b,n,m;
    int i,j,x,y;
    cin >> a >> b >> n >> m;
    for(i=0;i<m;i++){
        cin >> x >> y;
        adj[x][y]=adj[y][x]=1;
    }
    check[a]=1;
    q.push(make_pair(a,0));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        if(x==b)break;
        for(i=1;i<=n;i++){
            if(adj[x][i]==1 && !check[i]){
                check[i]=true;
                q.push(make_pair(i,y+1));
            }
        }
        q.pop();
    }
    if(q.empty()){
        cout << -1 << endl;
    }
    else cout << y << endl;
    return 0;
}