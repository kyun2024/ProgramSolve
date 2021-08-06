#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    while(true){
        cin >> a >> b >> c;
        if(a==b && b==c && c==0)break;
        if(b-a == c-b){
            cout << "AP " << 2*c-b << endl;
        }
        else{
            cout << "GP " << c*b/a << endl;
        }
    }
    return 0;
}