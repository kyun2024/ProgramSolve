#include <iostream>
#include <algorithm>

using namespace std;

using ull = unsigned long long;

int main(){
    ull n;
    ull a,b,c,d,e,f;
    cin >> n;
    cin >> a >> b >> c >> d >> e >> f;
    if(n==1){
        cout << (a+b+c+d+e+f)-max({a,b,c,d,e,f}) << endl;
    }
    else cout << min({a,b,c,d,e,f})*(n-2)*(5*(n-2)+4)
    + min({a+b,a+c,a+d,a+e,b+c,b+d,b+f,c+e,c+f,d+e,d+f,e+f})*(8*n-12)
    + min({a+b+c,a+c+e,a+e+d,a+d+b,f+b+c,f+c+e,f+e+d,f+d+b})*4
    << endl;
    return 0;
}