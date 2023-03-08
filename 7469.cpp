#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
vector<int> seg_buf[400001];
int merge_list[100001], merge_list_size;
int merge_buf[100001], merge_buf2[100001];

int get_up_to_m_count_rec(int n, int s, int e, int ts, int te, int m)
{
    // cout << "get " << n << " " << s << " " << e << " " << ts << " " << te << " " << m << endl;
    if(e < ts || te < s)return 0;
    else if(ts <= s && e <= te)
    {
        int cnt = upper_bound(seg_buf[n].begin(), seg_buf[n].end(), m)-seg_buf[n].begin();
        // cout << "return " << cnt << endl;
        return cnt;
    }
    else
    {
        int mid = (s + e)/2;
        return get_up_to_m_count_rec(2 * n, s, mid, ts, te, m) + get_up_to_m_count_rec(2 * n + 1, mid + 1, e, ts, te, m);
    }
}

int proc(int n, int ts,int te,int k)
{
    if(ts == te)
    {
        return arr[ts];
    }
    if(te-ts == 1)
    {
        if(k == 1)
        {
            return min(arr[ts], arr[te]);
        }
        else
        {
            return max(arr[ts], arr[te]);
        }
    }

    int s = -1e9, e = 1e9, m;
    while(s<=e)
    {
        m = (s+e)/2;
        int m_count = get_up_to_m_count_rec(1, 1, n, ts, te, m);
        int mm1_count = get_up_to_m_count_rec(1, 1, n, ts, te, m-1);
        // cout << "proc " << m << " " << m_count << " " << mm1_count << endl;
        if(k <= mm1_count)
        {
            e = m - 1;
        }
        else if(k <= m_count)
        {
            break;
        }
        else
        {
            s = m + 1;
        }
    }
    return m;
}

void init_buf(int n,int s,int e)
{
    if(s == e)
    {
        seg_buf[n] = {arr[s]};
    }
    else
    {
        int m = (s+e)/2;
        init_buf(2 * n, s, m);
        init_buf(2 * n + 1, m + 1, e);
        seg_buf[n].resize(seg_buf[2 * n].size() + seg_buf[2 * n + 1].size());
        merge(seg_buf[2 * n].begin(), seg_buf[2 * n].end(), seg_buf[2 * n + 1].begin(), seg_buf[2 * n + 1].end(), seg_buf[n].begin());
    }
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    int i;
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    init_buf(1, 1, n);
    int s, e, k;
    for(i=0;i<q;i++)
    {
        cin >> s >> e >> k;
        cout << proc(n, s, e, k) << '\n';
    }
    return 0;
}