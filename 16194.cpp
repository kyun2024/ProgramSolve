#include <iostream>

using namespace std;

int a[1001];
int m[1001];

int main()
{
    int n;
    int i,j;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(i=1;i<=n;i++)
    {
        m[i] = 987654321;
        for(j=1;j<=i;j++)
        {
            m[i] = min(a[j]+m[i-j],m[i]);
        }
    }
    cout << m[n] << endl;
    return 0;
}