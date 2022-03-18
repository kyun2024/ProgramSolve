#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    int n=0;
    while(1){
        cin >> a;
        if(a==0)break;
        cin >> b >> c;
        if(4*a*a>=b*b+c*c){
            cout << "Pizza " << ++n << " fits on the table.\n";
        }
        else{
            cout << "Pizza " << ++n << " does not fit on the table.\n";
        }
    }
    return 0;
}
