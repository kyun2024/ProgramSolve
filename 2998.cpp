#include <iostream>
#include <string>

using namespace std;

int main(){
    string str,res;
    cin >> str;
    while(str.length()%3!=0){
        str = '0'+str;
    }
    for(int i=0;i<str.length();i+=3){
        res += ((str[i]-'0')*4+(str[i+1]-'0')*2+(str[i+2]-'0')+'0');
    }
    cout << res << endl;
    return 0;
}