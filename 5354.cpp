#include <iostream>

using namespace std;

int main(){
    int T;
    int n,i,j;
    cin >> T;
    while(T--){
        cin >> n;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i==1||j==1||i==n||j==n)cout << "#";
                else cout << "J";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}