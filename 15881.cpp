#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.get();
    string str;
    cin >> str;
    int res=0;
    for(int i=0;i<n-3;i++){
        if(str.substr(i,4)=="pPAp"){
            res++;
            i+=3;
        }
    }
    cout << res << endl;
    return 0;
}