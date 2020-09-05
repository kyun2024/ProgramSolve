#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];
int sec[10000];

int main(){
    int n,k;
    int s,r=0,dist;
    int i;
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(i=0;i<n-1;i++){
        sec[i]=a[i+1]-a[i];
    }
    sort(sec,sec+n-1);
    s=0;
    for(i=0;i<n-k;i++){
        s += sec[i];
    }
    cout << s << endl;
    return 0;
}