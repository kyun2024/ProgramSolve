#include <iostream>
#include <string>

using namespace std;

int main(){
    string q;
    cin >> q;
    int a=1, b=2, c=3;
    for(const auto z:q){
        if(z=='A'){
            swap(a,b);
        }
        if(z=='B'){
            swap(b,c);
        }
        if(z=='C'){
            swap(a,c);
        }
    }
    if(a==1)cout << 1 << endl;
    else if(b==1)cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}