#include <iostream>

using namespace std;

int m[100];

int main(){
    int n;
    cin >> n;
    int i,k,c=0;
    for(i=0;i<n;i++){
        cin >> m[i];
    }
    cin >> k;
    for(i=0;i<n;i++){
        c += m[i]==k;
    }
    cout << c << endl;
    return 0;
}