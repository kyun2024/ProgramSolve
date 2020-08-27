#include <iostream>

using namespace std;

char ar[400][400];

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=-2*(n-1);i<=2*(n-1);i++){
        for(j=-2*(n-1);j<=2*(n-1);j++){
            if(max(abs(i),abs(j))%2==0)ar[i+2*(n-1)][j+2*(n-1)]='*';
            else ar[i+2*(n-1)][j+2*(n-1)]=' ';
        }
    }
    for(i=0;i<=4*(n-1);i++){
        for(j=0;j<=4*(n-1);j++)
        {
            cout << ar[i][j];
        }
        cout << '\n';
    }
    return 0;
}