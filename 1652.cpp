#include <iostream>
#include <string>

using namespace std;

string v[100];

int main()
{
    int n;
    int i, j;
    cin >> n;
    cin.get();
    for (i = 0; i < n; i++)
    {
        getline(cin, v[i]);
    }
    int s = 0;
    int r_res = 0, c_res = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] == '.')
            {
                s++;
            }
            else
            {
                if (s >= 2)
                {
                    r_res++;
                }
                s = 0;
            }
        }
        if (s >= 2)r_res++;
        s = 0;
        for (j = 0; j < n; j++)
        {
            if (v[j][i] == '.')
            {
                s++;
            }
            else
            {
                if (s >= 2)
                {
                    c_res++;
                }
                s = 0;
            }
        }
        if (s >= 2)c_res++;
        s = 0;
    }
    cout << r_res << " " << c_res << endl;
    return 0;
}