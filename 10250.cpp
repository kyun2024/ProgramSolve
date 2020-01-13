#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int t;
    int h,w,n;
    cin >> t;
    while(t-->0){
        cin >> h >> w >> n;
        cout << (n-1)%h+1 << setw(2) << setfill('0') << (n-1)/h+1 << endl;
    }
    return 0;
}