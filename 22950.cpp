#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    for(auto i = s.rbegin();i!=s.rend() && i-s.rbegin()<k;i++){
        if(*i=='1'){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}