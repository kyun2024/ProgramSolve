#include <iostream>
#include <string>

using namespace std;

bool iscpp(string s){
    for(auto c:s){
        if('a'<=c && c<='z' || c=='_'){
            
        }
        else{
            return false;
        }
    }
    return true;
}

bool isjava(string s){
    if('A'<=s.front()&&s.front()<='Z'){
        return false;
    }
    for(auto c:s){
        if('a'<=c && c<='z' || 'A'<=c && c<='Z'){
        }
        else{
            return false;
        }
    }
    return true;
}

string cpp2java(string s){
    string res;
    res += s.front();
    for(int i=1;i<s.length();i++){
        if(s[i]=='_'){
            if(s[i-1]=='_')
                res+='_';
            continue;
        }
        if(s[i-1]=='_'){
            res += (s[i]-'a'+'A');
        }
        else res += s[i];
    }
    if(s.back()=='_')
        res+='_';
    return res;
}

string java2cpp(string s){
    string res;
    res += s.front();
    for(int i=1;i<s.length();i++){
        if('A'<=s[i] && s[i]<='Z'){
            res += '_';
            res += (s[i]-'A'+'a');
        }
        else{
            res += s[i];
        }
    }
    return res;
}

int main(){
    string n;
    cin >> n;
    if(isjava(n) && iscpp(java2cpp(n))){
            cout << java2cpp(n) << endl; 
        
    }
    else if(iscpp(n) && isjava(cpp2java(n))){
        cout << cpp2java(n) << endl;
    }
    else{
        cout << "Error!\n";
    }
    return 0;
}