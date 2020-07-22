#include <iostream>
#include <string>

using namespace std;

int main(){
    int a1[26]={0,},a2[26]={0,},res=0;
    string str1,str2;
    cin >> str1 >> str2;
    for(int i=0;i<str1.length();i++){
        a1[str1[i]-'a']++;
    }
    for(int i=0;i<str2.length();i++){
        a2[str2[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        res += abs(a1[i] - a2[i]);
    }
    cout << res << endl;
    return 0;
}