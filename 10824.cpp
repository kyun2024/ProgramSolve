#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << 10*a*static_cast<long long>(powl(10,static_cast<long long>(log10l(b))))+b + 10*c*static_cast<long long>(powl(10,static_cast<long long>(log10l(d))))+d << endl;
}