#include <iostream>

using namespace std;

int memo[1000];

int main(){
    int n,i;
    memo[0]=1;
    for(i=1;i<1000;i++){
        memo[i] = memo[i-1] + (i<<1);
    }
    while(1){
        cin >> n;
        if(!n)break;
        cout << n << " => " << memo[n-1] << endl;
    }
    return 0;
}