#include <iostream>

using namespace std;

int main(){
    int n,tot=0,sco=0,x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x==1){
            sco++;
        }
        else{
            sco=0;
        }
        tot += sco;
    }
    cout << tot << endl;
    return 0;
}