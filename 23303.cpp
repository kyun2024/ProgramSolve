#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    regex re("(D|d)2");
    string str;
    getline(cin,str);
    if(regex_search(str,re)){
        cout << "D2" << endl;
    }
    else{
        cout << "unrated" << endl;
    }
    return 0;
}