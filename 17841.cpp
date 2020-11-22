#include <iostream>
#include <string>

using namespace std;

int m[100001][6];
string s[100001];

const string unist = " UNIST";
int s_idx(char c)
{
    switch (c)
    {
    case 'U':
        return 1;
    case 'N':
        return 2;
    case 'I':
        return 3;
    case 'S':
        return 4;
    case 'T':
        return 5;
    default:
        return -1;
    }
}

int main()
{
    int n, i, j, si;
    cin >> n;
    cin.get();
    for (i = 1; i <= n; i++)
    {
        getline(cin, s[i]);
    }
    m[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        si = s_idx(s[i][0]);
        if (si > 0)
        {
            for (j = 0; j < min(5-si+1,(int)s[i].length()); j++)
            {
                if (s[i][j] == unist[si + j])
                {
                    m[i][si+j] = m[i-1][si-1];
                }
                else break;
            }
        }
        for(j=0;j<=5;j++)m[i][j]=(m[i][j]+m[i-1][j])%1000000007;
    }
    cout << m[n][5] << endl;
    return 0;
}