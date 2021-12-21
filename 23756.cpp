#include <iostream>

using namespace std;

int main(){
    int angle, sum_a=0, t;
    int n;
    cin >> n;
    cin >> angle;
    while(n--){
        cin >> t;
        sum_a += min((angle-t+360)%360,(t-angle+360)%360);
        angle = t;
    }
    cout << sum_a << endl;
    return 0;
}