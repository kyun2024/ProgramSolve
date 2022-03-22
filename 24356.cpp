#include <iostream>

using namespace std;

int main(){
    int a,b,c,d;
    int t1,t2;
    cin >> a >> b >> c >> d;
    t1 = a*60+b;
    t2 = c*60+d;
    t1 = (t2-t1+24*60)%(24*60);
    cout << t1 << " " << t1/30 << endl;
    return 0;
}