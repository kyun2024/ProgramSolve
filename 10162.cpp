#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%10!=0)cout << -1 << endl;
    else{
        int t = n;
        t = n/300;
        n = n - t*300;
        cout << t << " ";
        t = n/60;
        n = n - t*60;
        cout << t << " ";
        t = n/10;
        cout << t << endl;
    }
    return 0;
}