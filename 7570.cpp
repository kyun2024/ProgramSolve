#include <iostream>

using namespace std;

int d[1000001];
int a[1000001];


int main(){
    int n,x;
    int i,res=1;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        a[x]=i;
    }
    d[1]=1;
    for(i=2;i<=n;i++){
        if(a[i-1]<a[i]){
            d[i]=d[i-1]+1;
        }
        else d[i]=1;
        res = max(res,d[i]);
    }
    cout << n-res << endl;
    return 0;
}