#include <iostream>

using namespace std;

int mat_a[50][50], mat_b[50][50];

int main()
{
    int n, m;
    int i, j, k, l;
    int swap_cnt = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%1d",&mat_a[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%1d",&mat_b[i][j]);
    for (i = 0; i < n - 2; i++)
        for (j = 0; j < m - 2; j++)
            if (mat_a[i][j] != mat_b[i][j])
                for (++swap_cnt, k = 0; k < 3; k++)
                    for (l = 0; l < 3; l++)
                        mat_a[i + k][j + l] = !mat_a[i + k][j + l];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (mat_a[i][j] != mat_b[i][j])
                goto END;
END:
    if (i == n && j == m)
        cout << swap_cnt << endl;
    else
        cout << -1 << endl;
    return 0;
}