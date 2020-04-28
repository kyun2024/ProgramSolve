#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> v,dp;
    int i,j,m;
    cin >> n;
    v.resize(n);
    dp.resize(n,0);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    dp[0]=1;
    for(i=1;i<n;i++){
        m=0;
        for(j=0;j<i;j++){
            if(v[j]<v[i]){
                m=max(m,dp[j]);
            }
        }
        dp[i]=m+1;
    }
    cout << n-*max_element(dp.begin(),dp.end()) << endl;
}