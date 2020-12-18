#include <iostream>

using namespace std;

int m[11];

int main(){
    int x,y,i;
    cin >> x >> y;
    m[0]=x;
    for(i=1;i<=y;i++){
        m[i]=m[i-1]+m[i-1]/20;
        if(i-3>=0){
            m[i]=max(m[i],m[i-3]+m[i-3]/5);
        }
        if(i-5>=0){
            m[i]=max(m[i],m[i-5]+7*m[i-5]/20);
        }
    }
    cout << m[y] << endl;
    return 0;
}