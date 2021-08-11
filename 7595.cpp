#include <iostream>

using namespace std;

int main(){
    int i,j,n;
    while(1){
        cin >> n;
        if(n==0)break;
        for(i=0;i<n;i++){
            for(j=0;j<=i;j++)cout << "*";
            cout << endl;
        }
    }
    return 0;
}