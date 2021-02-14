#include <iostream>

using namespace std;

int main(){
    char c;
    while(true){
        c=cin.get();
        if(cin.eof())break;
        cout << c;
    }
    return 0;
}