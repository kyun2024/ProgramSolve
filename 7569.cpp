#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

// z,y,x,c 

int mp[101][101][101];

int main(){
    queue<tuple<int,int,int,int>> q;
    int n,m,h;
    int i,j,k;
    cin >> m >> n >> h;
    for(i=1;i<=h;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                cin >> mp[i][j][k];
                if(mp[i][j][k]==1){
                    q.push({i,j,k,0});
                }
            }
        }
    }
    int x,y,z,c=0;
    while(!q.empty()){
        z = get<0>(q.front());
        y = get<1>(q.front());
        x = get<2>(q.front());
        c = get<3>(q.front());

        if(x>1 && mp[z][y][x-1]==0){
            mp[z][y][x-1]=1;
            q.push({z,y,x-1,c+1});
        }
        if(y>1 && mp[z][y-1][x]==0){
            mp[z][y-1][x]=1;
            q.push({z,y-1,x,c+1});
        }
        if(z>1 && mp[z-1][y][x]==0){
            mp[z-1][y][x]=1;
            q.push({z-1,y,x,c+1});
        }
        if(x<m && mp[z][y][x+1]==0){
            mp[z][y][x+1]=1;
            q.push({z,y,x+1,c+1});
        }
        if(y<n && mp[z][y+1][x]==0){
            mp[z][y+1][x]=1;
            q.push({z,y+1,x,c+1});
        }
        if(z<h && mp[z+1][y][x]==0){
            mp[z+1][y][x] = 1;
            q.push({z+1,y,x,c+1});
        }
        q.pop();
    }
    for(i=1;i<=h;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                if(mp[i][j][k]==0){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << c << endl;
    return 0;
}