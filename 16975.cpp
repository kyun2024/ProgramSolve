// IMOS 풀이

#include <iostream>

using namespace std;
using ll = long long;

ll seg_m[100001*4];
ll a[100001];

void seg_update(int n, int l, int r, int i, ll diff)
{
    while(l != r)
    {
        seg_m[n] += diff;
        int m = (l+r)/2;
        if(i <= m)
        {
            n = 2 * n;
            r = m;
        }
        else
        {
            n = 2 * n + 1;
            l = m + 1;
        }
    }
    seg_m[n] += diff;
    a[l] += diff;
}

ll seg_query(int n, int l, int r, int ql, int qr)
{
    if(r<ql || qr < l)return 0;
    if(ql <= l && r <= qr)return seg_m[n];
    return seg_query(2*n, l, (l+r)/2, ql, qr)+seg_query(2*n+1, (l+r)/2+1, r, ql, qr);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, Q;
    int i;
    cin >> N;
    for(i=1;i<=N;++i)
    {
        int a;
        cin >> a;
        seg_update(1, 1, N, i, a);
        if(i<N)seg_update(1, 1, N, i+1, -a);
    }
    int qt;
    cin >> Q;
    while(Q--)
    {
        cin >> qt;
        if(qt == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            seg_update(1, 1, N, i, k);
            if(j<N)seg_update(1, 1, N, j+1, -k);
        }
        else
        {
            int x;
            cin >> x;
            cout << seg_query(1, 1, N, 1, x) << '\n';
        }
    }
    return 0;
}