#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m[102][102];

int main()
{
    int R, C;
    cin >> R >> C;
    int i, j;
    for (i = 1; i <= R; i++)
        for (j = 1; j <= C; ++j)
            cin >> m[i][j];
    queue<tuple<int, int, int>> que, temp_que;
    que.push(make_tuple(0, 0, 0));
    int tt = 0;
    int cc = 0, b_cc = 0;
    while (1)
    {
        cc = 0;
        while (!que.empty())
        {
            int r = get<0>(que.front());
            int c = get<1>(que.front());
            int t = get<2>(que.front());
            // cout << "a" << r << " " << c << " " << t << endl;
            if (0 <= r && r <= R+1 && 0 <= c && c <= C+1)
            {
                if (m[r][c] == 0)
                {
                    m[r][c] = 2;
                    que.push(make_tuple(r + 1, c, t));
                    que.push(make_tuple(r, c + 1, t));
                    que.push(make_tuple(r - 1, c, t));
                    que.push(make_tuple(r, c - 1, t));
                }
                if (m[r][c] == 1)
                {
                    ++cc;
                    m[r][c] = 3;
                    temp_que.push(make_tuple(r, c, t + 1));
                }
            }
            que.pop();
        }
        // cout << "----" << endl;
        // for(i=0;i<=R+1;i++){
        //     for(j=0;j<=C+1;j++)
        //     {
        //         cout << m[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (cc == 0)
            break;
        while (!temp_que.empty())
        {
            int r = get<0>(temp_que.front());
            int c = get<1>(temp_que.front());
            int t = get<2>(temp_que.front());
            // cout << "c" << r << " " << c << " " << t << endl;
            m[r][c] = 0;
            que.push(temp_que.front());
            temp_que.pop();
        }
        ++tt;
        b_cc = cc;
        // cout << "----" << endl;
        // for(i=0;i<=R+1;i++){
        //     for(j=0;j<=C+1;j++)
        //     {
        //         cout << m[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    cout << tt << endl
         << b_cc << endl;
}