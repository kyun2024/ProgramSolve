#include <iostream>

using namespace std;

long long m[51];
int c[51];

using ll=long long;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    return x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2;
}

int main()
{
    int n;
    int i, j, k, res=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> m[i];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(i==j)continue;
            c[i] += [&k,i,j]() -> int {
                int s = min(i,j), e = max(i,j);
                for(k=s+1;k<e;k++){
                    if(ccw(s,m[s],e,m[e],k,m[k])>=0){
                        return 0;
                    }
                }
                return 1;
            }();
        }
        res = max(res,c[i]);
    }
    cout << res << endl;
    return 0;
}