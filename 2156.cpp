#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int i,j;
    int n;
    vector<int> input_data,dp;

    cin >> n;
    input_data.resize(n);
    dp.resize(n);
    for(i=0;i<n;i++){
        cin >> input_data[i];
    }
    dp[0] = input_data[0];
    dp[1] = input_data[1]+dp[0];
    dp[2] = max(input_data[0]+input_data[2],input_data[1]+input_data[2]);
    for(i=3;i<n;i++){
        dp[i]=max(*max_element(dp.begin(),dp.begin()+i-1)+input_data[i],*max_element(dp.begin(),dp.begin()+i-2)+input_data[i]+input_data[i-1]);
    }
    cout << *max_element(dp.begin(),dp.end());
}