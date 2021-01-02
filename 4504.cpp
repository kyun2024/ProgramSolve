#include <iostream>

using namespace std;

int main(){
    int n,a;
    cin >> n;
    while(true){
        cin >> a;
        if(a==0)break;
        cout << a << " is ";
        if(a%n!=0){
            cout << "NOT ";
        }
        cout << "a multiple of " << n << ".\n";
    }
    return 0;
}
