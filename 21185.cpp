#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    n=n%4;
    switch(n){
    case 0:
        cout << "Even" << endl;
        break;
    case 2:
        cout << "Odd" << endl;
        break;
    default:
        cout << "Either" << endl;
        break;
    }
    return 0;
}