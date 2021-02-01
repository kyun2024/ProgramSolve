#include <iostream>

using namespace std;

char m[102][102];
int rc[101], cc[101];

int main()
{
    int r, c;
    int i, j, sc;
    bool upc = false;
    for (i = 0; i < 102; i++)
    {
        for (j = 0; j < 102; j++)
        {
            m[i][j] = '.';
        }
    }
    cin >> r >> c;
    cin.get();
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            m[i][j] = cin.get();
        }
        cin.get();
    }
    for (i = 1; i <= r; i++)
    {
        sc = 0;
        for (j = 1; j <= c; j++)
        {
            if (m[i][j] == '#')
            {
                sc++;
            }
        }
        if (sc == 1)
        {
            for(j=1;j<=c;j++){
                if(m[i-1][j]=='#' &&
                m[i][j]=='#' &&
                m[i+1][j]=='#'){
                    cout << "RIGHT\n";
                    return 0;
                }
                if(m[i-1][j]=='#' &&
                m[i][j]=='.' &&
                m[i+1][j]=='#'){
                    cout << "LEFT\n";
                    return 0;
                }
            }
        }
        if (sc > 3)
        {
            if (sc % 2 != 0)
            {
                upc = true;
            }
            else
            {
                if (!upc)
                {
                    cout << "UP\n";
                    return 0;
                }
                else
                {
                    cout << "DOWN\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}