#include <iostream>

using namespace std;

int m[100001]={0,1,1,2,2,1,2,1,};

int main(){
    int i;
    for(i=8;i<=100000;i++){
        m[i]=min(min(m[i-1],m[i-2]),min(m[i-5],m[i-7]))+1;
    }
    cin >> i;
    cout << m[i] << endl;
    return 0;
}