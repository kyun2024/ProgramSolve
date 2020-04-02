#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> dp;
    vector<int> v;
    int n,m;
    int i,j,k;
    cin >> n;
    v.resize(n+1);
    dp.resize(n+1,vector<int>(n+1,0));
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    for(i=n;i>=1;i--){
        for(j=i;j<=n;j++){
            if(j-i==0){
                dp[i][j]=1;
            }
            else if(j-i==1){
                dp[i][j] = v[i] == v[j];
            }
            else{
                dp[i][j] = (v[i] == v[j])*dp[i+1][j-1];
            }
        }
    }
    // Test Code //
    // for(i=1;i<=n;i++){
    //     for(j=1;j<=n;j++){
    //         cout << std::setw(2) << std::right << dp[i][j];
    //     }
    //     cout << endl;
    // }
    cin >> m;
    for(i=0;i<m;i++){
        cin >> j >> k;
        cout << dp[j][k] << '\n';
    }
    return 0;
}