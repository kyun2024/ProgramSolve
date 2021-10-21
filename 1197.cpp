#include <iostream>
#include <algorithm>

using namespace std;

int parent[10001];

int get_p(int n){
    if(parent[n] == n)return n;
    return parent[n] = get_p(parent[n]);
}

struct xyc{
    int x,y,c;
};

xyc edges[100000];

int main(){
    int v,e;
    int i,j;
    cin >> v >> e;
    for(i=0;i<e;i++){
        cin >> edges[i].x >> edges[i].y >> edges[i].c;
    }
    sort(edges,edges+e,[](xyc i,xyc j){
        return i.c < j.c;
    });
    for(i=1;i<=v;i++)parent[i]=i;

    int res=0;
    int p1,p2;
    for(i=0;i<e;i++){
        p1 = get_p(edges[i].x);
        p2 = get_p(edges[i].y);
        if(p1 != p2){
            res += edges[i].c;
            parent[p2]=p1;
        }
    }
    cout << res << endl;
    return 0;
}