#include <iostream>
#include <string>

using namespace std;

int rev(int n){
    int r;
    for(r=0;n>0;r=10*r+n%10,n/=10);
    return r;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << rev(rev(a)+rev(b)) << endl;

}