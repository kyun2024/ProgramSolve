#include <iostream>

using namespace std;

long long b[100001][4];

int a[100001];

int main()
{
    unsigned long long res=0;
    int n;
    int i, j, k;
    bool cb;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (k = 0; k < 30; k++)
    {
        b[0][3]=1;
        for (i = 1; i <= n; i++)
        {
            cb = (a[i] >> k) % 2;
            if (cb)
            { // 1
                b[i][0] = b[i-1][2]+1;
                b[i][1] = b[i-1][0]+b[i-1][1];
                b[i][2] = b[i-1][0];
                b[i][3] = b[i-1][2]+b[i-1][3];
            }
            else{
                b[i][0] = b[i-1][0];
                b[i][1] = b[i-1][0]+b[i-1][1];
                b[i][2] = b[i-1][2]+1;
                b[i][3] = b[i-1][2]+b[i-1][3];
            }
        }
        res += (b[n][0]+b[n][1])*(1<<k);
    }
    cout << res << endl;
    return 0;
}