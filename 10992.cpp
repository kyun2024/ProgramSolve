#include <iostream>

using namespace std;

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=1;i<n;i++){
        for(j=1;j<=n-i;j++)cout << " ";
        cout << "*";
        if(i>1){
            for(j=1;j<=2*(i-1)-1;j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    for(j=1;j<=2*(n-1)+1;j++){
        cout << "*";
    }
    cout << endl;
    return 0;
}