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


int main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int N, Q;
    int i,j, a, b, f{}, r{1};
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
        cin >> a >> b;
        // cout << "debug depth : " << depth[a] << " " << depth[b] << endl;
        if(depth[a]<depth[b])swap(a,b);
        int d_diff = depth[a]-depth[b]; i = 0;
        while(d_diff)
        {
            if(d_diff & 1)a = ancestor[i][a];
            ++i; d_diff>>=1;
        }
        // cout << "debug " << a << " " << b << endl;
        if(a == b){
            cout << a << '\n';
            continue;
        }
        loop {
            if(ancestor[0][a] == ancestor[0][b]){
                cout << ancestor[0][a] << '\n';
                break;
            }
            else {
                for(i=1;ancestor[i][a] != ancestor[i][b];++i);
                a = ancestor[i-1][a]; b = ancestor[i-1][b];
            }
        }
    }
    return 0;
}