#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int n,m,res=1e9;
    cin >> n >> m;
    v.resize(n);
    for(auto &x : v){
        cin >> x;
    }
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){
                if(v[i]+v[j]+v[k]<=m && res > m-v[i]-v[j]-v[k]){
                    res = m - v[i] - v[j] - v[k];
                }
            }
        }
    }
    cout << m-res << endl;
    return 0;
}