#include <iostream>

using namespace std;

int main(){
    long long dp[68]={0,};
    int n,t;
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(t=4;t<=67;t++){
        dp[t]=dp[t-1]+dp[t-2]+dp[t-3]+dp[t-4];
    }
    cin >> n;
    while(--n>=0){
        cin >> t;
        cout << dp[t] << endl;
    }
    return 0;
}