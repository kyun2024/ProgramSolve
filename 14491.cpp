#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n;
    cin >> n;
    while(n){
        str = (char)('0'+(n%9)) + str;
        n/=9;
    }
    cout << str << endl;
    return 0;
}