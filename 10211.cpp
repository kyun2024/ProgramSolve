#include <iostream>

using namespace std;

int main(){    
    int T;
    cin >> T;
    int n,i,k,r,m;
    while(T--){
        cin >> n;
        cin >> m;
        r = m;
        for(i=2;i<=n;i++){
            cin >> k;
            if(m+k<k){
                m = k;
            }
            else{
                m = m+k;
            }
            r = max(r,m);
        }
        cout << r << endl;
    }
}