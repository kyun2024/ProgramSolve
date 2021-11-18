#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    if(str[0] + str[4] == str[8] + '0'){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}