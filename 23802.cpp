#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n*5;j++)cout << "@";
        cout << endl;
    }
    for(i=0;i<n*4;i++){
        for(j=0;j<n;j++)cout << "@";
        cout << endl;
    }
    return 0;
}