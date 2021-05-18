#include <iostream>

using namespace std;

int memo[11];

int main(){
    int n;
    int i;
    for(i=2;i<=10;i++){
        memo[i]=memo[i/2]+memo[(i+1)/2]+(i/2)*((i+1)/2);
    }
    cin >> n;
    cout << memo[n] << endl;
    return 0;
}