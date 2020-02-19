#include <iostream>

using namespace std;

int dp[101][101][2];

void pre(){
    int i,j,k;
    dp[0][1][0]=1;
    dp[0][1][1]=1;
    for(i=2;i<=100;i++){
        dp[0][i][0]=dp[0][i-1][0]+dp[0][i-1][1];
        dp[0][i][1]=dp[0][i-1][0];
    }
    for(i=1;i<=100;i++){
        dp[i][i+1][1]=1;
        for(j=i+2;j<=100;j++){
            dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][1];
            for(k=0;k<=i;k++){
                dp[i][j][1]+=dp[i-k][j-1-k][0];
            }
        }
    }
}

int main(){
    pre();
    int t,a,b;
    cin >> t;
    while(--t>=0){
        cin >> a >> b;
        if(a<b || b<0){
            cout << 0 << endl;
        }
        else{
            cout << dp[b][a][0] + dp[b][a][1] << endl;
        }
    }
}