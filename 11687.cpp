#include <iostream>

using namespace std;

int main()
{
    long long m, n, c;
    cin >> m;
    for(n=4*m + (5-(4*m)%5);;n+=5)
    {
        c= n/5 + n/25 + n/125 + n/625 + n/3125 + n/15625 + n/78125 + n/390625 + n/1953125 + n/9765625 + n/48828125 + n/244140625 + n/1220703125;
        // cout << n << " : " << c << endl;
        if(c == m)
        {
            cout << n << endl;
            break;
        }
        if(c > m)
        {
            cout << -1 << endl;
            break;
        }
    }
    return 0;
}