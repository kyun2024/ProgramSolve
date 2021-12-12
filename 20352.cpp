#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    long long n;
    cin >> n;
    cout << fixed << setprecision(7) << 2*M_PI*sqrtl(n/M_PI) << endl;
    return 0;
}