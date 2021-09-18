#include <iostream>

using namespace std;

int main(){
    int t,s,tm,a;
    cin >> t;
    s = tm = 0;
    cin.get();
    while(t>0){
        a = cin.get();
        if(a==' '){
            s += tm;
            tm = 0;
        }
        else if(a=='\n'){
            s += tm;
            cout << s << endl;
            s = 0;
            tm = 0;
            t--;
        }
        else{
            tm = 10*tm+(a-'0');
        }
    }
    return 0;
}
