#include <iostream>

using namespace std;

int main(){
    int n,r;
    int n2n{},n5n{},r12n{},r15n{},r22n{},r25n{};
    int t,i;
    cin >> n >> r;
    t = n;
    while(t!=0){
        n2n += t/2;
        t/=2;
    }
    t = n;
    while(t!=0){
        n5n += t/5;
        t/=5;
    }
    t = r;
    while(t!=0){
        r12n += t/2;
        t/=2;
    }
    t = r;
    while(t!=0){
        r15n += t/5;
        t/=5;
    }
    t = n-r;
    while(t!=0){
        r22n += t/2;
        t/=2;
    }
    t = n-r;
    while(t!=0){
        r25n += t/5;
        t/=5;
    }
    cout << min(n2n-r12n-r22n,n5n-r15n-r25n) << endl;
    return 0;
}