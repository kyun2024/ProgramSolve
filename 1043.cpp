#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int ufm[51];
bitset<51> tr;
int pm[51][51];

int uf_find(int i)
{
    if(i==ufm[i])return i;
    return ufm[i] = uf_find(ufm[i]);
}

void set_m(int i, int v)
{
    if(i==ufm[i])
    {
        ufm[i]=v;
        return;
    }
    set_m(ufm[i], v);
    ufm[i] = v;
}

void uf_union(int a, int b)
{
    int ma = uf_find(a);
    int mb = uf_find(b);
    set_m(a, min(ma, mb));
    set_m(b, min(ma, mb));
}

int main()
{
    int i,j,k,t,l;
    int n,m;
    cin >> n >> m;
    for(i=1;i<=n;i++)ufm[i]=i;
    cin >> i;
    for(j=0;j<i;j++)
    {
        cin >> t;
        tr[t]=1;
    }
    for(i=0;i<m;i++)
    {
        cin >> k;
        for(j=0;j<k;j++)
        {
            cin >> pm[i][j];
        }
        for(j=1;j<k;j++)
        {
            uf_union(pm[i][0], pm[i][j]);
        }
    }
    for(i=1;i<=50;i++)if(tr[i])tr[uf_find(i)]=1;
    cout << count_if((int(*)[51])&pm[0], (int(*)[51])&pm[m], [](int (&a)[51]){
        int i=0;
        for(i=0;a[i] != 0; i++)
        {
            if(tr[uf_find(a[i])])break;
        }
        if(a[i]==0)return true;
        return false;
    }) << endl;
    return 0;
}