#include <iostream>

using namespace std;

int parent[200001];
int u_parent[200001];

struct abc{
    int qt,a,b,res;
};

abc queries[400001];

int gp(int n){
    if(n==u_parent[n])return n;
    return u_parent[n] = gp(u_parent[n]);
}

int main(){
    cin.tie(0)->sync_with_stdio(false);

    parent[1]=1;
    int n,q;
    int i;
    cin >> n >> q;
    for(i=2;i<=n;i++){
        cin >> parent[i];
    }
    for(i=1;i<n+q;i++){
        cin >> queries[i].qt >> queries[i].a;
        if(queries[i].qt==1) cin >> queries[i].b;
    }
    for(i=1;i<=n;i++)u_parent[i]=i;
    for(i=n+q-1;i>=1;i--){
        if(queries[i].qt==0){
            u_parent[gp(queries[i].a)]=gp(parent[queries[i].a]);
        }
        else{
            queries[i].res = gp(queries[i].a)==gp(queries[i].b);
        }
    }
    for(i=1;i<n+q;i++){
        if(queries[i].qt==1){
            cout << (queries[i].res?"YES":"NO") << '\n';
        }
    }
}