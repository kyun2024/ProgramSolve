#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<int> p;
int n;

int main(){
    int i,j;
    cin >> n;
    p.resize(n);
    dp.resize(n,vector<int>(n+1,0));
    for(i=0;i<n;i++){
        cin >> p[i];
    }
    for(j=1;j<=n;j++){
        dp[0][j]=j*p[0];
    }
    for(i=1;i<n;i++){
        for(j=1;j<=i;j++){
            dp[i][j] = dp[i-1][j];
        }
        for(j=i+1;j<=n;j++){
            dp[i][j] = max(max(dp[i][j-i-1],dp[i-1][j-i-1])+p[i],dp[i-1][j]);
        }
    }
    int max_val = dp[0][n];
    for(i=1;i<n;i++){
        max_val = max(max_val,dp[i][n]);
    }
    cout << max_val << endl;
    return 0;
}