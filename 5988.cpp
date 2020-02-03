#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int n;
    cin >> n;
    while(--n>=0){
        cin >> s;
        if((s.back()-'0')%2==0){
            cout << "even" << endl;
        }
        else{
            cout << "odd" << endl;
        }
    }
    return 0;
}