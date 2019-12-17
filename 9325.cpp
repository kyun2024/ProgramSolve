#include <iostream>

using namespace std;

int main(){
    int n,m,res,count,mulv;
    cin >> n;
    while(--n >= 0){
        cin >> res;
        cin >> m;
        while(--m >=0){
            cin >> count >> mulv;
            res += count*mulv;
        }
        cout << res << endl;
    }
    return 0;
}