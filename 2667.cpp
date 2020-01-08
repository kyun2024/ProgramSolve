#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define inRange(x,a,b) (a<=x && x<=b)

using namespace std;

struct coord{
    int x,y;
};

int l[][4]={{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    vector<vector<int>> v;
    vector<int> m;
    queue<coord> q;
    int n;
    int i,j;
    int d=1;
    cin >> n;
    v.resize(n,vector<int>(n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%1d",&v[i][j]);
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(v[i][j]==1){
                v[i][j]=++d;
                m.push_back(1);
                q.push({j,i});
                while(!q.empty()){
                    coord cur = q.front();
                    for(int* dd : l){
                        if(inRange(cur.x+dd[0],0,n-1) && inRange(cur.y+dd[1],0,n-1) && v[cur.y+dd[1]][cur.x+dd[0]]==1){
                            v[cur.y+dd[1]][cur.x+dd[0]] = d;
                            q.push({cur.x+dd[0],cur.y+dd[1]});
                            m[d-2]++;
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    sort(m.begin(),m.end());
    cout << d-1 << endl;
    for(auto x : m){
        cout << x << endl;
    }
    return 0;
}