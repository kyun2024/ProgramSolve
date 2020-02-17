#include <iostream>

using namespace std;

int main(){
    int e,f,c;
    int res=0,s=0;
    cin >> e >> f >> c;
    s = e+f;
    while(s>=c){
        res += s/c;
        s = s/c+s%c;
    }
    cout << res << endl;
    return 0;
}