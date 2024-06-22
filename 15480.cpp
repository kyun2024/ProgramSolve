#include <bits/stdc++.h>
#define loop while(1)

using namespace std;

struct ps
{
    int n, d;
};

vector<int> adj_list[100001];
ps qm[100001];
int ancestor[17][100001];
bitset<100001> visited;
int depth[100001];

int LCA(int a,int b)
{
    int i=0;
    if(depth[a]<depth[b])swap(a,b);
    int d_diff = depth[a]-depth[b];
    while(d_diff)
    {
        if(d_diff & 1)a = ancestor[i][a];
        ++i; d_diff>>=1;
    }
    // cout << "debug " << a << " " << b << endl;
    if(a == b){
        return a;
    }
    loop {
        if(ancestor[0][a] == ancestor[0][b]){
            return ancestor[0][a];
        }
        else {
            for(i=1;ancestor[i][a] != ancestor[i][b];++i);
            a = ancestor[i-1][a]; b = ancestor[i-1][b];
        }
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int N, Q;
    int i, j, a, b, f{}, r{1}, t;
    cin >> N;
    for(i=1;i<N;++i)
    {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    visited[1]=1;
    qm[0] = {1, 1};
    depth[1] = 1;
    while(f<r){
        ps fr = qm[f++];
        for(auto nn : adj_list[fr.n]){
            if(!visited[nn])
            {
                visited[nn]=1;
                depth[nn]=fr.d+1;
                ancestor[0][nn]=fr.n;
                qm[r++]={nn, fr.d +1};
            }
        }
    }
    for(j=1;j<17;++j)for(i=1;i<=N;++i)ancestor[j][i]=ancestor[j-1][ancestor[j-1][i]];
    
    cin >> Q;
    while(Q--)
    {
        cin >> t >> a >> b;
        int lca_at = LCA(a, t);
        int lca_bt = LCA(b, t);
        if(lca_at == t && lca_bt == t)cout << LCA(a, b) << '\n';
        else if((lca_at == t && lca_bt != t)&&(lca_at != t && lca_bt == t))cout  << t << '\n';
        else if((lca_at == lca_bt) && lca_at != a && lca_at != t && lca_bt != b&& lca_bt != t) cout << LCA(a, b) << '\n';
        else cout << (LCA(lca_at, lca_bt)==lca_at?lca_bt:lca_at) << '\n';
    }
    return 0;
}