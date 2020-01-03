#include <iostream>

using namespace std;
int main(){
    int a,s{};
    for(int i=0;i<5;i++){
        cin >> a;
        s += a*a;
    }
    cout << s%10 << endl;
    return 0;

}