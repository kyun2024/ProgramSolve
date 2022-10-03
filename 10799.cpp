#include <iostream>
#include <string>

using namespace std;

int main(){
    long long c{},r{};
    string str;
    cin >> str;
    
    int i;
    for(i=0;i<str.length();i++){
        if(str[i]=='('){
            c++;
        }
        else{
            if(str[i-1]==')')
            {
                r++;
                c--;
            }
            else
            {
                r += --c;
            }
        }
    }
    cout << r << endl;
    return 0;
}