#include <iostream>

using namespace std;

int main(){
    int a,b,c,t;
    int d[10]={0};
    cin >> a >> b >> c;
    t = a*b*c;
    while(t>0){
        d[t%10]+=1;
        t/=10;
    }
    for(int i=0;i<10;i++){
        cout << d[i] << endl;
    }
    return 0;
}