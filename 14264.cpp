#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double n;
    cin >> n;
    cout << fixed << setprecision(9) << n*n/4.0*sqrtl(3) << endl;
    return 0;
}