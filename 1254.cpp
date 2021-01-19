#include <iostream>
#include <string>

using namespace std;

int main(){
    int i,j;
    string str;
    cin >> str;
    for(i=0;i<str.length();i++){
        for(j=0;j<=(str.length()-i)/2;j++){
            if(str[j+i]!=str[str.length()-j-1]){
                break;
            }
        }
        if(j>(str.length()-i)/2)break;
    }
    cout << str.length()+i << endl;
    return 0;
}