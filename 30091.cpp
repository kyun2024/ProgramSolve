#include <iostream>
#include <algorithm>

using namespace std;

long long a[2000];
long long c[20'000'001];
long long cc[10'000'001];

int n;

long long solution()
{
    int i,j;
    long long res = 0;
    for(i=0;i<n;++i)
    {
        for(j=i;j<n;++j)
        {
            // cout << i << " " << j << " " << a[i] << " " << a[j] << " ";
            if(a[i] == a[j] && cc[a[i]]>1){
                // cout << cc[a[i]]/2*a[i]*a[j];
                c[a[i]+a[j]] += cc[a[i]]/2*a[i]*a[j];
            }
            else if(a[i] != a[j])
            {
                // cout << min(cc[a[i]], cc[a[j]])*a[i]*a[j];
                c[a[i]+a[j]] += min(cc[a[i]], cc[a[j]])*a[i]*a[j];
            }
            // cout << endl;
        }
    }
    for(i=0;i<=20'000'000;++i)res = max(res, c[i]);
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
        ++cc[a[i]];
    }
    sort(a, a+n);
    n = unique(a, a+n)-a;
    cout << solution() << endl;
    return 0;
}