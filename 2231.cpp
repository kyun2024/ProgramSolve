#include <iostream>

using namespace std;

int dp[1000100]={0,};

int main(){
    int i,n,r;
    for(i=1;i<=1000000;i++){
        r=i;
        n=i;
        while(n>0){
            r+=n%10;
            n/=10;
        }
        if(dp[r]==0)dp[r]=i;
    }
    cin >> n;
    cout << dp[n] << endl;
    return 0;
}