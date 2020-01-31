#include <iostream>

using namespace std;

int main(){
    int a[7];
    int i;
    int s=0;
    int m=987654321;
    for(i=0;i<7;i++){
        cin >>a[i];
        if(a[i]%2==1){
            if(a[i]<m){
                m=a[i];
            }
            s += a[i];
        }
    }
    if(s==0)cout << -1 << endl;
    else cout << s << endl << m << endl;
    return 0;
}
