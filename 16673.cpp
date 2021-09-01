#include <iostream>

using namespace std;

int main(){
    long long c,k,p,s=0;
    cin >> c >> k >> p;
    for(long long i=1;i<=c;i++){
        s += k*i+p*i*i;
    }
    cout << s << endl;
    return 0;
}