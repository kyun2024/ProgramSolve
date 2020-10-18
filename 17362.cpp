#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << ((n-1)/4%2)*(5-(n-1)%4)+(1-(n-1)/4%2)*((n-1)%4+1) << endl;
    return 0;
}