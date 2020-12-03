#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int i,r=0;
    cin >> str;
    if(str=="0"){
        cout << str << endl;
        return 0;
    }
    for(i=0;i<str.length()%3;i++){
        r = 2*r + (str[i]-'0');
    }
    if(r!=0)cout << r;
    for(i=str.length()%3;i<str.length();i+=3){
        cout << 4*(str[i]-'0')+2*(str[i+1]-'0')+(str[i+2]-'0');
    }
    cout << endl;
    return 0;
}