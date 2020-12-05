#include <iostream>

using namespace std;

int m[2001][2001];

int main(){
    int i,j;
    m[0][0]=1;
    for(i=1;i<=2000;i++){
        for(j=0;j<i;j++)m[i][j]=m[i-1][j];
        for(;j<=2000;j++){
            m[i][j]=(m[i-1][j-i]+m[i-1][j])%100999;
        }
    }
    cin >> j;
    while(j--){
        cin >> i;
        cout << m[2000][i] << endl;
    }
    return 0;
}

