#include <iostream>
#include <memory.h>

using namespace std;

int c;
int mp[52][52];

void dfs(int y,int x){
    if(mp[y][x]!=1)return;
    mp[y][x]=c;
    dfs(y+1,x);
    dfs(y-1,x);
    dfs(y,x+1);
    dfs(y,x-1);
}

int main(){
    int t;
    int m,n,k,x,y;
    int i,j;
    cin >> t;
    while(--t>=0){
        memset(mp,0,sizeof(mp));
        c=1;
        cin >> m >> n >> k;
        for(i=0;i<k;i++){
            cin >> x >> y;
            mp[y+1][x+1]=1;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(mp[i][j]==1){
                    //cout << i << " " << j << " " << c << endl;
                    c+=1;
                    dfs(i,j);
                }
            }
        }
        cout << c-1 << endl;
    }
    return 0;
}