#include <iostream>
#include <iomanip>

using namespace std;

int dp[50001][3];
int a[50001];
int s[50001];

int main(){
    int n,k;
    int i,j,sum_val=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    cin >> k;
    for(i=1;i<=k;i++){
        sum_val += a[i];
    }
    for(;i<=n;i++){
        s[i-k]=sum_val;
        sum_val += a[i] - a[i-k];
    }
    s[n-k+1]=sum_val;
    /*
    for(i=1;i<=n-k+1;i++){
        cout << s[i] << " ";
    }
    cout << endl;
    */
    for(i=1;i<=n-k+1;i++){
        dp[i][0]=max(dp[i-1][0],s[i]);
        if(i>k)dp[i][1]=max(dp[i-1][1],s[i]+dp[i-k][0]);
        if(i>2*k)dp[i][2]=max(dp[i-1][2],s[i]+dp[i-k][1]);
    }
    /*
    for(j=0;j<3;j++){
        for(i=1;i<=n-k+1;i++){
            cout << setw(4) << right << dp[i][j];
        }
        cout << endl;
    }
    */
    cout << dp[n-k+1][2] << end;
    return 0;
}