#include <iostream>

using namespace std;

int main(){
    int a,x,b,y,t;
    cin >> a >> x >> b >> y >> t;
    cout << a+21*x*max(t-30,0) << " " << b+21*y*max(t-45,0) << endl;
    return 0;
}