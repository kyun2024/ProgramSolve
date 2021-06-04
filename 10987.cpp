#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int cnt=0;
    cin >> str;
    for(auto c : str){
        switch(c){
            case 'a':case 'e':case 'i':case 'o':case 'u':
            cnt++;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}