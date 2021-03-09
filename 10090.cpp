#include <iostream>

using namespace std;

int seg_a[4000004];
int v[1000001];

int main(){
    long long n,res;
    int i,x;
    
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        v[x]=i;
    }

    res = n*(n-1)/2;
    for(i=1;i<=n;i++){
        x = v[i];
        while(x>0){
            res -= seg_a[x];
            x -= (x & -x);
        }
        x = v[i];
        while(x<=n){
            seg_a[x]++;
            x += (x&-x);
        }
    }
    cout << res << endl;
    return 0;
}