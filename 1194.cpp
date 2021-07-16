#include <iostream>
#include <string>
#include <queue>

using namespace std;

string v[50];
bool check[50][50][(1 << 6)];

struct sinfo
{
    int y, x, key, c;
};

int main()
{
    int n, m;
    cin >> n >> m;
    cin.get();
    int i, j;
    for (i = 0; i < n; i++)
        getline(cin, v[i]);
    queue<sinfo> q;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if (v[i][j] == '0')
            {
                q.push({i, j, 0, 0});
                check[i][j][0] = 1;
                break;
            }
        if (j < m)
            break;
    }
    while (!q.empty())
    {
        sinfo cs = q.front();
        if (v[cs.y][cs.x] == '1')
            break;
        if (cs.x > 0 && check[cs.y][cs.x - 1][cs.key] == 0)
        {
            if (v[cs.y][cs.x - 1] == '.' || v[cs.y][cs.x - 1] == '0' || v[cs.y][cs.x - 1] == '1')
            {
                // move
                check[cs.y][cs.x - 1][cs.key] = 1;
                q.push({cs.y, cs.x - 1, cs.key, cs.c + 1});
            }
            if ('a' <= v[cs.y][cs.x - 1] && v[cs.y][cs.x - 1] <= 'f')
            {
                //get key and move
                check[cs.y][cs.x - 1][cs.key] = 1;
                check[cs.y][cs.x - 1][cs.key | (1 << (v[cs.y][cs.x - 1] - 'a'))] = 1;
                q.push({cs.y, cs.x - 1, cs.key | (1 << (v[cs.y][cs.x - 1] - 'a')), cs.c + 1});
            }
            if ('A' <= v[cs.y][cs.x - 1] && v[cs.y][cs.x - 1] <= 'F' && (cs.key & (1 << (v[cs.y][cs.x - 1] - 'A'))))
            {
                //it's door but you have key
                check[cs.y][cs.x - 1][cs.key] = 1;
                q.push({cs.y, cs.x - 1, cs.key, cs.c + 1});
            }
        }
        if (cs.x < m - 1 && check[cs.y][cs.x + 1][cs.key] == 0)
        {
            if (v[cs.y][cs.x + 1] == '.' || v[cs.y][cs.x + 1] == '0' || v[cs.y][cs.x + 1] == '1')
            {
                // move
                check[cs.y][cs.x + 1][cs.key] = 1;
                q.push({cs.y, cs.x + 1, cs.key, cs.c + 1});
            }
            if ('a' <= v[cs.y][cs.x + 1] && v[cs.y][cs.x + 1] <= 'f')
            {
                //get key and move
                check[cs.y][cs.x + 1][cs.key] = 1;
                check[cs.y][cs.x + 1][cs.key | (1 << (v[cs.y][cs.x + 1] - 'a'))] = 1;
                q.push({cs.y, cs.x + 1, cs.key | (1 << (v[cs.y][cs.x + 1] - 'a')), cs.c + 1});
            }
            if ('A' <= v[cs.y][cs.x + 1] && v[cs.y][cs.x + 1] <= 'F' && (cs.key & (1 << (v[cs.y][cs.x + 1] - 'A'))))
            {
                //it's door but you have key
                check[cs.y][cs.x + 1][cs.key] = 1;
                q.push({cs.y, cs.x + 1, cs.key, cs.c + 1});
            }
        }
        if (cs.y > 0 && check[cs.y - 1][cs.x][cs.key] == 0)
        {
            if (v[cs.y - 1][cs.x] == '.' || v[cs.y  - 1][cs.x] == '0' || v[cs.y  - 1][cs.x] == '1')
            {
                // move
                check[cs.y - 1][cs.x][cs.key] = 1;
                q.push({cs.y - 1, cs.x, cs.key, cs.c + 1});
            }
            if ('a' <= v[cs.y - 1][cs.x] && v[cs.y - 1][cs.x] <= 'f')
            {
                //get key and move
                check[cs.y - 1][cs.x][cs.key] = 1;
                check[cs.y - 1][cs.x][cs.key | (1 << (v[cs.y - 1][cs.x] - 'a'))] = 1;
                q.push({cs.y - 1, cs.x, cs.key | (1 << (v[cs.y - 1][cs.x] - 'a')), cs.c + 1});
            }
            if ('A' <= v[cs.y - 1][cs.x] && v[cs.y - 1][cs.x] <= 'F' && (cs.key & (1 << (v[cs.y - 1][cs.x] - 'A'))))
            {
                //it's door but you have key
                check[cs.y - 1][cs.x][cs.key] = 1;
                q.push({cs.y - 1, cs.x, cs.key, cs.c + 1});
            }
        }
        if (cs.y < n - 1 && check[cs.y + 1][cs.x][cs.key] == 0)
        {
            if (v[cs.y + 1][cs.x] == '.' || v[cs.y + 1][cs.x] == '0' || v[cs.y + 1][cs.x] == '1')
            {
                // move
                check[cs.y + 1][cs.x][cs.key] = 1;
                q.push({cs.y + 1, cs.x, cs.key, cs.c + 1});
            }
            if ('a' <= v[cs.y + 1][cs.x] && v[cs.y + 1][cs.x] <= 'f')
            {
                //get key and move
                check[cs.y + 1][cs.x][cs.key] = 1;
                check[cs.y + 1][cs.x][cs.key | (1 << (v[cs.y + 1][cs.x] - 'a'))] = 1;
                q.push({cs.y + 1, cs.x, cs.key | (1 << (v[cs.y + 1][cs.x] - 'a')), cs.c + 1});
            }
            if ('A' <= v[cs.y + 1][cs.x] && v[cs.y + 1][cs.x] <= 'F' && (cs.key & (1 << (v[cs.y + 1][cs.x] - 'A'))))
            {
                //it's door but you have key
                check[cs.y + 1][cs.x][cs.key] = 1;
                q.push({cs.y + 1, cs.x, cs.key, cs.c + 1});
            }
        }
        q.pop();
    }
    if(q.empty())cout << -1 << endl;
    else cout << q.front().c << endl;
    return 0;
}