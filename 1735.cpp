#include <iostream>

using namespace std;

int gcd(int a,int b){
    int r;
    if(a<b)swap(a,b);
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << (a*d+b*c)/gcd(a*d+b*c,b*d) << " " << b*d/gcd(a*d+b*c,b*d) << endl;
    return 0;
}