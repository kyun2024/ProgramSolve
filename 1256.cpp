#include <iostream>
#include <iomanip>

using namespace std;

long long m[201][201];
bool av[201][201];

int main()
{
    av[0][0] = 1;
    m[0][0] = 1;
    int i, j;
    for (i = 1; i <= 200; i++)
    {
        av[i][0] = 1;
        m[i][0] = 1;
        for (j = 1; j < i; j++)
        {
            if(av[i-1][j-1] && av[i-1][j])
            {
                m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
                if(m[i][j]>1000000000)
                {
                    m[i][j]=0;
                }
                else av[i][j]=1;
            }
        }
        av[i][i] = 1;
        m[i][i] = 1;
    }
    int a, z, k;
    cin >> a >> z >> k;
    string res{};
    while(k)
    {
        //cout << a << " " << z << " " << k << endl;
        if(a == 0)
        {
            if(k>1)
            {
                res = "-1";
                break;
            }
            while(z--)
            {
                res += 'z';
            }
            break;
        }
        else if(z == 0)
        {
            if(k>1)
            {
                res = "-1";
                break;
            }
            while(a--)
            {
                res += 'a';
            }
            break;
        }
        // a, z >= 1
        if(!av[a+z][a]){
            if(!av[a+z-1][a-1])
            {
                res += 'a';
                a--;
            }
            else
            {
                if(m[a+z-1][a-1]<k)
                {
                    res += 'z';
                    k -= m[a+z-1][a-1];
                    z--;
                }
                else
                {
                    res += 'a';
                    a--;
                }
            }
        }
        else
        {
            if(m[a+z][a]<k)
            {
                res = "-1";
                break;
            }
            else
            {
                if(m[a+z-1][a-1]<k)
                {
                    res += 'z';
                    k -= m[a+z-1][a-1];
                    z--;
                }
                else
                {
                    res += 'a';
                    a--;
                }
            }
        }
    }    
    cout << res << endl;
    return 0;
}