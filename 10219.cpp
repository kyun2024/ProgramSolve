#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    int H, W;
    string s;
    cin >> T;
    while(T--)
    {
        cin >> H >> W;
        while(H--)
        {
            cin >> s;
            cout << string(s.rbegin(), s.rend()) << endl;
        }
    }
    return 0;
}