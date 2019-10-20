#include <iostream>

using namespace std;

int main(){
    char c;
    int n,i;
    int res=0;
    cin >> n;
    cin.get();
    for(i=0;i<n;i++){
        cin >> c;
        res += c-'0';
    }
    cout << res << endl;
    return 0;
}