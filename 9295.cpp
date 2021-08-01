#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int a,b,i=0;
    while(T--){
        cin >> a >> b;
        cout << "Case " << ++i << ": " << a+b << '\n';
    }
    return 0;
}