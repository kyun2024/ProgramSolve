#include <iostream>

using namespace std;

void llswap(long long& a,long long &b){
    long long t=a;
    a=b;
    b=t;
}

int main(){
    long long a,b,t=0;
    cin >> a >> b;
    if(a>b)llswap(a,b);

    cout << -a*(a-1)/2+b*(b+1)/2 << endl;
    return 0;
}