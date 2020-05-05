#include <iostream>

using namespace std;

char a2[6561][6561];

void qf(int r,int c,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a2[r+i][c+j]=' ';
        }
    }
}
void q(int r,int c,int n){
    int i,j;
    if(n==1){
        a2[r][c]='*';
        return;
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==1 && j==1){
                qf(r+i*n/3,c+j*n/3,n/3);
            }
            else q(r+i*n/3,c+j*n/3,n/3);
        }
    }
}

int main(){
    int i,j,n;
    cin >> n;
    q(0,0,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << a2[i][j];
        }
        cout << endl;
    }
    return 0;
}