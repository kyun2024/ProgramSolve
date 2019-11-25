#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(){
    vector<int> input_data;
    vector<vector<long long>> dp;
    int n, r;
    int i,j;
    cin >> n;
    n = n - 1;
    input_data.resize(n);
    dp.resize(n,vector<long long>(21,0));
    for(i=0;i<n;i++){
        cin >> input_data[i];
    }
    cin >> r;
    dp[0][input_data[0]]=1;
    for(i=1;i<n;i++){
        for(j=0;j<=20;j++){
            if(dp[i-1][j] && j+input_data[i] <= 20){
                dp[i][j+input_data[i]]+=dp[i-1][j];
            }
            if(dp[i-1][j] && j-input_data[i] >= 0){
                dp[i][j-input_data[i]]+=dp[i-1][j];
            }
        }
    }
    cout << dp[n-1][r] << endl;
    return 0;
}