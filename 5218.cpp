#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    string str,str2;
    cin >> T;
    while(T--){
        cin >> str >> str2;
        cout << "Distances: ";
        for(int i=0;i<str.length();i++){
            cout << ((-str[i]+str2[i]+26)%26);
            if(i<str.length()-1)cout << " ";
            else cout << endl;
        }
    }
    return 0;
}