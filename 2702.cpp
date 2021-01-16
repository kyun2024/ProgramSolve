#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(){
    int T;
    int a,b;
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << lcm(a,b) << " " << gcd(a,b) << '\n';
    };
}