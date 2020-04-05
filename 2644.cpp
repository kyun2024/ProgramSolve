#include <iostream>
#include <queue>

using namespace std;

int am[101][101];
int ch[101];

struct coord{
    int x,c;
};

int main(){
    int n,m;
    int src,dst;
    int a,b;
    int i,j;
    queue<coord> q;
    cin >> n;
    cin >> src >> dst;
    cin >> m;
    for(i=0;i<m;i++){
        cin >> a >> b;
        am[a][b]=am[b][a]=1;
    }
    q.push({src,0});
    ch[src]=1;
    while(!q.empty()){
        coord cur = q.front();
        for(i=1;i<=n;i++){
            if(ch[i]==0 && am[cur.x][i]){
                q.push({i,cur.c+1});
                ch[i]=cur.c+1;
            }
        }
        q.pop();
    }
    cout << ((ch[dst]==0)?-1:ch[dst]) << endl;
    return 0;
}