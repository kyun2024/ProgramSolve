#include <iostream>

using namespace std;

int a[5];

int main()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    while (true)
    {
        j = 0;
        for (i = 1; i < 5; i++)
        {
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                for (j = 0; j < 5; j++)
                {
                    cout << a[j] << " ";
                }
                cout << '\n';
            }
        }
        if(!j){
            break;
        }
    }
    return 0;
}