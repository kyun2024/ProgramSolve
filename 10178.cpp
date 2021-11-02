#include <iostream>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    int a,b;
    while(T--){
        cin >> a >> b;
        cout << "You get " << (a/b) << " piece(s) and your dad gets " << (a%b) << " piece(s)." << endl;
    }
    return 0;
}