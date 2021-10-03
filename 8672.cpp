#include <iostream>

using namespace std;

int memo[31][1000001];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    //Init
    int i,j,k;
    for(i=1;i<=30;i++){
        k = (1<<i);
        memo[i][0] = memo[i][1]=1;
        for(j=2;j<=1000000;j++){
            memo[i][j]=(memo[i][j-1]+memo[i][j-2])%k;
        }
    }

    int T;
    int n,p;
    cin >> T;
    while(T--){
        cin >> n >> p;
        cout << memo[p][n] << '\n';
    }
    return 0;
}