#include <iostream>

using namespace std;

int v[11];

int main(){
    int n;
    int i,j,k,l,m,t,s;
    cin >> n;
    for(i=1;i<=n;i++)cin >> v[i];
    int res=0;
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            for(k=j+1;k<=n;k++){
                for(l=k+1;l<=n;l++){
                    s = 0;
                    t = 1;
                    for(m=1;m<j;m++){
                        t *= v[m];
                    }
                    s += t;
                    t = 1;
                    for(m=j;m<k;m++)t *= v[m];
                    s += t;
                    t = 1;
                    for(m=k;m<l;m++)t *= v[m];
                    s += t;
                    t = 1;
                    for(m=l;m<=n;m++)t *= v[m];
                    s += t;
                    res = max(res,s);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}