#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    constexpr int bias = 44031;
    int x;
    string c;
    cin >> c;
    x = (((c[0]&0xF)<<4) + ((c[1]&0x3C)>>2))*256 + (((c[1]&0x3)<<6) + (c[2]&0x3F));
    cout << x-bias << endl;
    return 0;
}