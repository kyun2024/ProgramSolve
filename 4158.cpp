#include <iostream>

using namespace std;

int m1[1000000], m2[1000000];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int i1, i2;
    int n, m;
    int res=0;
    while (1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)break;
        for(i1=0;i1<n;i1++)cin >> m1[i1];
        for(i2=0;i2<m;i2++)cin >> m2[i2];

        res = 0;
        i1 = i2 = 0;
        while(i1<n && i2<m){
            if(m1[i1]==m2[i2]){
                res++;
                i1++;
                i2++;
            }
            else if(m1[i1]>m2[i2])i2++;
            else i1++;
        }
        cout << res << '\n';
    }
    return 0;
}