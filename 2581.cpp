#include <iostream>

using namespace std;

bool prime[10001];

int main(){
    int i,j;
    for(i=2;i<=10000;i++){
        if(prime[i])continue;
        for(j=i*2;j<=10000;j+=i){
            prime[j]=true;
        }
    }
    for(i=2;i<=10000;i++){
        prime[i]=!prime[i];
    }
    int m,n,s=0,min_val=0;
    cin >> m >> n;
    for(i=m;i<=n;i++){
        if(min_val == 0 && prime[i]){
            min_val = i;
        }
        s += i*prime[i];
    }
    if(min_val == 0){
        cout << -1 << endl;
    }
    else{
        cout << s << endl << min_val << endl;
    }
    return 0;
}