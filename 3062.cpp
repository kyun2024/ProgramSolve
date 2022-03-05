#include <iostream>

using namespace std;

int main(){
    int T;
    int a,t,r;
    cin >> T;
    while(T--){
        cin >> a;
        t = a;
        r = 0;
        while(t){
            r = 10*r + t%10;
            t/=10;
        }
        a = a+r;
        t = a;
        r = 0;
        while(t){
            r = 10*r + t%10;
            t/=10;
        }
        cout << (a==r?"YES":"NO") << endl;
    }
    return 0;
}