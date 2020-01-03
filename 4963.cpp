#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dm[]={-1,0,1};

class coord{
public:
    int x,y;
};

void bfs(int number,int sx,int sy,vector<vector<int>>& v){
    int i,j;
    queue<coord> q;
    v[sy][sx]=number;
    q.push({sx,sy});
    while(!q.empty()){
        coord c=q.front();
        //cout << c.x << " " << c.y << endl;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(0 <= c.y + dm[i] && c.y + dm[i] < v.size() && 0 <= c.x + dm[j] && c.x + dm[j] < v[0].size() && v[c.y+dm[i]][c.x+dm[j]]==1){
                    v[c.y+dm[i]][c.x+dm[j]]=number;
                    q.push({c.x+dm[j],c.y+dm[i]});
                }
            }
        }
        q.pop();
    }
}

int count_islands(vector<vector<int>>& map){
    int count = 1;
    int i,j;
    for(i=0;i<map.size();i++){
        for(j=0;j<map[0].size();j++){
            //cout << i << " " << j << " " << map[i][j] << endl;
            if(map[i][j]==1){
                //cout << "BFS START" << endl;
                bfs(++count,j,i,map);
            }
        }
    }
    return count-1;
}

int main(){
    int w,h;
    int i,j;
    vector<vector<int>> map;
    while(true){
        cin >> w >> h;
        if(w==0 && h==0)break;
        map.resize(h,vector<int>(w,0));
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                cin >> map[i][j];
            }
        }
        //process
        cout << count_islands(map) << endl;
        map.clear();
    }
    return 0;
}