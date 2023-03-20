#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> mst_mem[100001*4];
int in_li[100001];

void update(int node, int s, int e)
{
    if(s==e){ mst_mem[node] = {in_li[s]}; return; }
    int m = (s+e)/2;
    update(2 * node, s, m); update(2 * node + 1, m+1, e);
    mst_mem[node].reserve(mst_mem[2 * node].size() + mst_mem[2 * node + 1].size());
    mst_mem[node].insert(mst_mem[node].end(), mst_mem[2 * node].begin(), mst_mem[2 * node].end());
    mst_mem[node].insert(mst_mem[node].end(), mst_mem[2 * node + 1].begin(), mst_mem[2 * node + 1].end());
    sort(mst_mem[node].begin(), mst_mem[node].end());
}

int query_function(int node, int s, int e, int l, int r, int k)
{
    if(e < l || r < s)return 0;
    if(l <= s && e <= r)return mst_mem[node].end()-upper_bound(mst_mem[node].begin(),mst_mem[node].end(),k);
    int m = (s+e)/2;
    return query_function(2 * node, s, m, l, r, k) + query_function(2 * node + 1, m+1, e, l, r, k);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, i, m, q, l, r;
    cin >> n;
    for(i=1;i<=n;i++) cin >> in_li[i];
    update(1, 1, n);
    cin >> m;
    for(i=0;i<m;i++)
    {
        cin >> l >> r >> q;
        cout << query_function(1, 1, n, l, r, q) << '\n';
    }
    return 0;
}