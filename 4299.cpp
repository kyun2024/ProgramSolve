#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if((a+b)%2!=0 || a<b){
        cout << -1 << endl;
    }
    else{
        cout << (a+b)/2 << " " << abs(a-b)/2 << endl;
    }
}