#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n,i;
    double x;
    double m=0,res=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        if(x<=x*m){
            m = m*x;
        }
        else m = x;
        res = max(res,m);
    }
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}