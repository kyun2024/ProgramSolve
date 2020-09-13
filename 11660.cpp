#include <iostream>

using namespace std;

int a[1025][1025],s[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    int r1,c1,r2,c2;
    int i,j;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            s[i][j]=a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
        }
    }
    for(i=1;i<=m;i++){
        cin >> r1 >> c1 >> r2 >> c2;
        cout << s[r2][c2]-s[r1-1][c2]-s[r2][c1-1]+s[r1-1][c1-1] << '\n';
    }
    return 0;
}