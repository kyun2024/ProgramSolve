#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x,y,r;
    unsigned long long s,i;
    while(true){
        cin >> x >> y >> r;
        if(x==y && y==r && r==0)break;
        s = 0;
        for(i=0;i<r;i++){
           s += ceil(sqrt(r*r-i*i));
        }
        cout << 4*s << endl;
    }
    return 0;
}