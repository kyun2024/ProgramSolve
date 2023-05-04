#include <iostream>
#include <algorithm>

using namespace std;

constexpr size_t N = 300001;
long long MaxValTree[4 * N];

struct idx_t
{
    long long idx, val, cmp;
} IntIdx[N];

long long query(int node, int s, int e, int rs, int re){
    // cout << "q : " << node << " " << s << " " << e << " " << rs << " " << re << endl;
	if(e < rs || re < s) return 0;
	if(rs<=s && e<=re)
	{
		return MaxValTree[node];
	}
	return max(query(2*node, s, (s+e)/2, rs, re), query(2*node+1, (s+e)/2+1, e, rs, re));
}

void set_val(int node, int s, int e, int idx, long long val)
{
    while(s<e)
    {
        // cout << "s : " << node << " " << s << " " << e << " " << idx << " " << val << endl;
        if(MaxValTree[node] < val) MaxValTree[node] = val;
        if(idx <= (s+e)/2)
        {
            e = (s+e)/2;
            node = 2 * node;
        }
        else
        {
            s = (s+e)/2+1;
            node = 2 * node + 1;
        }
    }
    // cout << "s : " << node << " " << s << " " << e << " " << idx << " " << val << endl;
    MaxValTree[node] = val;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
	int n, i;
	cin >> n;
	for(i=1;i<=n;i++)
    {
        cin >> IntIdx[i].val;
        IntIdx[i].idx = i;
    }
    sort(IntIdx+1, IntIdx+1+n, [](const idx_t& i, const idx_t& j){
        return (i.val < j.val);
    });
    IntIdx[1].cmp = 1;
    for(i=2;i<=n;i++)IntIdx[i].cmp = IntIdx[i-1].cmp+(IntIdx[i].val != IntIdx[i-1].val);
    sort(IntIdx+1, IntIdx+1+n, [](const idx_t& i, const idx_t& j){
        return (i.idx < j.idx);
    });
    int m = max_element(IntIdx+1, IntIdx+1+n, [](const idx_t& i, const idx_t& j){ return i.val < j.val; })->cmp;
    // cout << m << endl;
    for(i=1;i<=n;i++)
    {
        set_val(1, 1, m, IntIdx[i].cmp, query(1, 1, m, 1, IntIdx[i].cmp-1) + IntIdx[i].val);
    }
    cout << MaxValTree[1] << endl;
    return 0;
}