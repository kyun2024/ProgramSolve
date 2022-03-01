#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(c-(b+1),(b-1)-a) << endl;
    return 0;
}