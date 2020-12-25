#include <iostream>

using namespace std;

int m[100001];

int main(){
    m[2]=1;
    m[4]=2;
    m[5]=1;
    int i;
    for(i=6;i<=100000;i++){
        if(m[i-2]!=0){
            m[i]=m[i-2];
        }
        if(m[i-5]!=0){
            m[i]=min(m[i-5],m[i]);
        }
        if(m[i]!=0)m[i]+=1;
    }
    cin >> i;
    if(m[i]!=0){
        cout << m[i] << endl;
    }
    else cout << -1 << endl;
    return 0;
}