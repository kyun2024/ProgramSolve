#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    array<int,3> A;
    for(auto &x : A){
        cin >> x;
    }
    sort(A.begin(),A.end());
    cout << A[1] << endl;
    return 0;
}