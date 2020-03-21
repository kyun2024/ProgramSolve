#include <iostream>

using namespace std;

int main(){
    long long t,a,b,i,r,n;
    cin >> t;
    while(--t>=0){
        cin >> a >> b;
        n=b-a;
        r=n;
        for(i=1;i*i<=n;i++){
            r=min(r,2*(i-1)+(n-(i-1)*(i-1))/i);
        }
        cout << r << endl;
    }
    return 0;
}