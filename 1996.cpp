#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> v,m;
    int n,i,j,k,l;
    char c;
    cin >> n;
    v.resize(n+2,vector<int>(n+2,0));
    m.resize(n+1,vector<int>(n+1,0));
    cin.get();
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            c = cin.get();
            if(c!='.'){
                v[i][j]=c-'0';
            }
        }
        cin.get();
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(v[i][j]!=0){
                m[i][j]=-1;
            }
            else{
                for(k=i-1;k<=i+1;k++){
                    for(l=j-1;l<=j+1;l++){
                        m[i][j] += v[k][l];
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(m[i][j]==-1){
                cout << '*';
            }
            else if(m[i][j]>=10){
                cout << 'M';
            }
            else cout << m[i][j];
        }
        cout << '\n';
    }
    return 0;
}