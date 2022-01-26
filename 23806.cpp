#include <iostream>

char map[][6]={
    "@@@@@",
    "@   @",
    "@   @",
    "@   @",
    "@@@@@"
};

using namespace std;

int main(){
    int n;
    cin >> n;
    int i,j;
    for(i=0;i<n*5;i++){
        for(j=0;j<n*5;j++){
            cout << map[i/n][j/n];
        }
        cout << endl;
    }
    return 0;
}