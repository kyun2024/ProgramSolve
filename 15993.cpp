#include <iostream>

using namespace std;

int memo[100001][2];

int main(){
    int i;
    memo[1][1]=1; memo[2][0]=1; memo[2][1]=1; memo[3][0]=2; memo[3][1]=2;
    for(i=4;i<=100000;i++){
        memo[i][0]=(memo[i][0]+memo[i-1][1])%1000000009;
        memo[i][0]=(memo[i][0]+memo[i-2][1])%1000000009;
        memo[i][0]=(memo[i][0]+memo[i-3][1])%1000000009;
        memo[i][1]=(memo[i][1]+memo[i-1][0])%1000000009;
        memo[i][1]=(memo[i][1]+memo[i-2][0])%1000000009;
        memo[i][1]=(memo[i][1]+memo[i-3][0])%1000000009;
    }
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << memo[n][1] << " " << memo[n][0] << endl;
    }
    return 0;
}