#include <iostream>
#include <map>

using namespace std;

long long memo[1000001];
bool check[1000001];
map<long long, int> memo_map;

constexpr long long mod_n = 1000000007;

long long f(long long n)
{
    long long res = 0;
    if(memo_map.find(n) != memo_map.end())return memo_map[n];    
    // 1..n
    if(n%2)
    {
        // n is odd
        res = (res + 2*((n-3)/2+1))%mod_n;
        res = (res + f((n+1)/2))%mod_n;
        res = (res + ((n-3)/2+1))%mod_n;
        res = (res + f(n/2))%mod_n;
    }
    else
    {
        // n is even
        res = (res + 2*((n-4)/2+1))%mod_n;
        res = (res + f(n/2))%mod_n;
        res = (res + ((n-2)/2+1))%mod_n;
        res = (res + f(n/2))%mod_n;
    }
    memo_map[n] = res;
    return res;
}

// long long f(long long s,long long e,int c)
// {
//     cout << "f : " << s << " " << e << " " << c << endl;
//     if(e==1)return 0;
//     if(s==1)s=2;
//     if(s == e)
//     {
//         long long cnt = 0;
//         while(s > 1)
//         {
//             if(s%2)s+=1;
//             else s/=2;
//             cnt++;
//         }
//         return cnt%1000000007;
//     }
//     long long odd_s, odd_e, even_s, even_e;
//     if(s%2)
//     {
//         odd_s = s;
//         even_s = s+1;
//     }
//     else
//     {
//         even_s = s;
//         odd_s = s+1;
//     }
//     if(e%2)
//     {
//         odd_e = e;
//         even_e = e-1;
//     }
//     else
//     {
//         odd_e = e-1;
//         even_e = e;
//     }
//     long long sum_v = 0;
//     sum_v += 2*((odd_e-odd_s)/2+1)+f((odd_s+1)/2,(odd_e+1)/2, c+1);
//     cout << "f l " << s << " " << e << " " << c << endl;
//     sum_v += ((even_e-even_s)/2+1)+f(even_s/2, even_e/2, c+1);
//     return (sum_v)%1000000007;
// }

int main()
{
    long long a, b;
    cin >> a >> b;
    memo_map[0] = 0; memo_map[1] = 0; memo_map[2] = 1; memo_map[3] = 4;
    // check[0] = check[1] = check[2] = check[3] = check[4] = check[5] = 1;
    // memo[2] = 1; memo[3] = 4; memo[4] = 6; memo[5] = 11;
    cout << (f(b)-f(a-1)+mod_n)%mod_n << endl;
    // cout << memo_map.size() << endl;
    return 0;
}