#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int disjoint_map[4000001];

int set_union(int node)
{
    // cout << "Debug# " << node << '\n';
    if(node == disjoint_map[node])
    {
        ++disjoint_map[node];
        return node;
    }
    return disjoint_map[node] = set_union(disjoint_map[node]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int i,j,num;
    cin >> n >> m >> k;
    for(i=0;i<m;++i)
    {
        cin >> num;
        disjoint_map[num]=num;
    }
    for(i=1;i<=n;++i)
    {
        if(disjoint_map[i]==0)disjoint_map[i]=i+1;
    }
    for(i=0;i<k;++i)
    {
        cin >> num;
        cout << set_union(num+1) << '\n';
    }
    return 0;
}