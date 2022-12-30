#include <iostream>

using namespace std;

int a[1000001];
int seg_c[4000001];

void update_diff(int s,int e,int n,int diff)
{
    int m;
    int node = 1;
    while(s<e)
    {
        seg_c[node] += diff;
        m = (s+e)/2;
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
    seg_c[node] += diff;
}

int get_max(int s,int e)
{
    int m;
    int node = 1;
    while(s<e)
    {
        m = (s+e)/2;
        if(seg_c[2 * node + 1])
        {
            s = m + 1;
            node = 2 * node + 1;
        }
        else
        {
            e = m;
            node = 2 * node;
        }
    }
    return s;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n,m;
    int i;
    cin >> n >> m;
    for(i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    const int d = 2*m-1;
    for(i=1;i<d && i<=n ;++i)
    {
        update_diff(1,1000000,a[i],1);
    }
    for(;i<=n;++i)
    {
        update_diff(1,1000000,a[i],1);
        cout << get_max(1,1000000) << ' ';
        update_diff(1,1000000,a[i-d+1],-1);
    }
    cout << endl;
    return 0;
}