#include <iostream>
#include <string>

using namespace std;

int main(){
    int res,i;
    string str;
    while(true){
        res = 1;
        cin >> str;
        if(str==string("0"))break;
        for(const char c: str){
            switch(c){
                case '1':
                    res += 3;
                    break;
                case '0':
                    res += 5;
                    break;
                default:
                    res += 4;
                    break;
            }
        }
        cout << res << endl;
    }
}