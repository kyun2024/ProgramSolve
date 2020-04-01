#include <iostream>

using namespace std;

int main(){
    int a,b,c,d,n;
    cin >> a >> b >> c >> d >> n;
    cout << min(a*n,b+d*max(n-c,0)) << endl;
    return 0;
}