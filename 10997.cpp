#include <iostream>

using namespace std;

int direction[4][2]={
    {0,-1},
    {1,0},
    {0,1},
    {-1,0}
};

int p[410][410];

int main(){
    ios_base::sync_with_stdio(false);
    int i,j,k;
    int x,y;
    int r,c;
    int n;
    int d=0;
    cin >> n;
    if(n==1){
        cout << "*" << endl;
        return 0;
    }
    x = 4*(n-1)+1;
    y = 4*n-1;
    r=1;c=x;
    while(true){
        p[r][c]=1;
        if(1 <= c+direction[d][1] && c+direction[d][1] <= x &&
           1 <= r+direction[d][0] && r+direction[d][0] <= y &&
           p[r+2*direction[d][0]][c+2*direction[d][1]] == 0){
            r += direction[d][0];
            c += direction[d][1];
        }
        else{
            d = (d+1)%4;
            if(r==2*n+1 && c==2*(n-1)+1)break;
        }
    }
    for(i=1;i<=4*n-1;i++){
        for(k=4*(n-1)+1;k>=1;k--){
            if(p[i][k])break;
        }
        for(j=1;j<=k;j++){
            if(p[i][j])cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}