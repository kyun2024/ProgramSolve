#include <iostream>

using namespace std;

int main(){
    int a[3],b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    if((a[0]*3+a[1]*2+a[2])>(b[0]*3+b[1]*2+b[2])){
        cout << "A" << endl;
    }
    else if((a[0]*3+a[1]*2+a[2])<(b[0]*3+b[1]*2+b[2])){
        cout << "B" << endl;
    }
    else{
        cout << "T" << endl;
    }
    return 0;
}