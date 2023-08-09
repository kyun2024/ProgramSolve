#include <iostream>
#include <algorithm>

using namespace std;

int ufm[200001];


int f(int n)
{
    if(n == ufm[n])return n;
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
} ds[200001];

int main()
{
    int M, N;
    int i;
    int tot_exp, sum_exp;
    while (1)
    {
        tot_exp = 0; sum_exp = 0;
        cin >> M >> N;
        if(M==0 && N==0)break;
        for (i = 1; i <= N; ++i)
        {
            cin >> ds[i].x >> ds[i].y >> ds[i].z;
            tot_exp += ds[i].z;
        }
        for (i = 0; i <= M; i++)
            ufm[i] = i;
        sort(ds+1,ds+N+1,[](const c3& i,const c3& j){
            return i.z < j.z;
        });
        for(i=1;i<=N;++i)
        {
            if(f(ds[i].x) != f(ds[i].y))
            {
                u(ds[i].x, ds[i].y);
                sum_exp += ds[i].z;
            }
        }
        cout << tot_exp-sum_exp << '\n';
    }
    return 0;
}