#include <iostream>
#include <iomanip>

using namespace std;

long long p[5]={35034,23090,19055,12530,18090};
long long t[5];

int main(){
    int T;
    cin >> T;
    while(T--){
        for(int i=0;i<5;i++)cin >> t[i];
        long long r=0;
        for(int i=0;i<5;i++)r += t[i]*p[i];
        cout << "$" << fixed << setprecision(2) << r/100.0 << endl;
    }
    return 0;
}