#include <iostream>

using namespace std;

constexpr int modn=1'000'000'009;
int dp[1000001];

int main(){
    int i,n,t;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(i=4;i<=1000000;i++){
        dp[i]=(((dp[i-1]+dp[i-2])%modn)+dp[i-3])%modn;
    }
    cin >> t;
    while(--t>=0){
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}