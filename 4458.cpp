#include <iostream>

using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    cin.get();
    while(n--){
        getline(cin,str);
        if('a'<=str[0] && str[0]<='z'){
            str[0] -= 'a'-'A';
        }
        cout << str << endl;
    }
    return 0;
}