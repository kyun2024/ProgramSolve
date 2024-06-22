#include <iostream>
#include <algorithm>

using namespace std;

struct daw
{
    int d, a, w;
} sl[1024*1024];

int adj_m[1025][1025];
int head[1025];

int f(int n)
{
    if(n==head[n])return n;
    return head[n]=f(head[n]);
}

void u(int a,int b)
{
    head[f(a)]=head[f(b)];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    int i,j;
    int w;
    int c = 0;

    cin >> N;
    for(i=1;i<=N;++i)
    {
        for(j=i+1;j<=N;++j)
        {
            cin >> w;
            sl[c++] = {i,j,w};
        }
    }

    sort(sl, sl+N*(N-1)/2, [](const daw& i, const daw& j)
    {
        return i.w < j.w;
    });

    for(i=1;i<=N;i++)head[i]=i;

    for(i=0;i<N*(N-1)/2;i++)
    {
        if(f(sl[i].d) != f(sl[i].a))
        {
            u(sl[i].d, sl[i].a);
            adj_m[sl[i].d][sl[i].a]=1;
            adj_m[sl[i].a][sl[i].d]=1;
            ++adj_m[sl[i].d][0];
            ++adj_m[sl[i].a][0];
        }
    }
    for(i=1;i<=N;++i)
    {
        cout << adj_m[i][0] << " ";
        for(j=1;j<=N;++j)
        {
            if(adj_m[i][j])cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}