#include <iostream>

using namespace std;

int v[5001],m[800000];

int main(){
    // partition by 2 - 2|2
    // select 2 in back partition
    // save front partition weight in m
    int w,n;
    int i,j;
    cin >> w >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            if(w-v[i]-v[j]<0)continue;
            if(m[w-v[i]-v[j]]){
                cout << "YES" << endl;
                return 0;
            }
        }
        for(j=1;j<i;j++){
            m[v[i]+v[j]]=1;
        }
    }
    cout << "NO" << endl;
    return 0;
}