#include <iostream>

using namespace std;

int main(){
    int T;
    int a,b,c;
    cin >> T;
    while(T--){
        cin >> a >> b >> c;
        if(a<b-c){
            cout << "advertise\n";
        }
        else if(a==b-c){
            cout << "does not matter\n";
        }
        else{
            cout << "do not advertise\n";
        }
    }
    return 0;
}