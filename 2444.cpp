#include <iostream>

using namespace std;

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++)cout << " ";
        for(j=0;j<i*2+1;j++)cout << "*";
        cout << endl;
    }
    for(i=n-2;i>=0;i--){
        for(j=0;j<n-i-1;j++)cout << " ";
        for(j=0;j<i*2+1;j++)cout << "*";
        cout << endl;
    }
    return 0;
}