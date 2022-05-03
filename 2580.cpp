#include <iostream>

using namespace std;

int rc[9], cc[9], sc[9];
int m[9][9];
int e;

void f2(int r,int c)
{
    if(r==9)
    {
        e = 1;
        return;
    }
    if (m[r][c] != 0)
    {
        f2(r+(c+1)/9,(c+1)%9);
        return;
    }
    int i;
    for (i = 1; i <= 9; i++)
    {
        if (((rc[r] & (1 << (i - 1))) == 0) &&
        ((cc[c] & (1 << (i - 1))) == 0) &&
        ((sc[(r/3)*3 + (c/3)] & (1 << (i-1))) == 0))
        {
            rc[r] |= (1 << (i - 1));
            cc[c] |= (1 << (i - 1));
            sc[(r/3)*3 + (c/3)] |= (1 << (i - 1));
            m[r][c] = i;
            f2(r+(c+1)/9,(c+1)%9);
            if (e)
                return;
            rc[r] -= (1 << (i - 1));
            cc[c] -= (1 << (i - 1));
            sc[(r/3)*3 + (c/3)] -= (1 << (i - 1));
            m[r][c] = 0;
        }
    }
}

int main()
{
    int r, c, a;
    for (r = 0; r < 9; r++)
    {
        for (c = 0; c < 9; c++)
        {
            cin >> a;
            m[r][c] = a;
            if (a)
            {
                rc[r] |= (1 << (a - 1));
                cc[c] |= (1 << (a - 1));
                sc[(r / 3) * 3 + (c / 3)] |= (1 << (a - 1));
            }
        }
    }
    
    f2(0,0);
    for (r = 0; r < 9; r++)
    {
        for (c = 0; c < 9; c++)
        {
            cout << m[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}
