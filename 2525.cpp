#include <iostream>

using namespace std;

int main(){
    int a,b,c,t;
    cin >> a >> b >> c;
    t = a*60+b+c;
    a = t/60%24;
    b = t%60;
    cout << a << " " << b << endl;
    return 0;
}