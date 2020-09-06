#include <iostream>

using namespace std;

int main(){
    int n,i,j;
    cin >> n;
    if(n==1){
        cout << "*" << endl;
        return 0;
    }
    for(i=1;i<=2*n;i++){
        for(j=1;j<=n;j++){
            if((i+j)%2==0){
                cout << "*";               
            }            
            else cout << " ";
        }
        cout << '\n';
    }
    return 0;
}