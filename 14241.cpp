#include <iostream>

using namespace std;

int v[101];

int main(){
    int n;
    int res=0,i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    for(i=2;i<=n;i++){
        res += v[i]*v[i-1];
        v[i]+=v[i-1];
    }
    cout << res << endl;
    return 0;
}