#include <iostream>

using namespace std;

int main(){
    int n,c;
    cin >> n;
    for(c=1;n!=1;c++){
        if(n%2==0)n=n/2;
        else n=3*n+1;
    }
    cout << c << endl;
}