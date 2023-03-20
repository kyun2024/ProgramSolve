#include <iostream>

using namespace std;

bool chk[80][16001];

int main()
{
    int n,k,x;
    cin >> n >> k >> x;
    int a, b;
    int i, j, ini;
    for(ini = 0; ini < n; ++ini)
    {
        cin >> a >> b;
        for(i=ini-1;i>=0;--i)
        {
            for(j=0;j<=(i+1)*x;++j)
            {
                if(chk[i][j])chk[i+1][j + a] = 1;
            }
        }
        chk[0][a] = 1;
    }
    int res = 0;
    for(i=0;i<=k*x;i++)
    {
        if(chk[k-1][i])res = max(res, i*(k*x-i));
    }
    cout << res << endl;
    return 0;
}