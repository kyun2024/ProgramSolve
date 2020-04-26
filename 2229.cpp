#include <iostream>

using namespace std;

int dp[1001],a[1001];

int main(){
    int min_i,max_i;
    int i,j;
    int n;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    // dp[1] = 0;
    for(i=2;i<=n;i++){
        max_i=min_i=a[i];
        for(j=i-1;j>=1;j--){
            min_i=min(min_i,a[j]);
            max_i=max(max_i,a[j]);
            dp[i]=max(dp[i],max_i-min_i+dp[j-1]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}