#include <iostream>

using namespace std;

int m[2000001];

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    int* a=m+1000000;
    int i,t;
    cin >> n;
    while(n--){
        cin >> t;
        a[t]++;
    }
    i = 2000000;
    do{
        while(m[i]--)cout << i-1000000 << '\n';
    }while(i--);
    return 0;
}