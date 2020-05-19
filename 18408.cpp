#include <iostream>

using namespace std;

int main(){
    // 1 1 1 -> 3
    // 1 1 2 -> 4
    // 1 2 2 -> 5
    // 2 2 2 -> 6
    int a,b,c;
    cin >> a >> b >> c;
    cout << (a+b+c>4)+1 << endl;
    return 0;
}