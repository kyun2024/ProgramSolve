#include <iostream>

using namespace std;

int v[3000][3000];
int res[3];

void rec(int r,int c,int s){
    int i,j;
    int lr[3]={0,0,0};
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            lr[v[r+i][c+j]+1]++;
        }
    }
    if(lr[1]==0 && lr[2]==0){
        res[0]++;
        return;
    }
    if(lr[0]==0 && lr[2]==0){
        res[1]++;
        return;
    }
    if(lr[0]==0 && lr[1]==0){
        res[2]++;
        return;
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            rec(r+i*s/3,c+j*s/3,s/3);
        }
    }
}

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    rec(0,0,n);
    for(i=0;i<3;i++){
        cout << res[i] << endl;
    }
    return 0;
}