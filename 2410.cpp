#include <iostream>

using namespace std;

constexpr int modn = 1'000'000'000;

int dp[1000001];

int main(){
    int n;
    int i,j;
    cin >> n;
    dp[0]=1;
    for(i=1;i<=n;i++){
        dp[i]=(dp[i-1]+(i%2==0)*dp[i/2])%modn;
    }
    cout << dp[n] << endl;
}