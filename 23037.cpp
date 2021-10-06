#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    int res{};
    cin >> n;
    while(n){
        res += pow(n%10,5);
        n/=10;
    }
    cout << res << endl;
    return 0;
}