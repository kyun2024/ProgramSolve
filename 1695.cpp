#include <iostream>

using namespace std;

int a[5001],dp[5001][5001];

int main(){
    int n;
    int i,j,r=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    for(i=2;i<=n;i++){
        for(j=0;j<n-i+1;j++){
            if(a[1+j]==a[i+j])dp[1+j][i+j]=dp[2+j][i+j-1];
            else dp[1+j][i+j]=min(dp[2+j][i+j],dp[1+j][i+j-1])+1;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}