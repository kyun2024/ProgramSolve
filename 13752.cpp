#include <iostream>

using namespace std;

int main(){
    int n,a;
    cin >> n;
    while(n--){
        cin >> a;
        while(a--){
            cout << '=';
        }
        cout << '\n';
    }
    return 0;
}