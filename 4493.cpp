#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, sa, sb;
        string a, b;
        cin >> n;
        sa = sb = 0;
        while (n--)
        {
            cin >> a >> b;
            if (a == "R" && b == "S" || a == "P" && b == "R" || a == "S" && b == "P")
            {
                sa++;
            }
            if (b == "R" && a == "S" || b == "P" && a == "R" || b == "S" && a == "P")
            {
                sb++;
            }
        }
        if (sa > sb)
        {
            cout << "Player 1" << endl;
        }
        if (sa < sb)
        {
            cout << "Player 2" << endl;
        }
        if (sa == sb)
        {
            cout << "TIE" << endl;
        }
    }
    return 0;
}