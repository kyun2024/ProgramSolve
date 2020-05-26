#include <iostream>

using namespace std;

int a[100'001],s[100'001];

int main(){
    int res=-1e7;
    int n,k,i;
    cin >> n >> k;
    for(i=1;i<=n;i++){
        cin >> a[i];
        s[i]=a[i]+s[i-1];
    }
    for(i=k;i<=n;i++){
        res=max(res,s[i]-s[i-k]);
    }
    cout << res << endl;
    return 0;
}
