#include <iostream>

int memo[10001];

using namespace std;

int main()
{
    int n, m;
    int i;
    cin >> n >> m;
    memo[0] = 1;
    for(i=1;i<m;++i)
    {
        memo[i] = 1;
    }
    for(i=m;i<=n;++i)
    {
        memo[i] = (memo[i-1]+memo[i-m])%1000000007;
    }
    cout << memo[n] << endl;

    return 0;
}