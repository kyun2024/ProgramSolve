#include <iostream>

using namespace std;

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=n;i>=1;i--){
        for(j=0;j<n-i;j++)cout << " ";
        for(j=1;j<=2*i-1;j++)cout << "*";
        cout << endl;
    }
    for(i=2;i<=n;i++){
        for(j=0;j<n-i;j++)cout << " ";
        for(j=1;j<=2*i-1;j++)cout << "*";
        cout << endl;
    }
    return 0;
}