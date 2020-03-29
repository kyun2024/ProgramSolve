#include <iostream>

using namespace std;

int tris[122];
int dp[32'0001];

int q(int n){
    int i,j;
    int res=300000;
    if(dp[n]!=0)return dp[n];
    for(i=1;tris[i]<n;i++);
    for(j=i-1;j>=1;j--){
        res = min(res,q(n-tris[j]));
    }
    return dp[n]=res+1;
}

int main(){
    int i,a;
    for(i=1;i<=121;i++){
        tris[i]=i*(i+1)*(i+2)/6;
        dp[tris[i]]=1;
    }
    cin >> a;
    cout << q(a) << endl;
}