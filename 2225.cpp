#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> v;
    int n,k;
    int i,j;
    cin >> n >> k;
    v.resize(k+1,vector<int>(n+1,0));
    for(i=0;i<=n;i++){
        v[1][i]=1;
    }
    for(i=2;i<=k;i++){
        v[i][0]=1;
        for(j=1;j<=n;j++){
            v[i][j]=(v[i-1][j]+v[i][j-1])%1000000000;
        }
    }
    cout << v[k][n] << endl;
    return 0;
}