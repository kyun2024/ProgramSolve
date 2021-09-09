#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<100> b1,b2;
    int t;
    cin >> t;
    while(t--){
        cin >> b1 >> b2;
        cout << "Hamming distance is " << (b1^b2).count() << ".\n";
    }
    return 0;
}