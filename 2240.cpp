#include <iostream>

using namespace std;

int dp[1001][31];
int a[1001];

int main(){
    int n,k;
    int i,j;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+(a[i]==1);
    }
    for(j=1;j<=k;j++){
        for(i=1;i<=n;i++){
            dp[i][j]=(a[i]%2!=j%2)+max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    cout << max(dp[n][k],dp[n][k-1]) << endl;
}