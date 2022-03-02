#include <iostream>

using namespace std;

int main(){
    int i,n;
    cin >> n;
    for(i=0;i<=100;i++){
        if(1+i+i*i==n){
            cout << i << endl;
            break;
        }
    }
    return 0;
}