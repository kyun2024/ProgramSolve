#include <iostream>

using namespace std;

int m[502][502];

int R,C;
int c, max_s;

int diff[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int __dfs(int y,int x)
{
    int s = 0;
    m[y][x] = 0;
    for(int i=0;i<4;i++)
    {
        if(m[y+diff[i][0]][x+diff[i][1]])
            s += __dfs(y+diff[i][0],x+diff[i][1]);
    }
    return s+1;
}

void dfs(int y,int x)
{   
    int s = 0;
    ++c;
    m[y][x]=0;
    for(int i=0;i<4;i++)
    {
        if(m[y+diff[i][0]][x+diff[i][1]])
            s += __dfs(y+diff[i][0],x+diff[i][1]);
    }
    max_s = max(max_s, s+1);
}

int main()
{
    int i,j;
    cin >> R >> C;
    for(i=1;i<=R;i++)for(j=1;j<=C;j++)cin >> m[i][j];
    for(i=1;i<=R;i++)for(j=1;j<=C;j++)if(m[i][j])dfs(i,j);
    cout << c << endl << max_s << endl;
}