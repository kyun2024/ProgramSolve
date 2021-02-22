#include <iostream>

using namespace std;

constexpr long long div_n = 1000000007;

int memo[101][101][101];
bool visited[101][101][101];

int dfs(long long n,int l,int r){
    long long res = 0;
    if(l==1 && r==1){
        if(n==1)return 1;
        else return 0;
    }
    if(visited[n][l][r])return memo[n][l][r];
    if(l>1){
        res = (res + dfs(n-1,l-1,r))%div_n;
    }
    if(r>1){
        res = (res + dfs(n-1,l,r-1))%div_n;
    }
    if(l<=n-1 && r<=n-1 && l+r<=n){
        res = (res + (n-2)*dfs(n-1,l,r))%div_n;
    }
    visited[n][l][r]=true;
    return memo[n][l][r]=res;
}

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    if(l+r>n+1){
        cout << 0 << endl;
    }
    else cout << dfs(n,l,r) << endl;

    return 0;
}