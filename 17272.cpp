#include <iostream>

using namespace std;

long long mat[64][100][100];
long long cal_mat[100][100], temp_mat[100][100];

int main()
{
    long long n, t, t2;
    int m;
    cin >> n >> m;
    int i, j, k, l;
    mat[0][0][0] = mat[0][0][m - 1] = 1;
    for (j = 1; j < m; j++)
    {
        mat[0][j][j - 1] = 1;
    }
    for (i = 1; i < 64; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < m; k++)
            {
                t = 0;
                for (l = 0; l < m; l++)
                {
                    t = (t + mat[i - 1][j][l] * mat[i - 1][l][k]) % 1000000007;
                }
                mat[i][j][k] = t;
            }
        }
    }
    t = n - m + 1;
    for (i = 0; i < m; i++)
    {
        cal_mat[i][i] = 1;
    }
    for (i = 0; t > 0; i++)
    {
        if (t % 2)
        {
            for (j = 0; j < m; j++)
            {
                for (k = 0; k < m; k++)
                {
                    t2 = 0;
                    for (l = 0; l < m; l++)
                    {
                        t2 = (t2 + mat[i][j][l] * cal_mat[l][k]) % 1000000007;
                    }
                    temp_mat[j][k] = t2;
                }
            }
            for (j = 0; j < m; j++)
                for (k = 0; k < m; k++)
                    cal_mat[j][k] = temp_mat[j][k];
        }
        t >>= 1;
    }
    long long res{};
    for(i=0;i<m;i++){
        res = (res + cal_mat[0][i])%1000000007;    
    }
    cout << res << endl;
    return 0;
}