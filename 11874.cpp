#include <iostream>

using namespace std;

int main(){
    int L,D,X;
    int n,t,t2;
    cin >> L >> D >> X;
    for(n=L;n<=D;n++){
        t = n;
        t2 = 0;
        while(t){
            t2 += t%10;
            t/=10;
        }
        if(t2 == X)break;
    }
    cout << n << endl;
    for(n=D;n>=L;n--){
        t = n;
        t2 = 0;
        while(t){
            t2 += t%10;
            t/=10;
        }
        if(t2 == X)break;
    }
    cout << n << endl;
    return 0;
}