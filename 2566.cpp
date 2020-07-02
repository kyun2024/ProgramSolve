#include <iostream>

using namespace std;

const int n = 9;

int main(){
    int r,c;
    int a,i,m=0;
    for(i=0;i<n*n;i++){
        cin >> a;
        if(m<a){
            m=a;
            r=i/n;
            c=i%n;
        }
    }
    cout << m << endl;
    cout << r + 1 << " " << c + 1 << endl;
}   