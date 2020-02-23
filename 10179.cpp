#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    double x;
    cin >> n;
    while(--n>=0){
        cin >> x;
        cout << '$' << setprecision(2) << fixed << x*0.8 << endl;
    }
    return 0;
}