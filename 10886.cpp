#include <iostream>

using namespace std;

int main(){
    int n,s{},a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        s += a;
    }
    if(s>n-s){
        cout << "Junhee is cute!" << endl;
    } 
    else cout << "Junhee is not cute!" << endl;
    return 0;
}