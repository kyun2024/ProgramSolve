#include <iostream>
#include <algorithm>

using namespace std;

int a[100'001];

int main(){
    int n,i,res=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(i=1;i<=n;i++){
        res=max(res,i*a[i]);
    }
    cout << res << endl;
    return 0;
}