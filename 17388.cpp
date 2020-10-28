#include <iostream>

using namespace std;

int main(){
    int s,k,h;
    cin >> s >> k >> h;
    if(s+k+h>=100){
        cout << "OK" << endl;
    }
    else if(s==min(s,min(k,h))){
        cout << "Soongsil" << endl;
    }
    else if(k==min(s,min(k,h))){
        cout << "Korea" << endl;
    }
    else if(h==min(s,min(k,h))){
        cout << "Hanyang" << endl;
    }
    return 0;
}