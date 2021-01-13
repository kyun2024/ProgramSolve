#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1,s2,res="";
    cin >> s1 >> s2;
    string::iterator it;
    for(it=s1.begin();*it=='0';it++);
    s1 = string(it,s1.end());
    for(it=s2.begin();*it=='0';it++);
    s2 = string(it,s2.end());
    
    s1 = string(s1.rbegin(),s1.rend());
    s2 = string(s2.rbegin(),s2.rend());
    int i,s,c=0;
    for(i=0;i<min(s1.length(),s2.length());i++){
        s = s1[i]+s2[i]-2*'0'+c;
        c = s/2;
        s = s%2;
        res += (s+'0');
    }
    for(;i<s1.length();i++){
        s = s1[i]-'0'+c;
        c = s/2;
        s = s%2;
        res += (s+'0');    
    }
    for(;i<s2.length();i++){
        s = s2[i]-'0'+c;
        c = s/2;
        s = s%2;
        res += (s+'0');    
    }
    if(c!=0){
        res += (c+'0');
    }
    if(res.length()==0){
        res = string("0");
    }
    res = string(res.rbegin(),res.rend());
    cout << res << endl;
    return 0;
}