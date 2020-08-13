#include <iostream>
#include <string>

using namespace std;

bool visited[51][51];
int mc[51][51];
int r,c;
string mp[50];

int dfs(int y,int x,int cnt){
    if(y<1 || x<1 || y>r || x>c || mp[y-1][x-1]=='H'){
        return 1;
    }
    if(visited[y][x] && mc[y][x]==0)return -1;
    if(mc[y][x]>0)return mc[y][x];
    //cout << y << " " << x << endl;
    visited[y][x]=true;
    int t=0,res=0,i,r;
    r = mp[y-1][x-1]-'0';
    t = dfs(y,x+r,cnt+1);
    if(t==-1)return -1;
    res = max(res,t);
    t = dfs(y+r,x,cnt+1);
    if(t==-1)return -1;
    res = max(res,t);
    t = dfs(y,x-r,cnt+1);
    if(t==-1)return -1;
    res = max(res,t);
    t = dfs(y-r,x,cnt+1);
    if(t==-1)return -1;
    res = max(res,t);
    //cout << y << " " << x << " " << res << endl;
    mc[y][x]=res+1;
    return mc[y][x];
}   

int main(){
    int i,t;
    cin >> r >> c;
    cin.get();
    for(i=0;i<r;i++){
        getline(cin,mp[i]);
    }
    t = dfs(1,1,0);
    if(t==-1)cout << t << endl;
    else cout << t-1 << endl;
}