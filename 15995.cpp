#include <iostream>

using namespace std;

int main(){
    unsigned long long a,x,m;
    cin >> a >> m;
    for(x=1;(a*x)%m!=1;x++);
    cout << x << endl;
}