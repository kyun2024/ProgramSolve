#include <iostream>

using namespace std;

int a[3];

int main(){
    int n,i,m;
    cin >> n;
    for(i=0;i<n;i++)cin>>a[i];
    m = min(a[0],a[1]);
    m = (n==3)?min(m,a[2]):m;
    for(i=1;i<=m;i++){
        if(a[0]%i==0 && a[1]%i==0 && a[2]%i==0){
            cout << i << '\n';
        }
    }
    return 0;
}
