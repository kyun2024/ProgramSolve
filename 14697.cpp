#include <iostream>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int i,j,k;
    for(i=0;a*i<=d;i++){
        for(j=0;a*i+b*j<=d;j++){
            for(k=0;a*i+b*j+c*k<=d;k++){
                if(a*i+b*j+c*k == d){
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}