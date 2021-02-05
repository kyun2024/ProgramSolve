#include <iostream>

using namespace std;

int m[1024][1024];

int dfs(int x,int y){
    if(x==y){
        return x;
    }
    if(x>y){
        return m[x][y]=dfs(y,x);
    }
    return m[x][y]=dfs(x,y/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i,j;
    for(i=1;i<=1023;i++){
        m[i][i]=i;
    }
    for(i=1;i<=1023;i++){
        for(j=1;j<=1023;j++){
            dfs(i,j);
        }
    }
    int T;
    cin >> T;
    while(T--){
        cin >> i >> j;
        cout << m[i][j]*10 << '\n';
    }
    return 0;
}