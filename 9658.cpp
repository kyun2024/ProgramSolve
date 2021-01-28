#include <iostream>

using namespace std;

int m[1001];

int main(){
    int i;
    m[0]=0;
    for(i=1;i<=1000;i++){
        if(m[i-1]==1 || i-3>=0 && m[i-3]==1 || i-4>=0 && m[i-4]==1){
            
        }
        else{
            m[i]=1;
        }
    }
    cin >> i;
    if(m[i]==0){
        cout << "SK" << endl;
    }
    else cout << "CY" << endl;
    return 0;
}