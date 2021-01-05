#include <iostream>

using namespace std;

long long t[31][31];

int main(){
    int i,j;
    long long s=0;
    t[1][1]=1;
    for(i=2;i<=30;i++){
        for(j=1;j<=i;j++){
            t[i][j]=t[i-1][j-1]+t[i-1][j];
        }
    }
    int r,c,w;
    cin >> r >> c >> w;
    for(i=0;i<w;i++){
        for(j=0;j<=i;j++){
            s += t[r+i][c+j];
        }
    }
    cout << s << endl;
}