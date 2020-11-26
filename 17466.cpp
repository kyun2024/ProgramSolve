#include <iostream>

using namespace std;

int main(){
    unsigned long long n,r=1,p;
    cin >> n >> p;
    while(n>0){
        r = (r*n)%p;
        n--;
    }
    cout << r << endl;
}