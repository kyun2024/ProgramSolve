#include <iostream>

using namespace std;

int q[]={3,6,9,12,18,21,24,27};

int main(){
    int n;
    cin >> n;
    if(n%5==0){
        cout << n/5 << endl;
        return 0;
    }
    for(auto x:q){
        if(n-x>=0 && (n-x)%5==0){
            cout << (n-x)/5+x/3 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}