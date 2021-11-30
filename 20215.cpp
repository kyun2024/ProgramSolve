#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int w,h;
    cin >> w >> h;
    cout << fixed << setprecision(7) << w+h-sqrtl(w*w+h*h) << endl;
    return 0;
}