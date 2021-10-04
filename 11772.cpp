#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n,s{},a;
    cin >> n;
    while(n--){
        cin >> a;
        s += pow(a/10,a%10);
    }
    cout << s << endl;
    return 0;
}