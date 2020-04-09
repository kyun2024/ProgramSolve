#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int n;
    double t;
    cin >> n;
    t = static_cast<double>(n);
    cout << setprecision(6) << fixed << t*t*M_PI << endl << setprecision(6) << fixed << t*t*2.0 << endl;
    return 0;
}