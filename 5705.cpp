#include <iostream>

using namespace std;

int memo[41];

int main(){
    int n;
    memo[0]=memo[1]=1;
    for(n=2;n<=40;n++)memo[n]=memo[n-1]+memo[n-2];
    while(1){
        cin >> n;
        if(n==0)break;
        cout << memo[n] << endl;
    }
    return 0;
}