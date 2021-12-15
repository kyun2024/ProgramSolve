#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    if(m+60<n){
        cout << (m+60)*1500 + (n-m-60)*3000 << endl;
    }
    else{
        cout << n*1500 << endl;
    }
    return 0;
}