#include <iostream>

using namespace std;

int c[400000];
int pmt[100001];
int isa[100001];

void add(int s,int e,int n)
{
    int m;
    int node = 1;
    while(s<e)
    {
        c[node]++;
        m = (s+e)/2;
        if(n<=m)
        {
            e = m;
            node = 2*node;
        }
        else
        {
            s = m+1;
            node = 2*node + 1;
        }
    }
    c[node]++;
}

void set_pmt(int s,int e,int n,int pn)
{
    int m;
    int node = 1;
    // cout << "set_pmt : " << pn << endl;
    while(s<e)
    {
        m = (s+e)/2;
        // cout << s << " " << e << " " << n << " -> " << m << " " << c[2*node] << " " << c[2*node+1] << endl;
        c[node]--;
        if(n > c[2*node])
        {
            n -= c[2*node];
            s = m + 1;
            node = 2 * node + 1;
        }
        else
        {
            e = m;
            node = 2 * node;
        }
    }
    // cout << s << " " << e << endl;
    c[node]--;
    pmt[s] = pn;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, i;
    cin >> n;
    for(i=1;i<=n;i++)add(1, n, i);
    for(i=1;i<=n;i++)
    {
        cin >> isa[i];
    }
    for(i=1;i<=n;i++)
    {
        set_pmt(1,n,isa[i]+1,i);
    }
    for(i=1;i<=n;i++)
    {
        cout << pmt[i] << '\n';
    }
    return 0;
}