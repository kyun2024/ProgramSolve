#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int res;
    while(!(res = 0)){
        getline(cin,str);
        if(str=="#")break;
        for(auto c:str){
            switch(c){
                case 'a':case 'e':case 'i':case 'o':case 'u':
                case 'A':case 'E':case 'I':case 'O':case 'U':
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}