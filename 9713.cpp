#include <iostream>

using namespace std;

int main()
{
    int n;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << ((n + 1) * (n + 1) / 4) << endl;
    }
    return 0;
}