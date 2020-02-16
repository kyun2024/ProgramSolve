#include <iostream>

using namespace std;

struct ab{
    int a,b;
};

int main(){
    ab dp[46]={0,};
    int n,i;
    cin >> n;
    dp[0].a=1;
    for(i=1;i<=n;i++){
        dp[i].a=dp[i-1].b;
        dp[i].b=dp[i-1].a+dp[i-1].b;
    }
    cout << dp[n].a << " " << dp[n].b << endl;
    return 0;
}