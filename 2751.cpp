#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

array<int,2000001> A;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,a;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a;
        A[a+1e6] = 1;
    }
    for(int i=0;i<2*1e6+1;i++){
        if(A[i])cout << fixed << setprecision(0) << (i-1e6) << "\n";
    }
    return 0;
}