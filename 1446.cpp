#include <iostream>

using namespace std;

int fastway[13][3];
int memo[10001];
bool check[10001];

int main()
{
    int n, d;
    cin >> n >> d;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < 3; j++)
            cin >> fastway[i][j];
    }
    for (j = 1; j <= n; j++)
    {
        if (fastway[j][0] == 0)
        {
            if (!check[fastway[j][1]])
            {
                check[fastway[j][1]] = true;
                memo[fastway[j][1]] = fastway[j][2];
            }
            memo[fastway[j][1]] = min(memo[fastway[j][1]], fastway[j][2]);
        }
    }
    for (i = 1; i <= d; i++)
    {
        if (!check[i])
        {
            memo[i] = memo[i - 1] + 1;
        }
        memo[i] = min(memo[i - 1] + 1, memo[i]);
        for (j = 1; j <= n; j++)
        {
            if (fastway[j][0] == i)
            {
                if (!check[fastway[j][1]])
                {
                    check[fastway[j][1]] = true;
                    memo[fastway[j][1]] = fastway[j][2] + memo[i];
                }
                memo[fastway[j][1]] = min(memo[fastway[j][1]], fastway[j][2] + memo[i]);
            }
        }
    }
    cout << memo[d] << endl;
    return 0;
}