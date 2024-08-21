#include <iostream>

using namespace std;

int m[201][201];

int main()
{
    int w, h;
    int x, y;
    int i, j;

    cin >> w >> h >> x >> y;

    m[0][1] = 1;
    for(i=1;i<=x;++i)
        for(j=1;j<=y;++j)
            m[i][j] = (m[i-1][j]+m[i][j-1])%1000007;
    for(i=x;i<=w;++i)
        for(j=y;j<=h;++j)
            m[i][j] = (m[i-1][j]+m[i][j-1])%1000007;
    cout << m[w][h] << endl;
    
    return 0;
}