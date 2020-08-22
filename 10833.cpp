#include <iostream>

using namespace std;

int main(){
    int s{},a,b,n;
    cin >> n;
    while(n--){
        cin >> a >> b;
        s += b%a;
    }
    cout << s << endl;
    return 0;
}