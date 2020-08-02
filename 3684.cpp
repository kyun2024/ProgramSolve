#include <iostream>

using namespace std;

int ar[101];
int n;

void get_a_b(int &a, int &b)
{
    int t, k;
    for (a = 0; a <= 10000; a++)
    {
        for (b = 0; b <= 10000; b++)
        {
            for (k = 1; k < n; k++)
            {
                t = ar[k] * a % 10001;
                t = (t * a + a * b + b) % 10001;
                if (t != ar[k+1])break;
            }
            if(k==n)return;
        }
    }
}

int main()
{
    int i, a, b;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> ar[i];
    if (n == 1)
    {
        cout << ar[1] << endl;
        return 0;
    }
    get_a_b(a, b);
    //cout << a << " " << b << endl;
    for (i = 1; i <= n; i++)
    {
        cout << (a * ar[i] + b) % 10001 << endl;
    }
    return 0;
}