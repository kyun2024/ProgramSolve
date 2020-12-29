#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int p;
    while(true){
        cin >> str;
        if(str=="#")break;
        p=0;
        for(const auto& c : str){
            if(c=='1')p++;

            if(c=='e'){
                cout << str.substr(0,str.size()-1);
                cout << (p%2==0?0:1) << endl;
            }
            if(c=='o'){
                cout << str.substr(0,str.size()-1);
                cout << (p%2==0?1:0) << endl;
            }
        }
    }
    return 0;
}