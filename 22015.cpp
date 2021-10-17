#include <iostream>

using namespace std;

int main(){
    int a,b,c,m;
    cin >> a >> b >> c;
    m = max(max(a,b),c);
    cout << 3*m - (a+b+c) << endl;
    return 0;
}