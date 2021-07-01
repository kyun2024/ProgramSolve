#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int c{},i,j;
    for(i=1;;i++){
        for(j=1;j<=i;j++){
            c++;
            if(c==n){
                cout << (i-j+1) << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}