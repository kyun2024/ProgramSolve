#include <iostream>

using namespace std;

int main(){
    int i,c;
    int a[42]={0};
    for(i=0;i<10;i++){
        cin >> c;
        a[c%42]++;
    }
    c=0;
    for(i=0;i<42;i++){
        c += a[i]>0;
    }
    cout << c << endl;
    return 0;
}