#include <iostream>
#include <queue>

using namespace std;

int v[1000][1000];
bool check[1000][1000][11][2];

struct sinfo
{
    unsigned short y, x;
    int c;
    char b;
    bool d;
    sinfo(unsigned short y=0,unsigned short x=0,int c=0,char b=0,bool d=0):y(y),x(x),c(c),b(b),d(d){}
};

queue<sinfo> q;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%1d", &v[i][j]);
        }
    }
    check[0][0][0][0] = 1;
    q.push(sinfo(0,0,0,0,0));
    int cnt=0;
    while (!q.empty())
    {
        sinfo cs = q.front();
        if (q.front().y == r - 1 && q.front().x == c - 1)
            break;
        //printf("%d %d %d %d %d\n", cs.y, cs.x, cs.b, cs.d, ++cnt);
        if (!check[cs.y][cs.x][cs.b][!cs.d])
        {
            check[cs.y][cs.x][cs.b][!cs.d] = true;
            q.push(sinfo(cs.y, cs.x, cs.c + 1, cs.b, !cs.d));
            //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y,cs.x,cs.b,!cs.d);
        }
        if (cs.x > 0)
        {
            if (v[cs.y][cs.x - 1] == 1)
            {
                if (cs.b < k && cs.d == 0 && !check[cs.y][cs.x - 1][cs.b + 1][1])
                {
                    check[cs.y][cs.x - 1][cs.b + 1][1] = true;
                    q.push(sinfo(cs.y, cs.x - 1, cs.c + 1, cs.b + 1, !cs.d));
                    //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y,cs.x-1,cs.b+1,!cs.d);
                }
            }
            else if (!check[cs.y][cs.x - 1][cs.b][!cs.d])
            {
                check[cs.y][cs.x - 1][cs.b][!cs.d] = true;
                q.push(sinfo(cs.y, cs.x - 1, cs.c + 1, cs.b, !cs.d));
                //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y,cs.x-1,cs.b,!cs.d);
            }
        }
        if (cs.x < c - 1)
        {
            if (v[cs.y][cs.x + 1] == 1)
            {
                if (cs.b < k && cs.d == 0 && !check[cs.y][cs.x + 1][cs.b + 1][1])
                {
                    check[cs.y][cs.x + 1][cs.b + 1][1] = true;
                    q.push(sinfo(cs.y, cs.x + 1, cs.c + 1, cs.b + 1, !cs.d));
                    //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y,cs.x+1,cs.b+1,!cs.d);
                }
            }
            else if (!check[cs.y][cs.x + 1][cs.b][!cs.d])
            {
                check[cs.y][cs.x + 1][cs.b][!cs.d] = true;
                q.push(sinfo(cs.y, cs.x + 1, cs.c + 1, cs.b, !cs.d));
                //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y,cs.x+1,cs.b,!cs.d);
            }
        }
        if (cs.y > 0)
        {
            if (v[cs.y - 1][cs.x] == 1)
            {
                if (cs.b < k && cs.d == 0 && !check[cs.y - 1][cs.x][cs.b + 1][1])
                {
                    check[cs.y - 1][cs.x][cs.b + 1][1] = true;
                    q.push(sinfo(cs.y - 1, cs.x, cs.c + 1, cs.b + 1, !cs.d));
                    //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y-1,cs.x,cs.b+1,!cs.d);
                }
            }
            else if (!check[cs.y - 1][cs.x][cs.b][!cs.d])
            {
                check[cs.y - 1][cs.x][cs.b][!cs.d] = true;
                q.push(sinfo(cs.y - 1, cs.x, cs.c + 1, cs.b, !cs.d));
                //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y-1,cs.x,cs.b,!cs.d);
            }
        }
        if (cs.y < r - 1)
        {
            if (v[cs.y + 1][cs.x] == 1)
            {
                if (cs.b < k && cs.d == 0 && !check[cs.y + 1][cs.x][cs.b + 1][1])
                {
                    check[cs.y + 1][cs.x][cs.b + 1][1] = true;
                    q.push(sinfo(cs.y + 1, cs.x, cs.c + 1, cs.b + 1, !cs.d));
                    //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y+1,cs.x,cs.b+1,!cs.d);
                }
            }
            else if (!check[cs.y + 1][cs.x][cs.b][!cs.d])
            {
                check[cs.y + 1][cs.x][cs.b][!cs.d] = true;
                q.push(sinfo(cs.y + 1, cs.x, cs.c + 1, cs.b, !cs.d));
                //printf("(%d, %d, %d, %d)->(%d, %d, %d, %d)\n",cs.y,cs.x,cs.b,cs.d,cs.y+1,cs.x,cs.b,!cs.d);
            }
        }
        q.pop();
    }
    if (q.empty())
        printf("-1\n");
    else
        printf("%d\n", q.front().c+1);
    return 0;
}