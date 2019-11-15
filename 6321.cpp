#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin.get();
    for(int i=0;i<n;i++){
        getline(cin,s);
        for(auto& x: s){
            x = (x+1-'A')%26+'A';
        }
        cout << "String #" << i+1 << endl << s << endl << endl;
    }
    return 0;
}