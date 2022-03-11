#include <iostream>

using namespace std;

int m[1001][1001];
int d[51][3];
bool check[1001][1001];
int c[1001][1001];

int main()
{
    int i, j, x, y;
    int n;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> d[i][0] >> d[i][1] >> d[i][2];
    }

    for (j = 1; j <= n; j++)
        if (d[j][0] == 1 || d[j][1] == 1)
        {
            m[1][1] += d[j][2];
            c[1][1]++;
        }
    if (m[1][1] > 0)
        check[1][1] = 1;

    for (i = 1; i <= 1000; i++)
    {
        for (x = i, y = 1; x > 0 && y <= 1000; x--, y++)
        {
            if (check[y][x - 1] && m[y][x - 1] > 0 || check[y - 1][x] && m[y - 1][x] > 0)
            {
                check[y][x] = true;
                for (j = 1; j <= n; j++)
                {
                    if (d[j][0] <= y || d[j][1] <= x)
                    {
                        m[y][x] += d[j][2];
                        c[y][x]++;
                    }
                }
                m[y][x] = m[y][x] - y - x + 2;
            }
        }
    }
    for (i = 2; i <= 1000; i++)
    {
        for (x = 1000, y = i; x > 0 && y <= 1000; x--, y++)
        {
            if (check[y][x - 1] && m[y][x - 1] > 0 || check[y - 1][x] && m[y - 1][x] > 0)
            {
                check[y][x] = true;
                for (j = 1; j <= n; j++)
                {
                    if (d[j][0] <= y || d[j][1] <= x)
                    {
                        m[y][x] += d[j][2];
                        c[y][x]++;
                    }
                }
                m[y][x] = m[y][x] - y - x + 2;
            }
        }
    }
    int res=0;
    for(i = 1; i<= 1000;i++){
        for(j = 1;j<=1000;j++){
            res = max(res,c[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
