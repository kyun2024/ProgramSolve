#include <iostream>

using namespace std;

int main(){
    long long dp[81]={0,};
    int n;
    cin >> n;
    dp[1]=4;
    dp[2]=6;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}