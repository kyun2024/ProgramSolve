#include <iostream>
#include <iomanip>

using namespace std;

constexpr double pi=3.141592;

int main(){
    double w,r;
    cin >> w >> r;
    cout << fixed << setprecision(6) << 2*pi*r+2*w << endl;
    return 0;
}