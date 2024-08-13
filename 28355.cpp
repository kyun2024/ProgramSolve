#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll a[500001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ll n, i, s = 0;
    ll res = 0;
    cin >> n;
    for(i=1;i<=n;++i)
    {
        cin >> a[i];
        s += a[i];
    }
    ll x = (s - n/2)/(n*n);
    if(x<4)
    {
        ll t = 0;
        for(i=1;i<=5*n;++i)
        {
            t = max(t + a[(i-1)%n+1] - i, a[(i-1)%n+1] - i);
            res = max(res, t);
        }
    }
    else
    {
        ll pre = 0, suf = 0, t = 0;
        for(i=n;i>=1;--i)
        {
            t += a[i] - i;
            pre = max(pre, t);
        }
        t = 0;
        for(i=n*(x-2)+1;i<=n*(x+2);++i)
        {
            t += a[(i-1)%n+1] - i;
            suf = max(suf, t);
        }
        res = pre + s*(x-3) - n*(x-2)*(n*(x-2)+1)/2 + n*(n+1)/2 + suf;
    }
    cout << res << endl;
    return 0;
}