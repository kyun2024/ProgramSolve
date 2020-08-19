#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];

int main(){
    int n,k;
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    cin >> k;
    sort(a+1,a+n+1);
    int f = upper_bound(a+1,a+n+1,k)-a;
    cout << max((k-a[f-1])*(a[f]-k)-1,0) << endl;
    return 0;
}