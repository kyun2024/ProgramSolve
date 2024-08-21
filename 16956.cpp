#include <iostream>
#include <string>

using namespace std;

int m[502][502];

int main()
{
    int R, C;
    int i, j;
    string s;
    cin >> R >> C;
    for(i=1;i<=R;++i)
    {
        cin >> s;
        for(j=1;j<=C;++j)
        {
            if(s[j-1]=='S')
            {
                m[i][j] = 1;
            }
            else if(s[j-1] == 'W')
            {
                m[i][j] = 2;
            }
        }
    }
    bool res = 1;
    for(i=1;i<=R;++i)
    {
        for(j=1;j<=C;++j)
        {
            if(m[i][j] == 1)
            {
                if(m[i][j-1] == 2 || m[i][j+1] == 2 || m[i-1][j] == 2 || m[i+1][j] == 2)
                {
                    res = 0;
                }
            }
        }
    }
    cout << res << endl;
    if(res)
    {
        for(i=1;i<=R;++i)
        {
            for(j=1;j<=C;++j)
            {
                cout << (m[i][j] == 0?'D':(m[i][j]==1?'S':'W'));
            }
            cout << endl;
        }
    }
    return 0;
}