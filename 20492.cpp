#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int N;
    cin >> N;
    cout << fixed << setprecision(0) << N*0.78 << endl;
    cout << (N-0.2*N*0.22) << endl;
    return 0;
}