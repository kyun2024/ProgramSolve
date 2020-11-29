#include <iostream>

using namespace std;

int main(){
    int res=0,n;
    while(!cin.eof()){
        cin >> n;
        if(cin.eof())break;
        if(n>0)res++;
    }
    cout << res << endl;
    return 0;
}