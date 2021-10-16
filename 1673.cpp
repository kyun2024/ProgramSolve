#include <iostream>

using namespace std;

int main(){
    int n,k,res,c;
    while(true){
        cin >> n >> k;
        if(cin.eof())break;
        res = c = 0;
        while(n>0){
            res += n;
            c += n;
            n = c/k;
            c = c%k;
        }
        cout << res << endl;
    }
    return 0;
}