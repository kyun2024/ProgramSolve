#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    int t,n;
    vector<int> v;
    double m;
    cin >> t;
    for(int i=0;i<t;i++){
        m=0;
        cin >> n;
        v.clear();
        v.resize(n,0);
        for(int j=0;j<n;j++){
            cin >> v[j];
            m += v[j];
        }
        m = m/n;
        double zf=0;
        for(int j=0;j<n;j++){
            if (v[j]>m){
                zf+=1;
            }
        }
        zf/=n;
        cout << fixed << setprecision(3) << zf*100 << "%\n"; 
    }
    return 0;
}