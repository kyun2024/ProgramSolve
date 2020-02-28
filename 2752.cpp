#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    //모종의 과정
    if(a<b)swap(a,b);
    if(a<c)swap(a,c);
    if(b<c)swap(b,c);
    cout << c << " " << b << " " << a << endl;
    return 0;
}