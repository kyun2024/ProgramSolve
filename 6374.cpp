#include <iostream>

using namespace std;

int a[101][101];
int m[101][101];

int main(){
    int n;
    int r1,r2,c1,c2,res;
    cin >> n;
    for(r1=1;r1<=n;r1++){
        for(c1=1;c1<=n;c1++){
            cin >> a[r1][c1];
            m[r1][c1]=a[r1][c1]+m[r1-1][c1]+m[r1][c1-1]-m[r1-1][c1-1];
        }
    }
    res = -2000000;
    for(r1=1;r1<=n;r1++){
        for(c1=1;c1<=n;c1++){
            for(r2=0;r2<r1;r2++){
                for(c2=0;c2<c1;c2++){
                    res = max(res,m[r1][c1]-m[r1][c2]-m[r2][c1]+m[r2][c2]);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}