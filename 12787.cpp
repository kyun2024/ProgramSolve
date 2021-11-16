#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    unsigned long long n, ft;
    int T, a, i;
    cin >> T;
    while (T--)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> str;
            ft = n = 0;
            for (i = 0; i < str.length(); i++)
            {
                if (str[i] == '.')
                {
                    n <<= 8;
                    n += ft;
                    ft = 0;
                }
                else
                {
                    ft = 10 * ft + str[i] - '0';
                }
            }
            n <<= 8;
            n += ft;
            cout << n << endl;
        }
        else
        {
            cin >> n;
            ft = 255;
            ft <<= 56;
            for (i = 7; i >= 0; i--)
            {
                cout << ((n & ft) >> (i * 8));
                ft >>= 8;
                if (i > 0)
                    cout << ".";
            }
            cout << endl;
        }
    }
    return 0;
}