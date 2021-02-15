#include <iostream>
#include <string>

using namespace std;

int main(){
    int res=0;
    string str;
    cin >> str;
    if(str.length()>2 && str[1]=='x'){ //hexademical
        str = str.substr(2);
        for(const auto& x : str){
            if(x>='a'){
                res = 16*res + (x-'a'+10);    
            }
            else res = 16*res + (x-'0');
        }
    }
    else if(str.length()>1 && str[0]=='0'){ //octal
        for(const auto& x : str){
            res = 8*res + (x-'0');
        }
    }
    else{
        for(const auto& x : str){
            res = 10*res + (x-'0');
        }
    }
    cout << res << endl;
    return 0;
}