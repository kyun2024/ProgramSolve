#include <iostream>

using namespace std;

int main(){
    char str[8];
    cin >> str;
    if (str[0]==str[1] && str[1]==str[2] && str[2]=='5')cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}