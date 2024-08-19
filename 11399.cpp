#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];

int main()
{
    int N, i;
    cin >> N;
    for(i=1;i<=N;++i)
    {
        cin >> a[i];
    }
    sort(a+1, a+N+1, greater<int>());
    int res=0;
    for(i=1;i<=N;++i)
    {
        res += i*a[i];
    }
    cout << res << endl;
    
    return 0;
}