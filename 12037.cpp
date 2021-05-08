#include <iostream>

using namespace std;

int m[16];

int main(){
    int i;
    m[0]=m[1]=1;
    for(i=2;i<=15;i++){
        m[i]=m[i-1]+m[i-2];
    }
    int t,T,c,v,l;
    cin >> T;
    for(t=1;t<=T;t++){
        cin >> c >> v >> l;
        cout << "Case #" << t << ": " << m[l] << endl;
    }
    return 0;
}