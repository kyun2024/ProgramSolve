#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v,dp;
    int n,m;
    int i,j;
    cin >> n;
    v.resize(n);
    dp.resize(n,0);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    for(i=1;i<n;i++){
        m = -1;
        for(j=0;j<i;j++){
            if(j+v[j]>=i && (m > dp[j] || m<0)){
                m = dp[j];
            }
        }
        if(m<0)break;
        dp[i]=m+1;
    }
    if(i<n){
        cout << -1 << endl;
    }
    else{
        cout << dp[n-1] << endl;
    }
    return 0;
}