#include <iostream>

using namespace std;

int main(){
    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a>=b)cout << "MMM BRAINS\n";
        else cout << "NO BRAINS\n";
    }
    return 0;
}