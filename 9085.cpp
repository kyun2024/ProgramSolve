#include <iostream>

using namespace std;

int main(){
    int T,n,a,x,i;
    cin >> T;
    while(T--){
        x = 0;
        cin >> n;
        for(i=0;i<n;i++){
            cin >> a;
            x+=a;
        }
        cout << x << endl;
    }
    return 0;
}