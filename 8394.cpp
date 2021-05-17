#include <iostream>

using namespace std;

int memo[10000001][2];

int main(){
    memo[1][1]=1;
    for(int i=2;i<=10000000;i++){
        memo[i][0]=(memo[i-1][1])%10;
        memo[i][1]=(memo[i-1][0]+memo[i-1][1])%10;
    }
    int n;
    cin >> n;
    cout << ((memo[n][0]+memo[n][1])%10) << endl;
    return 0;
}