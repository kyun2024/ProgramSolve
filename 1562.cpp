#include <iostream>
#include <bitset>

using namespace std;

int dp[101][10][1024];

int main()
{
    int i, j, k, l, n, s = 0;
    for (j = 1; j <= 9; j++)
    {
        dp[1][j][(1 << j)] = 1;
    }
    for (i = 2; i <= 100; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            for (l = j - 1; l <= j + 1; l += 2)
            {
                if (0 <= l && l <= 9)
                {
                    for (k = 0; k < 1024; k++)
                    {
                        if(k&(1<<l))dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][l][k]) % 1'000'000'000;
                        // cout << i << " " << j << " " << l << " " << bitset<10>(k) << " " << bitset<10>(k | (1 << j)) << endl;
                        // cin.get();
                    }
                }
            }
        }
    }
    cin >> n;
    for (j = 0; j <= 9; j++)
    {
        s = (s+dp[n][j][1023])%1'000'000'000;
    }
    cout << s << endl;
}