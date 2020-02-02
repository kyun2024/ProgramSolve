#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n=0,i,k=1;
    cin >> str;
    for(i=str.length()-1;i>=0;i--){
        if('0' <= str[i] && str[i] <='9'){
            n += k*(str[i]-'0');
        }
        else{
            n += k*(str[i]-'A'+10);
        }
        k*=16;
    }
    cout << n << endl;
    return 0;
}