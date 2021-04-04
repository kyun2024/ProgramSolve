#include <iostream>

using namespace std;

int memo[4][10001];

int dfs(int n,int c){
    if(n==0)return 1;
    if(memo[c][n]!=0)return memo[c][n];
    for(int i=min(n,c);i>=1;i--){
        memo[c][n] += dfs(n-i,i);
    }
    return memo[c][n];
}

int main(){
    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        cout << dfs(x,3) << '\n';
    }
    return 0;
}