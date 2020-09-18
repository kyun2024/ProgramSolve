#include <iostream>

using namespace std;

ostream& print_uni(ostream& os,int code){
    char c;
    c = 0b1110'0000 + ((0b1111)&(code>>12));
    os << c;
    c = 0b1000'0000 + ((0b0011'1111)&(code>>6));
    os << c;
    c = 0b1000'0000 + ((0b0011'1111)&code);
    os << c;
    return os;
}

int main(){
    int code;
    cin >> code;
    print_uni(cout, code+0xabff);
    cout << endl;
    return 0;
}