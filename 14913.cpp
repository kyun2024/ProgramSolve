#include <iostream>

using namespace std;

int main(){
    int n,d,k;
    cin >> n >> d >> k;
    if(d>0){
        if(n>k)goto X;

    }
    else{
        if(n<k)goto X;
    }
    if((k-n)%d!=0)goto X;
    cout << (k-n)/d+1 << endl;
    return 0;
X:
    cout << "X" << endl;
    return 0;
}