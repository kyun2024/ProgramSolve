#include <iostream>

using namespace std;

int memo[100001];

int dfs(int n){
    if(n==0)return 1;
    if(memo[n]!=0)return memo[n];
    for(int i=min(n/2,3);i>=1;i--){
        memo[n] = (memo[n] + dfs(n-2*i))%1000000009;
    }
    if(n<=3){
        memo[n] = (memo[n] + 1)%1000000009;
    }
    return memo[n];
}

int main(){
    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        cout << dfs(x) << '\n';
    }
    return 0;
}