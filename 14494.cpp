#include <iostream>

using namespace std;

int dp[1001][1001]={0,};

int main(){
    int r,c;
    for(c=1;c<=1000;c++){
        dp[1][c]=1;
        dp[c][1]=1;
    }
    for(r=2;r<=1000;r++){
        for(c=2;c<=1000;c++){
            dp[r][c]=(((dp[r][c-1]+dp[r-1][c])%1000000007)+dp[r-1][c-1])%1000000007;
        }
    }
    cin >> r >> c;
    cout << dp[r][c] << endl;
    return 0;
}