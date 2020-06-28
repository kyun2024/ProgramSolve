#include <iostream>
#include <string>

using namespace std;

int main(){
    string a,op,b;
    cin >> a >> op >> b;
    if(op==string("*")){
        cout << 1 << string(a.length()+b.length()-2,'0') << endl;
    }
    else{
        if(a.length()==b.length()){
            a[0]='2';
            cout << a << endl;
        }
        else if(a.length()>b.length()){
            a[a.length()-b.length()]='1';
            cout << a << endl;
        }
        else{
            b[b.length()-a.length()]='1';
            cout << b << endl;
        }
    }
    return 0;
}