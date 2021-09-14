#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n,s=0,c,k,j;
    while(t--){
        s = 0;
        cin >> n >> k;
        for(j=0;j<n;j++){
            cin >> c;
            s += c/k;
        }
        cout << s << endl;
    }
    return 0;
}