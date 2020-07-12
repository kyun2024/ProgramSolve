#include <iostream>
#include <string>

using namespace std;

int adj_mat[51][51];

int main(){
    int n;
    string ins;
    int i,j,k;
    cin >> n;
    cin.get();
    for(i=1;i<=n;i++){
        getline(cin,ins);
        for(j=1;j<=n;j++){
            adj_mat[i][j]=(ins[j-1]=='Y'?1:0);
        }
    }
    int res=0;
    int f=0;
    for(i=1;i<=n;i++){
        f=0;
        for(j=1;j<=n;j++){
            if(i==j)continue;
            else if(adj_mat[i][j])f++;
            else{
                for(k=1;k<=n;k++){
                    if(i!=k&&j!=k&&adj_mat[i][k]*adj_mat[k][j]){
                        f++;
                        break;
                    }
                }
            }
        }
        res = max(res,f);
    }
    cout << res << endl;
    return 0;
}