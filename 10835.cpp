#include <iostream>

using namespace std;

int memo[2001][2001];
int leftv[2001];
int rightv[2001];

int dfs(int l,int r){
    if(l==0 || r==0)return 0;
    if(memo[l][r]!=0)return memo[l][r];
    int res=0;
    if(leftv[l]>rightv[r]){
        res = max(res,dfs(l,r-1)+rightv[r]);
    }
    res = max(res,dfs(l-1,r));
    res = max(res,dfs(l-1,r-1));
    return memo[l][r] = res;
}

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=n;i>=1;i--){
        cin >> leftv[i];
    }
    for(i=n;i>=1;i--){
        cin >> rightv[i];
    }
    for(i=1;i<=n;i++){          // left
        for(j=1;j<=n;j++){      // right
            if(leftv[i]>rightv[j]){
                memo[i][j] = max(memo[i][j],memo[i][j-1]+rightv[j]);
            }
            memo[i][j] = max(memo[i][j],memo[i-1][j]);
            memo[i][j] = max(memo[i][j],memo[i-1][j-1]);
        }
    }
    cout << memo[n][n] << endl;
    return 0;
}