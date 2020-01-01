#include <iostream>

int A[15][15]={0,};

using namespace std;

int main(){
    int i,j;
    for(i=1;i<15;i++){
        A[0][i] = i;
    }
    for(i=1;i<15;i++){
        for(j=1;j<15;j++){
            A[i][j]=A[i-1][j]+A[i][j-1];
        }
    }
    int t;
    int r,c;
    cin >> t;
    while(t-->0){
        cin >> r >> c;
        cout << A[r][c] << endl;
    }
    return 0;
}