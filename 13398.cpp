#include <iostream>

using namespace std;

int v[100001];
int memo[100001][2];

int main(){
    int n,i,res=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    memo[1][0] = 0; //exclude
    memo[1][1] = v[1];
    res = memo[1][1];
    for(i=2;i<=n;i++){
        memo[i][1]=max(v[i],v[i]+memo[i-1][1]);
        res = max(res,memo[i][1]);
        memo[i][0]=max(memo[i-1][1], v[i]+memo[i-1][0]);
        res = max(res,memo[i][0]);
    }
    
    cout << res << endl;
    return 0;
}