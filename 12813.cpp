#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<100000> b1,b2;
    cin >> b1 >> b2;
    cout << (b1&b2).to_string() << endl;
    cout << (b1|b2).to_string() << endl;
    cout << (b1^b2).to_string() << endl;
    cout << (~b1).to_string() << endl;
    cout << (~b2).to_string() << endl;
    return 0;
}

