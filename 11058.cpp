#include <iostream>

using namespace std;

unsigned long long dp[101];

int main(){
    int n,i;
    cin >> n;
    for(i=1;i<=5;i++){
        dp[i]=i;
    }
    for(i=6;i<=n;i++){
        dp[i]=max(dp[i-4]*3,dp[i-5]*4);
    }
    cout << dp[n] << endl;
    return 0;
}