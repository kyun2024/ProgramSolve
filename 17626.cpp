#include <iostream>

using namespace std;

int m[50001];

int main(){
    int i,j;
    for(i=1;i<=50000;i++){
        for(j=1;j*j<=i;j++){
            if(i-j*j==0){
                m[i]=0;
                break;
            }
            if(m[i]==0){
                m[i]=m[i-j*j];
            }
            else{
                m[i]=min(m[i],m[i-j*j]);
            }
        }
        m[i]++;
    }
    cin >> i;
    cout << m[i] << endl;
    return 0;
}