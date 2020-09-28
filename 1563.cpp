#include <iostream>

using namespace std;

int memo[1001][2][3];

const int divider = 1000000;

int main(){
    int n,i;
    memo[1][0][0]=1; //O
    memo[1][0][1]=1; //A
    memo[1][1][0]=1; //L
    for(i=2;i<=1000;i++){
        memo[i][0][0]=(memo[i-1][0][0]+memo[i-1][0][1]+memo[i-1][0][2])%divider;
        memo[i][0][1]= memo[i-1][0][0];
        memo[i][0][2]= memo[i-1][0][1];
        memo[i][1][0]= (memo[i-1][0][0]+memo[i-1][0][1]+memo[i-1][0][2]+
                        memo[i-1][1][0]+memo[i-1][1][1]+memo[i-1][1][2])%divider;
        memo[i][1][1]= memo[i-1][1][0];
        memo[i][1][2]= memo[i-1][1][1];
    }
    cin >> n;
    cout << (memo[n][0][0]+memo[n][0][1]+memo[n][0][2]+memo[n][1][0]+memo[n][1][1]+memo[n][1][2])%divider << endl;

}