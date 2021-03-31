#include <iostream>

using namespace std;

int main(){
    int r=1;
    int a,b,c;
    cin >> a >> b >> c;
    if(!(a%2|b%2|c%2)){
        cout << a*b*c << endl;
    }
    else{
        if(a%2)r*=a;
        if(b%2)r*=b;
        if(c%2)r*=c;
        cout << r << endl;
    }
    return 0;
}