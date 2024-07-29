#include <iostream>
#include <iomanip>

using namespace std;

int m[100][20000];
int r[100] = {1, 0};

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    int K, i, j;
    while(T--)
    {
        cin >> K;
        if(K==1)
        {
            cout << 1 << endl;
            continue;
        }
        for(i=1;i<100;++i)
        {
            r[i] = (10*r[i-1])%K;
        }
        m[0][r[0]] = 1;
        for(i=1;i<100;++i)
        {
            for(j=0;j<K;++j)
            {
                if(m[i-1][j])
                {
                    m[i][j] = m[i-1][j];
                    if(m[i][(j+r[i])%K] == 0)m[i][(j+r[i])%K] = m[i-1][j]+1;
                }
            }
            m[i][r[i]] = 1;
            if(m[i][0])break;
        }
        j = 0;
        for(;i>=1;--i)
        {
            if(m[i-1][j] == m[i][j])cout << 0;
            else
            {
                cout << 1;
                j = (j-r[i]+K)%K;
            }
        }
        cout << (j == r[0]) << endl;
        // cout << setw(3) << right << "";
        // for(j=0;j<K;++j)
        // {
        //     cout << setw(3) << right << j;
        // }
        // cout << endl;
        // for(i=0;i<5;++i)
        // {
        //     cout << setw(3) << right << r[i];
        //     for(j=0;j<K;++j)
        //     {
        //         cout << setw(3) << right << m[i][j];
        //     }
        //     cout << endl;
        // }
        for(i=0;i<100;++i)for(j=0;j<K;++j)m[i][j]=0;
    }
}