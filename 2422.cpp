#include <iostream>

using namespace std;

bool mat[201][201];

int main(){
    int n,m,res=0;
    int i,j,k;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> j >> k;
        mat[j][k]=mat[k][j]=1;
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            for(k=j+1;k<=n;k++){
                res += !(mat[i][j]|mat[j][k]|mat[i][k]);
            }
        }
    }
    cout << res << endl;
    return 0;
}