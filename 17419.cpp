#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    bitset<1000000> b;
    cin >> b;
    cout << b.count() << endl;
    return 0; 
}