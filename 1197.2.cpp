#include <iostream>
#include <algorithm>

using namespace std;

int h[10001];
struct aaa
{
    int x,y,d;
} e[100001];

int ds_find(int n)
{
    if(h[n]==n)return n;
    return h[n]=ds_find(h[n]);
}

void ds_union(int a, int b)
{
    int ha = ds_find(a), hb = ds_find(b);
    h[max(ha, hb)] = h[min(ha, hb)];
}

int main()
{
    int V, E;
    cin >> V >> E;
    int i;
    for(i=0;i<E;++i)
    {
        auto &[x, y, d] = e[i];
        cin >> x >> y >> d;
    }
    sort(e, e+E, [](const aaa& i, const aaa& j){
        return i.d < j.d;
    });
    for(i=1;i<=V;++i)h[i]=i;
    int res{}, edge_count{};
    for(i=0;i<E || edge_count < V-1;++i)
    {
        auto [x,y,d] = e[i];
        if(ds_find(x) != ds_find(y))
        {
            ds_union(x, y);
            res += d;
            ++edge_count;
        }
    }
    cout << res << endl;

    return 0;
}