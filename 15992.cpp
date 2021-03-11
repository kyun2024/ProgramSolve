#include <iostream>

using namespace std;

int memo[1001][1001];
bool visited[1001][1001];

int dfs(int n,int m){
    if(n==0 && m==0)return 1;
    if(m==0)return 0;
    if(visited[n][m])return memo[n][m];
    visited[n][m]=true;
    for(int i=1;i<=min(n,3);i++){
        memo[n][m] = (memo[n][m]+dfs(n-i,m-1))%1000000009;
    }
    return memo[n][m];
}

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << dfs(n,m) << endl;
    }
    return 0;
}