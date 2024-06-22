#include <iostream>
#include <algorithm>

using namespace std;

int ufm[1000000];

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
} ds[1000000];

int main()
{
    int V, E;
    int i;
    int max_exp{}, min_exp{};
    cin >> V >> E;
    ++E;
    for (i = 1; i <= E; ++i)
    {
        cin >> ds[i].x >> ds[i].y >> ds[i].z;
        ds[i].z = !ds[i].z;
    }
    for (i = 0; i <= V; i++)
        ufm[i] = i;
    sort(ds + 1, ds + E + 1, [](const c3 &i, const c3 &j)
         { return i.z < j.z; });
    for (i = 1; i <= E; ++i)
    {
        if (f(ds[i].x) != f(ds[i].y))
        {
            u(ds[i].x, ds[i].y);
            min_exp += ds[i].z;
        }
    }

    for (i = 0; i <= V; i++)
        ufm[i] = i;
    sort(ds + 1, ds + E + 1, [](const c3 &i, const c3 &j)
         { return i.z > j.z; });
    for (i = 1; i <= E; ++i)
    {
        if (f(ds[i].x) != f(ds[i].y))
        {
            u(ds[i].x, ds[i].y);
            max_exp += ds[i].z;
        }
    }
    cout << max_exp*max_exp - min_exp*min_exp << '\n';
    return 0;
}