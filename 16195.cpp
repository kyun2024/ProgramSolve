#include <iostream>

using namespace std;

bool check[1001][1001];
int memo[1001][1001];

int dfs(int n,int m){
    if(n<0)return 0;
    if(check[n][m])return memo[n][m];
    check[n][m]=true;
    if(m==0 && n>0){
        return memo[n][m];
    }
    if(n==0){
        return memo[n][m]=1;
    }
    memo[n][m] = (memo[n][m] + dfs(n-1,m-1))%1000000009;
    memo[n][m] = (memo[n][m] + dfs(n-2,m-1))%1000000009;
    memo[n][m] = (memo[n][m] + dfs(n-3,m-1))%1000000009;
    return memo[n][m];
}

int main(){
    int T;
    int n,m;
    cin >> T;
    while(T--){
        cin >> n >> m;
        cout << dfs(n,m) << endl;
    }
    return 0;
}