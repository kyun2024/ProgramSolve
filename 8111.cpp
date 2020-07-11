#include <iostream>
#include <memory.h>

using namespace std;

int d[101][20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_case, n, r = 1, k;
    int i, j;
    cin >> test_case;
    while (test_case--)
    {
        //initalize
        r = 1;
        memset(d[0], 0, sizeof(int) * 20001);
        cin >> n;
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        for (i = 1; i <= 100; i++)
        {
            d[i][r] = 1;
            d[i][n] = r;
            for (j = (r + 1) % n; j != r; j = (j + 1) % n)
            {
                d[i][j] = d[i - 1][j] | d[i - 1][(j - r + n) % n];
            }
            if (d[i][0])
            {
                break;
            }
            r = (10 * r) % n;
        }
        if (i > 100)
        {
            cout << "NAY" << endl;
        }
        else
        {
            r = 0;
            for (k = i; k >= 1; k--)
            {
                if (d[k - 1][r] == 0)
                {
                    cout << 1;
                    r = (r + n - d[k][n]) % n;
                }
                else
                {
                    cout << 0;
                }
                if (r == 0)
                {
                    for (; k > 1; k--)
                    {
                        cout << 0;
                    }
                    break;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}