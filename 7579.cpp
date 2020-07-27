#include <iostream>
#include <iomanip>

using namespace std;

int meml[101],cstl[101];
int dp[101][10001];

int main(){
    int n,m,M=0;
    int i,j;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> meml[i];
    for(i=1;i<=n;i++){
        cin >> cstl[i];
        M += cstl[i];
    }
    dp[1][cstl[1]]=meml[1];
    for(i=2;i<=n;i++){
        for(j=0;j<cstl[i];j++){
            dp[i][j]=dp[i-1][j];
        }
        if(cstl[i]==0){
            dp[i][j]=dp[i-1][j]+meml[i];
        }
        else dp[i][j]=max(dp[i-1][j],dp[i][0]+meml[i]);
        for(j=cstl[i]+1;j<=M;j++){
            dp[i][j]=dp[i-1][j];
            if(dp[i-1][j-cstl[i]]>0){
                dp[i][j]=max(dp[i-1][j-cstl[i]]+meml[i],dp[i][j]);
            }
        }
    }
    /*
    for(i=1;i<=n;i++){
        for(j=0;j<=M;j++){
            cout << setw(3) << dp[i][j];
        }
        cout << endl;
    }
    */
    for(i=0;i<=M;i++){
        if(dp[n][i]>=m)break;
    }
    cout << i << endl;
    return 0;
}