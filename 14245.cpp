#include <iostream>
#include <tuple>
#include <stack>

using namespace std;

int seg_c[2000001];
int a[500001];

void seg_xor(int s,int e,int node,int rs,int re,int n)
{
    stack<tuple<int,int,int>> st;
    st.push({s, e, node});
    while(!st.empty())
    {
        int cs = get<0>(st.top());
        int ce = get<1>(st.top());
        int cnode = get<2>(st.top());
        st.pop();
        // cout << "seg_xor : " << cs << " " << ce << " " << cnode << endl;
        if(rs <= cs && ce <= re)
        {
            seg_c[cnode] ^= n;
            // cout << "xor " << cs << " " << ce << " " << n << endl;
        }
        else
        {
            const int m = (cs+ce)/2;
            if(rs <= m)
            {
                st.push({cs, m, 2*cnode});
            }
            if(m < re)
            {
                st.push({m+1, ce, 2*cnode+1});
            }
        }
    }
}

int get_val(int s,int e,int n)
{
    int m;
    int res = 0;
    int node = 1;
    while(s<e)
    {
        m = (s+e)/2;
        res ^= seg_c[node];
        if(n <= m)
        {
            e = m;
            node = 2 * node;
        }
        else
        {
            s = m + 1;
            node = 2 * node + 1;
        }
    }
    res ^= seg_c[node];
    return res^a[n];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    int i;
    int t, a, b, c;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> ::a[i];
    }
    cin >> m;
    for(i=1;i<=m;i++)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> a >> b >> c;
            seg_xor(1, n, 1, a+1, b+1, c);
        }
        else
        {
            cin >> a;
            cout << get_val(1, n, a+1) << '\n';
        }
    }
    return 0;
}