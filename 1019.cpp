#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long long r[10];

int main()
{
    long long n;
    int i, j, x;
    cin >> n;
    int l = (int)log10(n) + 1;
    
    for (i = 0; i < 10; i++)
    {
        r[i] += n / 10;
    }
    for (i = 0; i <= n % 10; i++)
    {
        r[i] += 1;
    }
    if (l >= 2)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 100) * 10;
        }
        for (i = 0; i < (n % 100) / 10; i++)
        {
            r[i] += 10;
        }
        r[(n % 100) / 10] += (n % 10)+1;
    }
    if (l >= 3)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 1000) * 100;
        }
        for (i = 0; i < (n % 1000) / 100; i++)
        {
            r[i] += 100;
        }
        r[(n % 1000) / 100] += (n % 100)+1;
    }
    if (l >= 4)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 10000) * 1000;
        }
        for (i = 0; i < (n % 10000) / 1000; i++)
        {
            r[i] += 1000;
        }
        r[(n % 10000) / 1000] += (n % 1000)+1;
    }
    if (l >= 5)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 100000) * 10000;
        }
        for (i = 0; i < (n % 100000) / 10000; i++)
        {
            r[i] += 10000;
        }
        r[(n % 100000) / 10000] += (n % 10000)+1;
    }
    if (l >= 6)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 1000000) * 100000;
        }
        for (i = 0; i < (n % 1000000) / 100000; i++)
        {
            r[i] += 100000;
        }
        r[(n % 1000000) / 100000] += (n % 100000)+1;
    }
    if (l >= 7)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 10000000) * 1000000;
        }
        for (i = 0; i < (n % 10000000) / 1000000; i++)
        {
            r[i] += 1000000;
        }
        r[(n % 10000000) / 1000000] += (n % 1000000)+1;
    }
    if (l >= 8)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 100000000) * 10000000;
        }
        for (i = 0; i < (n % 100000000) / 10000000; i++)
        {
            r[i] += 10000000;
        }
        r[(n % 100000000) / 10000000] += (n % 10000000)+1;
    }
    if (l >= 9)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 1000000000) * 100000000;
        }
        for (i = 0; i < (n % 1000000000) / 100000000; i++)
        {
            r[i] += 100000000;
        }
        r[(n % 1000000000) / 100000000] += (n % 100000000)+1;
    }
    if (l >= 10)
    {
        for (i = 0; i < 10; i++)
        {
            r[i] += (n / 10000000000LL) * 1000000000;
        }
        for (i = 0; i < (n % 10000000000LL) / 1000000000; i++)
        {
            r[i] += 1000000000;
        }
        r[(n % 10000000000LL) / 1000000000] += (n % 1000000000)+1;
    }
    int sub_n = 0;
    for (i = 0; i < l; i++)
    {
        sub_n = 10 * sub_n + 1;
    }
    cout << r[0] - sub_n << " ";
    for (i = 1; i < 10; i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
    return 0;
}