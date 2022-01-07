#include <iostream>

using namespace std;

int main(){
    int n;
    int a,b,i;
    while(1){
        cin >> n;
        if(n==0)break;
        cin >> a;
        cout << a << " ";
        for(i=1;i<n;i++){
            cin >> b;
            if(b!=a)cout << b << " ";
            a = b;
        }
        cout << "$" << endl;
    }
    return 0;
}