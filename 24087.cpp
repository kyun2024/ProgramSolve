#include <iostream>

using namespace std;

int main(){
    int s,a,b;
    cin >> s >> a >> b;
    cout << 250+((max(0,s-a)+b-1)/b)*100 << endl;
    return 0;
}