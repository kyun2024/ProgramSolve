#include <iostream>
#include <string>

using namespace std;

bool ofc[26][26];
bool check[26][26];
long long m[26][26];
long long N, K;

long long f(int open_c, int close_c)
{
    
    if(check[open_c][close_c])return m[open_c][close_c];
    check[open_c][close_c]=1;
    if(open_c == 0)return m[open_c][close_c]=1;
    bool cond = (open_c<close_c);
    long long open_r, close_r = 0;
    if(cond)close_r = f(open_c, close_c-1);
    open_r = f(open_c-1, close_c);
    return m[open_c][close_c] = open_r + close_r;
}

string q(int open_c, int close_c, long long k)
{
    // cout << open_c << " " << close_c << " " << k << endl;
    if(m[open_c][close_c] < k)return "-1";
    if(open_c == 0)
    {
        if(k == -1)
        {
            string res;
            for(int i=0;i<close_c;res+=")", ++i);
            return res;
        }
        else return "-1";
    }
    string r0 = q(open_c-1, close_c, k);
    if(r0 != "-1")r0 = "("+r0;
    else if(open_c<close_c)
    {
        r0 = q(open_c, close_c-1, k-m[open_c-1][close_c]);
        if(r0 != "-1")r0 = ")"+r0;
    }
    return r0;
}

int main()
{
    cin >> N >> K;
    f(N/2, N/2);
    // for(int i=0;i<=N/2;++i)
    // {
    //     for(int j=0;j<=N/2;++j)
    //     {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << q(N/2, N/2, K-1) << endl;
    return 0;
}