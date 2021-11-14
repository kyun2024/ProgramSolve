#include <iostream>
#include <string>

using namespace std;

int main(){
    int i;
    string s1,s2,s{},s_t;
    cin >> s1 >> s2;
    for(i=0;i<8;i++){
        s += s1[i];
        s += s2[i];
    }
    while(s.length()>2){
        s_t = string();
        for(i=0;i<s.length()-1;i++){
            s_t += (char)((((s[i]&15)+(s[i+1]&15))%10)+'0');
        }
        s = s_t;
    }
    cout << s << endl;
    return 0;
}