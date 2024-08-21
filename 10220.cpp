#include <iostream>

using namespace std;

int m[100];
int c[100];
int N;

int req(int i, int n)
{
    if (i == n)
    {
        int k;
        for (k = 0; k < n; ++k)
            c[k] = 0;
        for (k = 0; k < n; ++k)
            ++c[m[k]];
        for (k = 0; k < n && m[k] == c[k]; ++k)
            ;
        if (k == n)
        {
            for (int k = 0; k < n; ++k)
            {
                cout << m[k] << " ";
            }
            cout << endl;
        }
        return (k == n);
    }
    int res = 0;
    for (int k = (i == n); k < n; ++k)
    {
        m[i] = k;
        res += req(i + 1, n);
        m[i] = 0;
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        if(N>=7)cout << 1 << '\n';
        else if(N==4)cout << 2 << '\n';
        else if(N==5)cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}