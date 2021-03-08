#include <iostream>

using namespace std;

pair<int, int> d[1001][1001], m[1001][1001][2];

std::pair<int, int> operator+(const std::pair<int, int> &x, const std::pair<int, int> &y)
{
    return std::make_pair(x.first + y.first, x.second + y.second);
}

int main()
{
    int n;
    int i, j, y, x;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            if (x == 0)
            {
                d[i][j].first = -1;
                continue;
            }
            while (x % 2 == 0)
            {
                d[i][j].first++;
                x >>= 1;
            }
            while (x % 5 == 0)
            {
                d[i][j].second++;
                x /= 5;
            }
        }
    }
    m[1][1][0] = m[1][1][1] = d[1][1];
    for (i = 2; i <= n; i++)
    {
        for (j = i, y = 1; j >= 1; j--, y++)
        {
            //cout << y << " " << j << endl;
            if (d[y][j].first == -1)
                continue;
            if (j > 1 && d[y][j - 1].first != -1)
            {
                //from the left
                m[y][j][0] = m[y][j - 1][0];
                m[y][j][0] = m[y][j][0] + d[y][j];
                m[y][j][1] = m[y][j - 1][1];
                m[y][j][1] = m[y][j][1] + d[y][j];
            }
            else
            {
                if (y > 1 && d[y - 1][j].first != -1)
                {
                    //from the up
                    m[y][j][0] = m[y - 1][j][0];
                    m[y][j][0] = m[y][j][0] + d[y][j];
                    m[y][j][1] = m[y - 1][j][1];
                    m[y][j][1] = m[y][j][1] + d[y][j];
                }
                else
                {
                    d[y][j].first = -1;
                }
            }
            if (y > 1 && d[y - 1][j].first != -1)
            {
                //from the up
                if (m[y][j][0].second > (m[y - 1][j][0] + d[y][j]).second)
                {
                    m[y][j][0] = m[y - 1][j][0] + d[y][j];
                }
                if (m[y][j][1].first > (m[y - 1][j][1] + d[y][j]).first)
                {
                    m[y][j][1] = m[y - 1][j][1] + d[y][j];
                }
            }
            //cout << "m2: " << m[y][j][0].first << ", " << m[y][j][0].second << endl;
            //cout << "m5: " << m[y][j][1].first << ", " << m[y][j][1].second << endl;
        }
    }
    for(i=2;i<=n;i++){
        for(y=i,j=n;y<=n;y++,j--){
            //cout << y << " " << j << endl;
            if (d[y][j].first == -1)
                continue;
            if (j > 1 && d[y][j - 1].first != -1)
            {
                //from the left
                m[y][j][0] = m[y][j - 1][0];
                m[y][j][0] = m[y][j][0] + d[y][j];
                m[y][j][1] = m[y][j - 1][1];
                m[y][j][1] = m[y][j][1] + d[y][j];
            }
            else
            {
                if (y > 1 && d[y - 1][j].first != -1)
                {
                    //from the up
                    m[y][j][0] = m[y - 1][j][0];
                    m[y][j][0] = m[y][j][0] + d[y][j];
                    m[y][j][1] = m[y - 1][j][1];
                    m[y][j][1] = m[y][j][1] + d[y][j];
                }
                else
                {
                    d[y][j].first = -1;
                }
            }
            if (y > 1 && d[y - 1][j].first != -1)
            {
                //from the up
                if (m[y][j][0].second > (m[y - 1][j][0] + d[y][j]).second)
                {
                    m[y][j][0] = m[y - 1][j][0] + d[y][j];
                }
                if (m[y][j][1].first > (m[y - 1][j][1] + d[y][j]).first)
                {
                    m[y][j][1] = m[y - 1][j][1] + d[y][j];
                }
            }
            //cout << "m2: " << m[y][j][0].first << ", " << m[y][j][0].second << endl;
            //cout << "m5: " << m[y][j][1].first << ", " << m[y][j][1].second << endl;
        }
    }
    cout << min(min(m[n][n][0].first, m[n][n][0].second), min(m[n][n][1].first, m[n][n][1].second)) << endl;
    return 0;
}