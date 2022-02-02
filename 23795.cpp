#include <iostream>

using namespace std;

int main(){
    int s=0,n;
    while(1){
        cin >> n;
        if(n==-1)break;
        s += n;
    }
    cout << s << endl;
    return 0;
}