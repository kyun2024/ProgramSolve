#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double n;
    cin >> n;
    n = 25 + 0.01*n;
    n = max(100.0,n);
    n = min(2000.0,n);
    cout << fixed << setprecision(2) << n << endl;
    return 0;
}