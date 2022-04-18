#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int n, m;
        int i, j;
        int x{}, y{}, c{};
        cin >> m >> n;
        if(m==0 && n==0)break;
        for (i = m; i <= n; i++)
        {
            c = 0;
            for (j = 1; j * j < i; j++)
            {
                if (i % j == 0)
                    c += 2;
            }
            if (j * j == i)
                c += 1;
            if (c >= y)
            {
                x = i;
                y = c;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}