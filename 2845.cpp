#include <iostream>
#include <array>

using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    array<int,5> a;
    for(auto &x : a){
        cin >> x;
    }
    for(auto &x : a){
        cout << x - n*t << " ";
    }
    return 0;
}