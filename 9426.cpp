#include <iostream>
#include <stack>

using namespace std;

int c[65537*4];
int temp[250001];

void modify_diff(int s,int e,int n,int diff)
{
    stack<int> s_n;
    int m;
    int node = 1;
    s_n.push(1);
    while(s<e)
    {
        m = (s+e)/2;
        if(n <= m)
        {
            e = m;
            node = 2*node;
        }
        else
        {
            s = m + 1;
            node = 2 * node + 1;
        }
        s_n.push(node);
    }
    while(!s_n.empty())
    {
        c[s_n.top()] += diff;
        s_n.pop();
    }
}

int get_middle(int s,int e,int n)
{
    int m;
    int node = 1;
    while(s<e)
    {
        m = (s+e)/2;
        if(c[2*node]>=n)
        {
            e = m;
            node = 2 * node;
        }
        else
        {
            s = m + 1;
            n -= c[2*node];
            node = 2 * node + 1;
        }
    }
    return s;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    int i;
    unsigned long long res=0;
    cin >> n >> k;
    const int m_idx = (k+1)/2;
    for(i=1;i<=n;i++)
    {
        cin >> temp[i];
    }
    for(i=1;i<k;i++)
    {
        modify_diff(0, 65536, temp[i], 1);
    }
    for(i=k;i<=n;i++)
    {
        modify_diff(0, 65536, temp[i],1);
        res += get_middle(0, 65536, m_idx);
        modify_diff(0, 65536, temp[i-k+1],-1);
    }
    cout << res << endl;
    return 0;
}