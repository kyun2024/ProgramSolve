#include <iostream>

using namespace std;

int dp[41];
int v[42];

int main(){
    int i,m,n,res=1;
    dp[0]=dp[1]=1;
    for(i=2;i<=40;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cin >> m >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    v[0]=0;
    v[n+1]=m+1;
    for(i=1;i<=n+1;i++){
        res *= dp[v[i]-v[i-1]-1];
    }
    cout << res << endl;
    return 0;
}