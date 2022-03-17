#include <iostream>

using namespace std;

int main(){
    int n,t,s;
    while(1){
        cin >> n;
        if(n==0)break;
        while(n>=10){
            t = n;
            s = 0;
            while(t){
                s += t%10;
                t/=10;
            }
            n = s;
        }
        cout << n << endl;
    }
    return 0;
}
