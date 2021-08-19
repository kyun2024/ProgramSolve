#include <iostream>

using namespace std;

int main(){
    int t;
    int n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << "Pairs for " << n << ":";
        for(int i=1; i<=(n-1)/2;i++){
            if(i!=1)cout << ",";
            cout << " " << i << " " << n-i;
        }
        cout << endl;


    }
    return 0;
}
