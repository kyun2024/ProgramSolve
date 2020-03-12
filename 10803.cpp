#include <iostream>
#include <iomanip>

using namespace std;

int dp[10001][101];

int recur(int r,int c){
    if(dp[r][c]!=0){
        return dp[r][c];
    }
    if(3*r>=c*c){
        return dp[r][c]=recur(r-c,c)+1;
    }
    int res=1'000'000,i,g;
    for(i=1;i<=r/2;i++){
        res = min(res,recur(i,c)+recur(r-i,c));
    }
    for(i=1;i<=c/2;i++){
        res = min(res,recur(r,i)+recur(r,c-i));
    }
    return dp[r][c]=res;
}

int main(){
    int n,m;
    int i,j;
    cin >> n >> m;
    if(n<m)swap(n,m);
    for(i=1;i<=m;i++){
        dp[i][i]=1;
    }
    for(i=1;i<=n;i++){
        dp[i][1]=i;
    }
    for(i=1;i<=m;i++){
        dp[1][i]=i;
    }
    cout << recur(n,m) << endl;
    return 0;
}