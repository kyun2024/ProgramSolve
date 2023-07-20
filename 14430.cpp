#include <iostream>

using namespace std;

int m[301][301];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int R, C;
    int i, j, x;
    cin >> R >> C;
    for(i=1;i<=R;i++)
    {
        for(j=1;j<=C;j++)
        {
            cin >> x;
            m[i][j] = x + max(m[i-1][j], m[i][j-1]);
        }
    }
    cout << m[R][C] << endl;
    return 0;
}