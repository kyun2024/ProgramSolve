#include <iostream>

using namespace std;

int v[1001];
int m[1001];

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=1;i<=n;i++)cin >> v[i];
    for(i=2;i<=n;i++){
        for(j=1;j<i;j++){
            if(v[j]<v[i]){
                m[i]=max(m[i],m[j]+v[j]);
            }
        }
    }
    int res = v[1];
    for(i=2;i<=n;i++){
        res = max(res,v[i]+m[i]);
    }
    cout << res << endl;
    return 0;
}