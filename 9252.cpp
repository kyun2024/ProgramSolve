#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main(){
    int r,c;
    int i,j;
    string str1,str2,res;
    cin >> str1 >> str2;
    for(i=1;i<=str1.length();i++){
        for(j=1;j<=str2.length();j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    /*
    for(i=1;i<=str1.length();i++){
        for(j=1;j<=str2.length();j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[str1.length()][str2.length()] << endl;
    r=str1.length();
    c=str2.length();
    while(r>0 && c>0){
        if(str1[r-1]==str2[c-1]){
            res = str1[r-1] + res;
            r--;
            c--;
        }
        else{
            if(dp[r-1][c]>dp[r][c-1]){
                r--;
            }
            else{
                c--;
            }
        }
    }
    cout << res << endl;
    return 0;
}