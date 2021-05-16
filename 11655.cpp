#include <iostream>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    for(auto c : str){
        if('A'<=c && c <='Z'){
            cout << static_cast<char>((c-'A'+13)%26+'A');
        }
        else if('a'<=c && c<='z'){
            cout << static_cast<char>((c-'a'+13)%26+'a');
        }
        else cout << c;
    }
    cout << endl;
    return 0;
}