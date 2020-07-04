#include <iostream>

using namespace std;

int main(){
    int a,s,m{},i{},k,t;
    for(k=1;k<=5;k++){
        s = 0;
        for(t=1;t<=4;t++){
            cin >> a;
            s += a;
        }
        if(s>m){
            m=s;
            i=k;
        }
    }
    cout << i << " " << m << endl;
    return 0;
}