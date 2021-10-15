#include <iostream>

using namespace std;

int memo[2001];

int main(){
    int *m = memo+1000;
    int n,i;
    cin >> n;
    while(n--){
        cin >> i;
        m[i]=1;
    }
    for(i=-1000;i<=1000;i++){
        if(m[i])cout << i << " ";
    }
    cout << endl;
    return 0;
}