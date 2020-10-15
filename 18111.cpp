#include <iostream>

using namespace std;

int mcm[500][500];

int main(){
    int n,m,ori_b,b,ts=0;
    int i,j,k;
    int res_time=1e9, res_height=0;
    cin >> n >> m >> ori_b;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> mcm[i][j];
        }
    }
    for(k=0;k<=256;k++){
        b = ori_b;
        ts = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
               if(mcm[i][j]>k){
                   ts += 2*(mcm[i][j]-k);
               } 
               else if(mcm[i][j]<k){
                   ts += (k-mcm[i][j]);
               }
               b += (mcm[i][j]-k);
            }
        }
        if(b>=0 && res_time>=ts){
            res_time = ts;
            res_height = k;
        }
    }
    cout << res_time << " " << res_height << endl;
    return 0;
}