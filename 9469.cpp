#include <iostream>

using namespace std;

int main(){
    int t,n;
    cin >> t;
    double d,a,b,f;
    while(t--){
        cin >> n >> d >> a >> b >> f;
        cout << n << " " << d/(a+b)*f << endl;
    }
    return 0;
}