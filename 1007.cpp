#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int base[1048577][21];
int lb[21];
int n;
int crd[21][2];
int cnt;

void init(){
    fill_n(lb,21,0);
    cnt=0;
}

void dfs(int l,int c){
    lb[l]=1;
    if(c==n/2){
        for(int i=1;i<=n;i++){
            base[cnt][i]=(lb[i]==1)?1:-1;
        }
        cnt++;
        lb[l]=0;
        return;
    }
    for(int i=l+1;i<=n;i++){
        dfs(i,c+1);
    }
    lb[l]=0;
}

int main(){
    int T;
    int i,j;
    long double r;
    long double sx,sy;
    cin >> T;
    while(T--){
        cin >> n;
        init();
        dfs(0,0);
        for(i=1;i<=n;i++){
            cin >> crd[i][0] >> crd[i][1];
        }
        r = 987654321;
        for(i=0;i<cnt;i++){
            sx = sy = 0;
            // for(j=1;j<=n;j++){
            //     cout << base[i][j] << " ";
            // }
            // cout << endl;
            for(j=1;j<=n;j++){
                sx += base[i][j]*crd[j][0];
                sy += base[i][j]*crd[j][1];
                //cout << base[i][j] << "*" << crd[i][0] << " " << base[i][j] << "*" << crd[i][1] << endl;
            }
            //cout << sx << " " << sy << endl;
            r = min(r,sqrtl(sx*sx+sy*sy));
        }
        cout << fixed << setprecision(7) << r << endl;
    }
}