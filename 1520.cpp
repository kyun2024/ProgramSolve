#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<vector<int>> dp,v;

void q(int r,int c){
    if(r>0 && v[r][c]<v[r-1][c]){
        if(dp[r-1][c]==0)q(r-1,c);
        dp[r][c] += max(dp[r-1][c],0);
    }
    if(c>0 && v[r][c]<v[r][c-1]){
        if(dp[r][c-1]==0)q(r,c-1);
        dp[r][c] += max(dp[r][c-1],0);
    }
    if(r<dp.size()-1 && v[r][c]<v[r+1][c]){
        if(dp[r+1][c]==0)q(r+1,c);
        dp[r][c] += max(dp[r+1][c],0);
    }
    if(c<dp[0].size()-1 && v[r][c]<v[r][c+1]){
        if(dp[r][c+1]==0)q(r,c+1);
        dp[r][c] += max(dp[r][c+1],0);
    }
    if(dp[r][c]==0)dp[r][c]=-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    int i,j;
    cin >> n >> m;
    dp.resize(n,vector<int>(m,0));
    v.resize(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    dp[0][0]=1;
    q(n-1,m-1);
    cout << dp[n-1][m-1] << endl;
    return 0;
}