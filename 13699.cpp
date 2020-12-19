#include <iostream>

using namespace std;

unsigned long long m[36];

int main(){
    m[0]=1;
    int i,j;
    for(i=1;i<=35;i++){
        for(j=0;j<i;j++){
            m[i] += m[j]*m[i-j-1];
        }
    }
    cin >> i;
    cout << m[i] << endl;
    return 0;
}