#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int i=6,s=0;
    while(i--){
        cin >> str;
        s += str == "W";
    }
    if(s>4)cout << 1 << endl;
    else if(s>2)cout << 2 << endl;
    else if(s>0)cout << 3 << endl;
    else cout << -1 << endl;
    return 0;
}