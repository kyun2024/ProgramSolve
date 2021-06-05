#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int b;
    int bz=1;
    int dec=0;
    cin >> str >> b;
    for(auto it=str.rbegin();it!=str.rend();it++){
        dec += bz*(('0'<=(*it) && (*it)<='9')?(*it)-'0':(*it)-'A'+10);
        bz *= b;
    }
    cout << dec << endl;
    return 0;
}