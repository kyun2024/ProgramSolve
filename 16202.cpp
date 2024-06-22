#include <iostream>
#include <algorithm>

using namespace std;

int ufm[1001];

int f(int n)
{
    if (n == ufm[n])
        return n;
    return ufm[n] = f(ufm[n]);
}

void u(int n0, int n1)
{
    int p0 = f(n0);
    int p1 = f(n1);
    ufm[p0] = p1;
}

struct c3
{
    int x, y, z;
} ds[10001];

int main()
{
    int V, E, K;
    int i;
    int min_exp{}, rm_idx = -1;
    cin >> V >> E >> K;
    for (i = 1; i <= E; ++i)
    {
        cin >> ds[i].x >> ds[i].y;
        ds[i].z = i;
    }
    for (int k = 0; k < K; k++)
    {
        min_exp = 0;
        rm_idx = -1;
        for (i = 0; i <= V; i++)
            ufm[i] = i;
        sort(ds + 1, ds + E + 1, [](const c3 &i, const c3 &j)
             { return i.z < j.z; });
        for (i = 1; i <= E; ++i)
        {
            if (f(ds[i].x) != f(ds[i].y) && ds[i].z<1000000)
            {
                u(ds[i].x, ds[i].y);
                min_exp += ds[i].z;
                if(rm_idx == -1)rm_idx = i;
            }
        }
        for(i=2;i<=V;i++)if(f(1) != f(i))break;
        if(i<=V){
            cout << 0 << " ";
        }
        else
        {
            cout << min_exp << " ";
        }
        ds[rm_idx].z = 1000000;
    }
    return 0;
}