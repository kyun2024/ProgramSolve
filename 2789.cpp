#include <iostream>
#include <string>

using namespace std;

int main(){
    const char *filter_list = "CAMBRIDGE", *c;
    string str;
    cin >> str;
    for(auto c1 : str){
        for(c = filter_list;*c!=0;c++){
            if(*c==c1)break;
        }
        if(!*c)cout << c1;
    }
    cout << endl;
    return 0;
}