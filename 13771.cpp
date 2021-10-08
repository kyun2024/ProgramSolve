#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    double a,min_v,min2_v;
    cin >> n;
    cin >> min_v >> min2_v;
    if(min_v>min2_v)swap(min_v,min2_v);
    for(int i=3;i<=n;i++){
        cin >> a;
        if(a<min_v){
            min2_v = min_v;
            min_v = a;
        }
        else if(a<min2_v){
            min2_v = a;
        }
    }
    cout << fixed << setprecision(2) << min2_v << endl;
    return 0;
}