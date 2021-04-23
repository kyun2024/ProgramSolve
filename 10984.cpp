#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int T;
    cin >> T;
    int n,i;
    double x,z,sx,sz;
    while(T--){
        cin >> n;
        sx=0;sz=0;
        for(i=0;i<n;i++){
            cin >> x >> z;
            sx += x;
            sz += x*z;
        }
        cout << setprecision(2) << sx << " " << (sz/sx) << endl;
    }
    return 0;
}