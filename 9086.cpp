#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    while(n--){
        cin >> str;
        cout << *str.begin() << *(str.end()-1) << endl;
    }
    return 0;
}