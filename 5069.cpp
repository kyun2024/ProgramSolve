#include <iostream>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

int n,gc;
map<tuple<long long,long long,int>,int> m;
map<tuple<long long,long long,int>,bool> visited;
long long dx[]={200000,100000,-100000,-200000,-100000,100000};
long long dy[]={0,173205,173205,0,-173205,-173205};

int dfs(long long mx, long long my, int c){
    //cout << setw(9) << mx << " " << setw(9) << my << " " << c << endl;
    if(visited[{mx,my,c}])return m[{mx,my,c}];
    visited[{mx,my,c}]=1;
    if(c==n){
        if(mx==0 && my==0)
        {
            return m[{mx,my,c}] = 1;
        }
        else return m[{mx,my,c}] = 0;
    }
    for(int i=0;i<6;i++){
        int r = dfs(mx + dx[i], my + dy[i], c+1);
        m[{mx,my,c}] += r;
    }
    return m[{mx,my,c}];
}

int main(){
    int T;
    cin >> T;
    while(T--){
        visited.clear();
        m.clear();
        cin >> n;
        dfs(0,0,0);
        cout << m[{0,0,0}] << endl;
    }
    return 0;
}