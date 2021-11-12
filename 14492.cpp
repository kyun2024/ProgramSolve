#include <iostream>

using namespace std;

int m_a[300][300], m_b[300][300];

int main()
{
    int n;
    int i, j, k, b, c = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> m_a[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> m_b[i][j];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            b = 0;
            for (k = 0; k < n; k++)
            {
                b |= m_a[i][k] & m_b[k][j];
            }
            c += b;
        }
    }
    cout << c << endl;
    return 0;
}
