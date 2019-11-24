#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<long long>> v,res;
    int i,j,k;
    long long sum_val;
    int n;
    cin >> n;
    v.resize(n,vector<long long>(n));
    res.resize(n,vector<long long>(n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    res[0][0]=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=0 || j!=0){
                sum_val = 0;
                for(k=1;k<=i;k++){
                    sum_val += res[i-k][j]*(v[i-k][j]==k);
                }
                for(k=1;k<=j;k++){
                    sum_val += res[i][j-k]*(v[i][j-k]==k);
                }
                res[i][j] = sum_val;
            }
        }
    }
    cout << res[n-1][n-1] << endl;
    return 0;
}