#include <iostream>

using namespace std;

int main()
{
    int T, t, i;
    int a, b;
    int res;
    cin >> T;
    for (t = 1; t <= T; t++)
    {
        cin >> a >> b;
        res = 0;
        for (i = 1; i <= 1259; i++)
        {
            if (i * i * i > b)
                break;
            if (a <= i * i * i)
                res++;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}