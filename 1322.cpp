#include <iostream>

using namespace std;

int main(){
    unsigned long long x,y,k;
    cin >> x >> k;
    y = x;
    for(int i=0;i<64 && k>0;i++){
        if((x&(1ULL<<i))==0){
            if(k%2){
                y|=(1ULL<<i);
            }
            k/=2;
        }
    }    
    cout << y-x << endl;
    return 0;
}