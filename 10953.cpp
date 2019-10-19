#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n,a,b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        a=str[0]-'0';
        b=str[2]-'0';
        cout << a+b << endl;
    }
    return 0;
}