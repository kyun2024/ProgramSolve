#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    long long a,b;
    while(T--){
        cin >> a >> b;
        cout << (a*a)/(b*b) << endl;
    }
    return 0;
}