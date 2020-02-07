#include <iostream>

using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    c*=2;
    cout << min(min(a*x+b*y,max(x,y)*c),min(c*x+max(y-x,0)*b,max(x-y,0)*a+c*y)) << endl;
    return 0;
}