#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str; 
    for(auto c:str){
        if('A'<=c && c<='Z'){
            cout << (char)(c-'A'+'a');
        }
        else{
            cout << (char)(c-'a'+'A');
        }
    }
    cout << endl;
    return 0;
}