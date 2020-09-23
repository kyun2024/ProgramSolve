#include <iostream>

using namespace std;

int main(){
    int n,b,r;
    while(true){
        cin >> n;
        if(n==0)break;
        b=n;
        r=0;
        while(b!=0){
            r = 10*r + b%10;
            b/=10;
        }
        cout << ((n==r)?"yes":"no") << endl;
    }
    return 0;
}