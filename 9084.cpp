#include <iostream>
#include <memory.h>

using namespace std;

int dp[20][10001];
int v[20];

int main(){
    int t;
    int n,m;
    int i,j;
    cin >> t;
    while(--t>=0){
        cin >> n;
        for(i=0;i<n;i++){
            cin >> v[i];
        }
        cin >> m;
        memset(dp,0,sizeof(dp));
        for(j=0;v[0]*j<=m;j++){
            dp[0][v[0]*j]=1;
        }
        for(i=1;i<n;i++){
            for(j=0;j<v[i];j++){
                dp[i][j]=dp[i-1][j];
            }
            for(j=v[i];j<=m;j++){
                dp[i][j]=dp[i][j-v[i]]+dp[i-1][j];
            }
        }
        cout << dp[n-1][m] << endl;
    }
    return 0;
}