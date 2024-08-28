#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> box_list[19][19];
ll tree[262144];
ll inorder[262144];

int idx=1;
void fill_inorder(int N, int node, int level)
{
    if(level<1)return;
    fill_inorder(N, 2*node, level-1);
    inorder[idx++] = tree[node];
    fill_inorder(N, 2*node+1, level-1);
}

ll get_max_sub_sum(vector<ll>& v)
{
    ll cal = v[0], res = v[0];
    for(int i=1;i<v.size();++i)
    {
        cal = max(cal+v[i], v[i]);
        res = max(res, cal);
    }
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, b, i, j, k, a;
    cin >> N;
    b = __builtin_popcount(N);
    for(i=1;i<=N;++i)cin >> tree[i];
    fill_inorder(N, 1, b);
    for(i=1;i<=N;++i)
    {
        int rz = __builtin_ctz(i);
        for(j=0;j<b;++j)
        {
            for(k=j;k<b;++k)
            {
                if(j <= rz && rz <= k)
                {
                    box_list[j][k].push_back(inorder[i]);
                }
            }
        }
    }
    ll res = -1e18;
    for(j=0;j<b;++j)
    {
        for(k=j;k<b;++k)
        {
            ll cur = get_max_sub_sum(box_list[j][k]);
            res = max(res, get_max_sub_sum(box_list[j][k]));
        }
    }
    cout << res << endl;

    return 0;
}