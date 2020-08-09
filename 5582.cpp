#include <iostream>
#include <string>

using namespace std;

int memo[4001][4001];
int res;

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    int i,j;
    for(i=0;i<str2.length();i++){
        for(j=0;j<str1.length();j++){
            if(str1[j]==str2[i]){
                memo[i+1][j+1]=memo[i][j]+1;
                res = max(res,memo[i+1][j+1]);
            }
        }
    }
    cout << res << endl;
    return 0;
}