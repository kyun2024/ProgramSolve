#include <iostream>
#include <array>
#include <numeric>

using namespace std;

int main(){
    array<int,5> a;
    for(auto &x: a){
        cin >> x;
    }
    cout << accumulate(a.begin(),a.end(),0) << endl;
    return 0;
}