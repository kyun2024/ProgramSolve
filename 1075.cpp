#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    cout << setfill('0') << setw(2) << (m-(n/100*100)%m)%m << endl;
    return 0;
}