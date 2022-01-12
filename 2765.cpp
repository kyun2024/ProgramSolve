#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double r,rot,t;
    int i;
    for(i=1;;i++){
        cin >> r >> rot >> t;
        if(rot==0)break;
        cout << "Trip #" << i << ": " << fixed << setprecision(2) << M_PI*r*rot/63360 << " " << M_PI*r*rot/63360/t*3600 << endl;
    }
    return 0;
}