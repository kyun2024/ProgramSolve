#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int a[26]={0,};
    cin >> str;
    for(const auto x:str){
        //cout << x;
        if('A'<= x && x <= 'Z'){
            //cout << int(x-'A') << " ";
            a[x-'A']++;
        }
        else if('a'<=x && x<='z'){
            //cout << int(x-'a') << " ";
            a[x-'a']++;
        }
    }
    //cout << endl;
    int max_count{},max_n{};
    for(int i=0;i<26;i++){
        if(max_count<a[i]){
            max_count = a[i];
        }
    }
    //cout << max_count << endl;
    for(int i=0;i<26;i++){
        if(max_count==a[i]){
            max_n++;
        }
    }
    if(max_n>1){
        cout << '?' << endl;
    }else{
        for(int i=0;i<26;i++){
            if(max_count==a[i]){
                cout << char(i+'A') << endl;
            }
        }
    }
    return 0;
}