#include <iostream>

using namespace std;

int main(){
    long long n,r,c,res{},n2,i;
    bool rch,cch;
    cin >> n >> r >> c;
    for(n2=1,i=0;i<n;n2*=2,i++);
    while(n2>1){
        rch=(r>=n2/2);
        cch=(c>=n2/2);
        res+=(2*rch+1*cch)*(n2*n2)/4;
        //cout << (2*rch+1*cch)*(n2*n2)/4 << endl;
        n2/=2;
        r=r-n2*rch;
        c=c-n2*cch;
    
    }
    cout << res << endl;
    return 0;
}