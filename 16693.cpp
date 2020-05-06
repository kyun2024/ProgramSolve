#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a/b>c*c*M_PI/d){
        cout << "Slice of pizza" << endl;
    }
    else cout << "Whole pizza" << endl;
    return 0;
}