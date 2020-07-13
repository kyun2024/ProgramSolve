#include <iostream>

using namespace std;

int main(){
    int n,a,b,t;
    while(true){
        t=1;
        cin >> n;
        if(n==0)break;
        while(n--){
            cin >> a >> b;
            t = t*a-b;
        }
        cout << t << endl;
    }
    return 0;
}