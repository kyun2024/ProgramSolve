#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct abc{
    double v,t;
};

int main(){
    vector<int> dp;
    vector<abc> v;
    int t,n,i,j,m,res;
    cin >> t;
    while(--t>=0){
        cin >> n;
        v.clear();
        v.resize(n);
        for(i=0;i<n;i++){
            cin >> v[i].v >> v[i].t;
        }
        res=0;
        dp.clear();
        dp.resize(n);
        for(i=0;i<n;i++){
            m=0;
            for(j=0;j<i;j++){
                if(v[j].v<v[i].v && v[j].t>v[i].t){
                    m = max(m,dp[j]);
                }
            }
            dp[i]=m+1;
            res = max(res,dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}