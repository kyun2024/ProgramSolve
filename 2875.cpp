#include <iostream>

using namespace std;

int main(){
    int f,m,k;
    int t=0,r=0;
    cin >> f >> m >> k;
    t = min(f/2,m);
    r = f+m-3*t;
    k = max(k-r,0);
    t -= (k+2)/3;
    cout << t << endl;
}