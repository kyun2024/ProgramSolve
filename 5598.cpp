#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    for(auto x: str){
        char c = (x-'A'-3+26)%26+'A';
        cout << c;
    }
    cout << endl;
    return 0;
}