#include <iostream>

using namespace std;

int main()
{
    int T;
    int n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        n--;
        n = n % 28;
        if (n / 14)n = 15 - (n - 14);
        else n++;
        cout << (n & 8 ? "딸기" : "V");
        cout << (n & 4 ? "딸기" : "V");
        cout << (n & 2 ? "딸기" : "V");
        cout << (n & 1 ? "딸기" : "V") << '\n';
    }
    return 0;
}