#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int a,b,n;
    cin >> a >> b >> n;
    if(a/gcd(a,b)*b>n)cout << "no\n";
    else cout << "yes\n";
    return 0;
}
