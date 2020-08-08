#include <iostream>

using namespace std;

int facto(int n){
    if(n<=1)return 1;
    else return n*facto(n-1);
}

int combination(int n,int r){
    return facto(n)/(facto(r)*facto(n-r));
}

int main(){
    int n,r;
    cin >> n >> r;
    cout << combination(n,r) << endl;
}