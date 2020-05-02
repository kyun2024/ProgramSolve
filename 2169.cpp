#include <iostream>

using namespace std;

int a[1001][1001],dp[1001][1001],dpa[1001][1001];

int main(){
    int n,m;
    int i,j;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    dp[1][1]=dpa[1][1]=a[1][1];
    for(i=2;i<=m;i++){
        dpa[1][i]=dp[1][i]=dp[1][i-1]+a[1][i];
    }
    for(i=2;i<=n;i++){
        dp[i][1]=dp[i-1][1]+a[i][1];
        for(j=2;j<=m;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+a[i][j];
        }
        dpa[i][m]=dp[i-1][m]+a[i][m];
        for(j=m-1;j>=1;j--){
            dpa[i][j]=max(dpa[i][j+1],dp[i-1][j])+a[i][j];
        }
        for(j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j],dpa[i][j]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}