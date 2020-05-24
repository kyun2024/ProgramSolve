#include <iostream>

using namespace std;

int main(){
    int n,k=1,s=0,i,b;
    cin >> n;
    for(k=1;n>=10*k;k*=10);
    n=n-k+1;
    for(i=1,b=1;b<k;i++,b*=10){
        s += 9*i*b;
    }
    s += n*i;
    cout << s << endl;
}