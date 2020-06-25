#include <iostream>

using namespace std;

int main(){
    int s;
    int i,a;
    cin >> s;
    for(i=0;i<9;i++){
        cin >> a;
        s -= a;
    }
    cout << s << endl;
}