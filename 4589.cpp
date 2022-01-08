#include <iostream>

using namespace std;

int main(){
    int n;
    int a,b,c;
    cin >> n;
    cout << "Gnomes:\n";
    while(n--){
        cin >> a >> b >> c;
        cout << ((a>=b && b>=c || a<=b && b<=c)?"Ordered":"Unordered") << '\n';
    }
    return 0;
}