#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int s = x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2;
    cout << (s>0)-(s<0) << endl;
    return 0;
}