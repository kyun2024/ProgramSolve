#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct abc{
    int r,c,n;  
};

int main(){
    int n,number;
    int i,j,res=1;
    int r,c;
    vector<vector<int>> v,dp;
    vector<abc> ord;
    cin >> n;
    ord.resize(n*n);
    v.resize(n+2,vector<int>(n+2,0));
    dp.resize(n+2,vector<int>(n+2,0));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> v[i][j];
            ord[(i-1)*n+(j-1)].r=i;
            ord[(i-1)*n+(j-1)].c=j;
            ord[(i-1)*n+(j-1)].n=v[i][j];
        }
    }
    sort(ord.begin(),ord.end(),[](const abc& i,const abc& j){
        return i.n<j.n;
    });
    for(i=0;i<n*n;i++){
        r=ord[i].r;
        c=ord[i].c;
        number=ord[i].n;
        dp[r][c]=max((v[r-1][c]<number)*dp[r-1][c],max((v[r][c-1]<number)*dp[r][c-1],max((v[r+1][c]<number)*dp[r+1][c],(v[r][c+1]<number)*dp[r][c+1])))+1;
        res=max(res,dp[r][c]);
    }
    cout << res << endl;
    return 0;
}
