#include <iostream>

using namespace std;

int dp[101][10001];
int a[101][2];

int main(){
    int m,n;
    int i,j,k;
    cin >> m >> n;
    for(i=1;i<=n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<a[i][0];j++){
            dp[i][j]=dp[i-1][j];
        }
        for(j=a[i][0];j<=m;j++){
            for(k=0;k<=a[i][1]&&j-k*a[i][0]>=0;k++){
                dp[i][j]+=dp[i-1][j-k*a[i][0]];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}