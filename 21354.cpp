#include <iostream>

using namespace std;

int main(){
    int a,p;
    cin >> a >> p;
    if(7*a>13*p){
        cout << "Axel\n";
    }
    if(7*a<13*p){
        cout << "Petra\n";
    }
    if(7*a == 13*p){
        cout << "lika\n";
    }
    return 0;
}