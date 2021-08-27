#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int n,i;
    while(T--){
        cin >> n;
        for(i=99;i>=0;i--){
            if(n>=i*i+i)break;
        }
        cout << i << endl;
    }
    return 0;
}