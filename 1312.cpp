#include <iostream>

using namespace std;

int kdigit(int n,int q,int k){
    if(k==0)return n/q;
    return kdigit((n%q)*10,q,k-1);
}

int main(){
    int a,b,n;
    cin >> a >> b >> n;
    cout << kdigit(a,b,n) << endl;
    return 0;
}