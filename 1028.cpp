#include <iostream>
#include <iomanip>

using namespace std;

int v[751][751],ld[752][752],lu[752][752];

int main(){
    int r,c,res=0;
    int i,j,k;
    cin >> r >> c;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%1d",&v[i][j]);
        }
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            ld[i][j]=ld[i-1][j-1]+v[i][j];
        }    
    }
    for(i=r;i>=1;i--){
        for(j=1;j<=c;j++){
            lu[i][j]=lu[i+1][j-1]+v[i][j];
        }
    }
    for(j=1;j<=c;j++){
        res = max(res,v[1][j]);
        res = max(res,v[r][j]);
    }
    for(i=2;i<r;i++){
        for(j=1;j<=c;j++){
            res = max(res,v[i][j]);
            for(k=1;j-2*k>=1 && i-k>=1 && i+k <= r;k++){
                if(v[i][j-2*k]==1){
                    if(ld[i+k][j-k]-ld[i-1][j-2*k-1] >= k+1 && 
                    lu[i-k][j-k]-lu[i+1][j-2*k-1] >= k+1 &&
                    ld[i][j]-ld[i-k-1][j-k-1] >= k+1 &&
                    lu[i][j]-lu[i+k+1][j-k-1] >= k+1){
                        res = max(res,k+1);
                    }
                    /*
                    res = max(res,min(min(ld[i+k][j-k]-ld[i-1][j-2*k-1],lu[i-k][j-k]-lu[i+1][j-2*k-1]),min(ld[i][j]-ld[i-k-1][j-k-1],lu[i][j]-lu[i+k+1][j-k-1])));
                    */
                }
            }
        }
    }
    cout << res << endl;
    
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++)
        {
            cout << setw(2) << ld[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++)
        {
            cout << setw(2) << lu[i][j];
        }
        cout << endl;
    }
    
    return 0;
}