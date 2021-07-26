#include <iostream>

using namespace std;

constexpr long long mod_n = 1000000007;

long long fct[4000001];
long long inv_fct[4000001];
long long m[22];

void proc()
{
    long long i, j, t;
    long long res;
    inv_fct[0] = fct[0] = 1;
    for (i = 1; i <= 4000000; i++)
    {
        fct[i] = (i * fct[i - 1]) % mod_n;
    }
    m[0] = fct[4000000];
    for (j = 1; j < 32; j++)
    {
        m[j] = (m[j - 1] * m[j - 1]) % mod_n;
    }
    res = 1;
    for (j = 0, t = mod_n - 2; t > 0; t >>= 1, j++)
    {
        if (t % 2)
        {
            res = (res * m[j]) % mod_n;
        }
    }
    inv_fct[4000000] = res;
    for (i = 3999999; i >= 1; i--)
    {
        inv_fct[i] = (inv_fct[i + 1] * (i + 1)) % mod_n;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    proc();
    int T;
    cin >> T;
    int n, k;
    long long res;
    while (T--)
    {
        cin >> n >> k;
        if (n == k || k == 0)
            cout << 1 << endl;
        else
        {
            res = (fct[n] * inv_fct[k]) % mod_n;
            res = (res * inv_fct[n - k]) % mod_n;
            cout << res << '\n';
        }
    }
    return 0;
}