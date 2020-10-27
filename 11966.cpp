#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<32> b;
    int n;
    cin >> n;
    b=n;
    cout << (b.count() == 1) << endl;
    return 0;
}