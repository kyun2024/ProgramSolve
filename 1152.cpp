#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int res = 0, cnt = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
        {
            if (cnt != 0)
            {
                res++;
            }
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    if (cnt != 0)
    {
        res++;
    }
    cout << res << endl;
    return 0;
}