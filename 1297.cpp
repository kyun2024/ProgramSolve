#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int c,a,b;
    cin >> c >> a >> b;
    double x = sqrtl(double(c*c)/(a*a+b*b));
    cout << int(a*x) << " " << int(b*x) << endl;
    return 0;
}