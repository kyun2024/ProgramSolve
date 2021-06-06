#include <iostream>
#include <string>

using namespace std;

int ac[26];

int main(){
    string str;
    cin >> str;
    for(auto c : str){
        ac[c-'a']++;
    }
    for(auto c : ac)cout << c << " ";
    cout << endl;
    return 0;
}