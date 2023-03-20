#include <iostream>

using namespace std;

long long mem[31];

int main()
{
    constexpr int mod_n = 1000000007;
    int n,m;
    cin >> n >> m;
    long long res = 1;
    int t = 1<<n;
    if(t<m)
    {
        cout << res << endl;
    }
    else
    {
        long long p = 1;
        for(int i = t; i > t-m; i--)
        {
            p = (p * i)%mod_n;
        }
        // cout << "p : " << p << endl;
        mem[0] = t;
        for(int i=1;i<=30;i++)
        {
            mem[i] = (mem[i-1] * mem[i-1])%mod_n;
        }
        long long q = 1;
        int b = 0;
        while(m)
        {
            if(m%2)q = (q * mem[b])%mod_n;
            ++b;
            m /= 2;
        }
        // cout << "q : " << q << endl;
        mem[0] = q;
        for(int i=1;i<=30;i++)
        {
            mem[i] = (mem[i-1] * mem[i-1])%mod_n;
        }
        m = mod_n-2;
        b = 0;
        q = 1;
        while(m)
        {
            if(m%2)q = (q * mem[b])%mod_n;
            ++b;
            m /= 2;
        }
        // cout << "q' : " << mem[0] << endl;
        p = (mem[0] - p + mod_n)%mod_n;
        // cout << "p' : " << p << endl;
        res = (p * q)%mod_n;
        cout << res << endl;
    }
    return 0;
}