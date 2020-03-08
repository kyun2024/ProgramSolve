#include <iostream>
#include <iomanip>

using namespace std;

int row[500],col[500];
int dp[500][500];

int main(){
    int n;
    int i,j,k;
    cin >> n;
    for(i=0;i<n;i++)cin >> row[i] >> col[i];
    for(i=1;i<n;i++){  //대각선 출발 위치 - r는 1로 고정
        for(j=0;j<n-i;j++){  //대각선 진행 횟수
            for(k=j;k<i+j;k++){
                //cout << j << ", " << i+j << ", " << k << endl;
                if(dp[j][i+j]==0){
                    dp[j][i+j]=dp[j][k]+dp[k+1][i+j]+row[j]*col[k]*col[i+j];
                }
                else{
                    dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+row[j]*col[k]*col[i+j]);
                }
            }
        }
    }
    /*
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << setw(4) << right << dp[i][j];
        }
        cout << endl;
    }
    */

    cout << dp[0][n-1] << endl;
    return 0;
}