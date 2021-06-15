#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    while(true){
        getline(cin,str);
        if(str=="END")break;
        cout << string(str.rbegin(),str.rend()) << endl;
    }
    return 0;
}