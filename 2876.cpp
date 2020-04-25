#include <iostream>

using namespace std;

int a[100001][2],dp[100001][2];

int main(){
    int n;
    int i;
    int res,grade;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    dp[0][0]=1;
    dp[0][1]=1;
    res = 1;
    grade = 6;
    for(i=1;i<n;i++){
        if(a[i-1][0]==a[i][0]){
            dp[i][0]=dp[i-1][0]+1;
        }
        else if(a[i-1][1]==a[i][0]){
            dp[i][0]=dp[i-1][1]+1;
        }
        else{
            dp[i][0]=1;
        }
        if(a[i-1][0]==a[i][1]){
            dp[i][1]=dp[i-1][0]+1;
        }
        else if(a[i-1][1]==a[i][1]){
            dp[i][1]=dp[i-1][1]+1;
        }
        else{
            dp[i][1]=1;
        }
        res = max(res,dp[i][0]);
        res = max(res,dp[i][1]);
    }
    for(i=0;i<n;i++){
        if(dp[i][0]==res&&grade>a[i][0]){
            grade=a[i][0];
        }
        if(dp[i][1]==res&&grade>a[i][1]){
            grade=a[i][1];
        }
    }
    cout << res << " " << grade << endl;
    return 0;
}