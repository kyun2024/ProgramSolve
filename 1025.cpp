#include <iostream>

using namespace std;

int a[9][9];

static unsigned isqrt(unsigned long val)
{
    unsigned long temp, g = 0, b = 0x8000, bshft = 15;
    do
    {
        if (val >= (temp = (((g << 1) + b) << bshft--)))
        {
            g += b;
            val -= temp;
        }
    } while (b >>= 1);
    return g;
}

int main()
{
    int n, m;
    int i, j, k, l, x, y, t, tem;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    int res = -1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = -9; k <= 9; k++)
            {
                for (l = -9; l <= 9; l++)
                {
                    if (k == 0 && l == 0)
                        continue;
                    t = 0;
                    for (y = i, x = j, tem=0; 0 <= y && y < n && 0 <= x && x < m; y += k, x += l, tem++)
                    {
                        t = 10 * t + a[y][x];
                        int sq = isqrt(t);
                        if (sq * sq == t)
                        {
                            res = max(res, t);
                            //printf("(%d, %d)+%d*(%d, %d) = %d\n", i, j, tem, k, l, t);
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}