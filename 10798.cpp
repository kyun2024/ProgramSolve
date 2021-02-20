#include <iostream>
#include <string>

using namespace std;

string s[5];

int main(){
    int i,j;
    for(i=0;i<5;i++){
        cin >> s[i];
    }
    for(j=0;j<15;j++){
        for(i=0;i<5;i++){
            if(j<s[i].length()){
                cout << s[i][j];
            }
        }
    }
    cout << endl;
    return 0;
}