#include <iostream>
#include <vector>

using namespace std;

int main(){
    int r,c;
    int i,j,res;
    vector<vector<int>> v,row,col,dp;
    cin >> r >> c;
    v.resize(r,vector<int>(c,0));
    row.resize(r,vector<int>(c,0));
    col.resize(r,vector<int>(c,0));
    dp.resize(r,vector<int>(c,0));
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%1d",&v[i][j]);
        }
    }
    //row
    for(i=0;i<r;i++){
        row[i][0]=v[i][0];
        for(j=1;j<c;j++){
            row[i][j]=v[i][j]*(row[i][j-1]+1);
        }
    }
    //col
    for(j=0;j<c;j++){
        col[0][j]=v[0][j];
        for(i=1;i<r;i++){
            col[i][j]=v[i][j]*(col[i-1][j]+1);
        }
    }
    
    res = 0;
    for(j=0;j<c;j++){
        dp[0][j]=v[0][j];
        if(dp[0][j]>res)res=dp[0][j];
    }
    for(i=1;i<r;i++){
        dp[i][0]=v[i][0];
        for(j=1;j<c;j++){
            if(dp[i-1][j-1]!=0){
                dp[i][j]=v[i][j]*min(row[i][j],min(col[i][j],dp[i-1][j-1]+1));
            }
            else{
                dp[i][j]=v[i][j];
            }
            if(dp[i][j]>res)res=dp[i][j];
        }
    }
    cout << res*res << endl;
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout << row[i][j] << " ";
        }
        cout << '\t';
        for(j=0;j<c;j++){
            cout << col[i][j] << " ";
        }
        cout << '\t';
        for(j=0;j<c;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}