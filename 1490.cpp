#include <iostream>

using namespace std;

int ns[10];
int main()
{
    long long d, t;
    cin >> d;
    t = d;
    while (t > 0)
    {
        ns[t % 10] = 1;
        t /= 10;
    }
    for (t = 1; t < 10; t++)
    {
        if (ns[t] && d % t != 0)
            break;
    }
    if (t == 10)
    {
        cout << d << endl;
        return 0;
    }
    long long i, j, x, n;
    x = 10;
    for (i = 0;; i++)
    {
        for (j = 0; j < x; j++)
        {
            n = d * x + j;
            for (t = 1; t < 10; t++)
            {
                if (ns[t] && (n % t) != 0)
                    break;
            }
            if (t == 10)
            {
                cout << n << endl;
                return 0;
            }
            /*else
            {
                cout << n << " " << t << endl;
            }*/
        }
        x *= 10;
    }
    return 0;
}