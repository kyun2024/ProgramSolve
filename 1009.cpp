#include <iostream>

using namespace std;

int main(){
    int t,a,b,r,i;
    cin >> t;
    while(t--){
        cin >> a >> b;
        r=1;
        for(i=1;i<=b;i++){
            r = (r*a)%10;
        }
        cout << (r+9)%10+1 << endl;
    }
    return 0;
}