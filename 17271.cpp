#include <iostream>

using namespace std;

int dp[10001];

constexpr int modn=1'000'000'007;

int main(){
    int n,m;
    int i;
    cin >> n >> m;
    dp[0]=1;
    for(i=1;i<m;i++){
        dp[i]=dp[i-1]%modn;
    }
    for(i=m;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-m])%modn;
    }
    cout << dp[n] << endl;
    return 0;
}