#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n=0,i;
    cin >> str;
    for(i=0;i<str.length();n++){
        if(str[i]=='c'){
            if(str.length()-i>=2 && (str[i+1]=='=' || str[i+1]=='-')){
                i+=2;
            }
            else{
                i+=1;
            }
        }
        else if(str[i]=='d'){
            if(str.length()-i>=3 && str.substr(i,3) == "dz="){
                i+=3;
            }
            else if(str.length()-i>=2 && str.substr(i,2) == "d-"){
                i+=2;
            }
            else{
                i+=1;
            }
        }
        else if(str[i]=='l'||str[i]=='n'){
            if(str.length()-i>=2 && str[i+1]=='j'){
                i+=2;
            }
            else{
                i+=1;
            }
        }
        else if(str[i]=='s' || str[i]=='z'){
            if(str.length()-i>=2 && str[i+1]=='='){
                i+=2;
            }
            else{
                i+=1;
            }
        }
        else{
            i+=1;
        }
    }
    cout << n << endl;
    return 0;
}