#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll n, m, a, i, s{};
    cin >> n >> m;
    for(i = 0; i < n; ++i)
    {
        cin >> a;
        s += a;
    }
    ll c = max(m-n-s, 0LL);
    ll d = c/(n+1);
    ll res = (d * (d+1) * (2*d+1) / 6) * (n+1 - c%(n+1)) + ((d+1) * (d+2) * (2*d+3) / 6) * (c%(n+1));
    cout << res << endl;
    return 0;
}