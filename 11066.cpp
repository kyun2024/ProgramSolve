#include <iostream>
#include <iomanip>
#include <memory.h>

int dp[500][500];
int val[500][500];
int v[500];

using namespace std;

int main()
{
    int n, t;
    int i, j, k;
    cin >> t;
    while (--t >= 0)
    {   
        memset(dp,0,sizeof(dp));
        memset(val,0,sizeof(val));
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            val[i][i] = v[i];
        }
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                val[i][j] = val[i][j - 1] + v[j];
            }
        }
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < n - i; j++)
            {
                for (k = j; k < i + j; k++)
                {
                    //cout << "(" << j << "," << i+j << ") (" << j << "," << k << ") (" << k+1 << "," << i+j << ")" << endl;
                    if (dp[j][i + j] == 0)
                    {
                        dp[j][i + j] = dp[j][k] + dp[k + 1][i + j] + val[j][k] + val[k + 1][i + j];
                    }
                    else
                    {
                        dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + val[j][k] + val[k + 1][i + j]);
                    }
                }
            }
        }
        cout << dp[0][n - 1] << endl;
        /*
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout << setw(5) << right << dp[i][j];
            }
            cout << endl;
        }
        */
    }
    return 0;
}