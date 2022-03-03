#include <string>
#include <iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    str += ",";
    int s=0,t=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==','){
            s += t;
            t = 0;
        }
        else{
            t = 10*t + (str[i]-'0');
        }
    }
    cout << s << endl;
    return 0;
}