#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int a,b;
    while(T--){
        cin >> a >> b;
        cout << (a*a)/(b*b) << endl;
    }
    return 0;
}