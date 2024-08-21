#include <iostream>

using namespace std;

int m[2222222];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, i, a{};
    cin >> n;
    for(i=0;i<n;++i)
    {
        cin >> m[i];
        a ^= m[i];
    }
    int res = a;
    for(i=0;i<n;++i)
    {
        res = max(res, a^m[i]);
    }
    cout << res << res << endl;

    return 0;
}