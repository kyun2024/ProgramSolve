#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int a,b,gcd_val;
    cin >> a >> b;
    gcd_val = gcd(a,b);
    cout << gcd_val << endl << a*b/gcd_val << endl;
    return 0;
}