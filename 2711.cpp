#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int a,i;
    string str;
    cin >> n;
    while(n--){
        cin >> a >> str;
        for(i=1;i<=str.length();i++){
            if(i!=a)cout << str[i-1];
        }
        cout << endl;
    }
    return 0;
}