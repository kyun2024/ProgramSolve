#include <iostream>

using namespace std;

int a1[51];
int m[51][500001];
bool visited[51][500001];

int main()
{
    int n;
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a1[i];
    }
    visited[1][a1[1]] = 1;
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j <= 500000; j++)
        {
            if (visited[i - 1][j])
            {
                visited[i][j + a1[i]] = 1;
                m[i][j + a1[i]] = max(m[i][j + a1[i]], m[i - 1][j]);
                if (a1[i] > j)
                {
                    visited[i][a1[i] - j] = 1;
                    m[i][a1[i] - j] = max(m[i][a1[i] - j], m[i - 1][j] + j);
                }
                else{
                    visited[i][abs(a1[i] - j)] = 1;
                    m[i][abs(a1[i] - j)] = max(m[i][abs(a1[i] - j)], m[i - 1][j] + a1[i]);
                }
            }
        }
        visited[i][a1[i]] = 1;
        for (j = 0; j <= 500000; j++)
        {
            visited[i][j] = max(visited[i][j], visited[i - 1][j]);
            m[i][j] = max(m[i][j], m[i - 1][j]);
        }
    }
    if (visited[n][0])
    {
        cout << m[n][0] << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
