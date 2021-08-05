#include <iostream>

using namespace std;

int main(){
    int n,s{};
    while(true){
        cin >> n;
        if(cin.eof())break;
        s += n;
    }
    cout << s << endl;
    return 0;
}
