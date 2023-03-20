#include <iostream>

using namespace std;

int mc[1000001];
int sn[1000];

int calc(int n)
{
    if(mc[n])return mc[n];
    int res = 987654321;
    for(int i=0;sn[i]<n;i++)
    {
        res = min(res, calc(n-sn[i]) + 1);
    }
    return mc[n] = res;
}

int main()
{
    int i, j, c=0;
    for(i=0;c<=1000000;i++)
    {
        c = c + 4*i+1;
        mc[c] = 1;
        sn[i] = c;
    }
    // for(i=1;i<=1000000;i++)
    // {
    //     if(mc[i])continue;
    //     for(j=0;sn[j]<i;j++)
    //     {
    //         if(mc[i] == 0)mc[i] = mc[i-sn[j]] + 1;
    //         else mc[i] = min(mc[i], mc[i-sn[j]] + 1);
    //     }
    // }

    cin >> j;
    cout << calc(j) << endl;
    return 0;
}