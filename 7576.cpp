#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct coord{
    int x,y,c;
    friend ostream& operator<<(ostream& os,const coord& cd);
};
ostream& operator<<(ostream& os,const coord& cd){
    os << cd.x << " " << cd.y << " " << cd.c;    
}

int main(){
    int i,j;
    int r,c;
    vector<vector<int>> v;
    queue<coord> q;
    cin >> c >> r;
    v.resize(r,vector<int>(c));
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> v[i][j];
            if(v[i][j]==1){
                q.push({j,i,1});
            }
        }
    }
    while(!q.empty()){
        coord cr = q.front();
        if(cr.x+1<c && v[cr.y][cr.x+1]==0){
            v[cr.y][cr.x+1]=cr.c+1;
            q.push({cr.x+1,cr.y,cr.c+1});
        }
        if(cr.y+1<r && v[cr.y+1][cr.x]==0){
            v[cr.y+1][cr.x]=cr.c+1;
            q.push({cr.x,cr.y+1,cr.c+1});
        }
        if(cr.x>0 && v[cr.y][cr.x-1]==0){
            v[cr.y][cr.x-1]=cr.c+1;
            q.push({cr.x-1,cr.y,cr.c+1});
        }
        if(cr.y>0 && v[cr.y-1][cr.x]==0){
            v[cr.y-1][cr.x]=cr.c+1;
            q.push({cr.x,cr.y-1,cr.c+1});
        }
        q.pop();
    }
    int m=v[0][0];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(v[i][j]>m){
                m = v[i][j];
            }
            if(v[i][j]==0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << m-1 << endl;
    return 0;
}