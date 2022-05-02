#include <iostream>

using namespace std;

int main(){
    int n,a,b;
    cin >> n;
    a = n;
    b = 0;
    while((a&1)==0){
        a>>=1;
        b++;
    }
    cout << a << " " << b << endl;
    return 0;
}
