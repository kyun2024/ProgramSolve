#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << -1;
        }
        else if (r1 != r2 && (r1 - r2) * (r1 - r2) > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
        {
            cout << 0;
        }
        else if(r1 != r2 && (r1 - r2) * (r1 - r2) == (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)){
            cout << 1;
        }
        else if ((r1 + r2) * (r1 + r2) == (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
        {
            cout << 1;
        }
        else if ((r1 + r2) * (r1 + r2) < (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
        {
            cout << 0;
        }
        else if ((r1 + r2) * (r1 + r2) > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
        {
            cout << 2;
        }
        cout << endl;
    }
}