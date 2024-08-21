#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int prefix_sum[1001];
int a[1001];
bitset<800000001> check;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;
    int i;

    for(i=1;i<=N;++i) cin >> a[i];
    sort(a+1, a+1+N);
    for(i=1;i<=N;++i) prefix_sum[i] = prefix_sum[i-1]+a[i];
    for(i=1;i<=N;++i)
    {
        check[a[i]]=1;
        for(int x=prefix_sum[i-1]+1;x<=prefix_sum[i];++x)
        {
            if(x>=a[i])check.set(x, check[x]||check[x-a[i]]);
            if(!check[x])
            {
                cout << x << endl;
                return 0;
            }
        }
    }
    cout << prefix_sum[N]+1 << endl;
    return 0;
}