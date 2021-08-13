#include <iostream>

using namespace std;

unsigned long long fct[20];

int main(){
    unsigned long long n;
    long long i;
    fct[0]=1;
    for(i=1;i<=19;i++){
        fct[i]=i*fct[i-1];
    }
    cin >> n;
    if(n==0){
        cout << "NO" << endl;
        return 0;
    }
    for(i=19;i>=0;i--){
        if(n>=fct[i])n-=fct[i];
    }

    cout << (n==0?"YES":"NO") << endl;
    return 0;
}