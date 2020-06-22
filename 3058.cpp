#include <iostream>

using namespace std;

int main(){
    int n;
    int i,k,s,a;
    cin >> n;
    while(n--){
        s=0;
        k=100;
        for(i=0;i<7;i++){
            cin >> a;
            if(a%2==0){
                s+=a;
                if(k>a)k=a;
            }
        }
        cout << s << " " << k << endl;
    }
}