#include <iostream>
using namespace std;

int main(){
    int a,s=0,i=10;
    for(i=10;i>0;i--){
        cin >> a;
        if(s+a>=100)break; 
        s += a;
    }
    if(i!=0 && abs(100-s-a)<=abs(100-s)){
        cout << s+a << endl;
    }
    else cout << s << endl;
    return 0;
}