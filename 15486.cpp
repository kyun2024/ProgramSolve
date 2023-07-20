#include <iostream>

using namespace std;

int m[1500051];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N;
    int n, p, i;
    cin >> N;
    for(i=1;i<=N;i++)
    {
        cin >> n >> p;
        m[i] = max(m[i], m[i-1]);
        m[i+n-1] = max(m[i+n-1],m[i-1]+p);
    }
    cout << m[N] << endl;
    return 0;
}