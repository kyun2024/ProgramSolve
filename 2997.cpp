#include <iostream>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c;
    if(a>b)swap(a,b);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    if(b-a == c-b){
        cout << 2*c-b << endl;
    }
    else if(2*(b-a) == c-b){
        cout << 2*b-a << endl;
    }
    else if(b-a == 2*(c-b)){
        cout << (a+b)/2 << endl;
    }
    return 0;
}