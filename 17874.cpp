#include <iostream>

using namespace std;

int main(){
    int n,v,h;
    cin >> n >> h >> v;
    cout << 4*max(h*v,max(h*(n-v),max((n-h)*v,(n-h)*(n-v)))) << endl;
    return 0;
}