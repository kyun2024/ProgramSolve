#include <iostream>

using namespace std;

int d[101][101];

int main(){
    int n;
    int i,j,k;

    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> d[i][j];
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                d[i][j]|=d[i][k]&d[k][j];
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}