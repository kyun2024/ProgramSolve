#include <iostream>

using namespace std;

int a[31];
int s[31];

int main(){
    int n,i;
    a[1]=1;a[2]=3;
    s[0]=1;s[1]=1;s[2]=3;s[3]=1;
    for(i=3;i<=30;i++){
        a[i]=a[i-1]+2*a[i-2];
    }
    for(i=4;i<=30;i++){
        s[i]=s[i-2]+2*s[i-4];
    }
    cin >> n;
    cout << (a[n]-s[n])/2+s[n] << endl;
    return 0;
}