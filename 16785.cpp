#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    //cout << (a==0 && b==0?-1:(a!=0 ? c/(7*a+b)*7+((c%(7*a+b))+a-1)/a : ((c+b-1)/b)*7)) << endl;
    cout << c/(7*a+b)*7 + min(((c%(7*a+b))+a-1)/a,7) << endl;
    return 0;
}