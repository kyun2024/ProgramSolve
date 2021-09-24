#include <iostream>

using namespace std;

int main(){
    int a,b;
    int cc,c,t;
    while(true){
        cin >> a >> b;
        if(a==0 && b==0)break;
        cc = c = 0;
        while(a>0||b>0){
            t = a%10+b%10+c;
            c = t/10;
            cc += c;
            a/=10;
            b/=10;
        }
        cout << cc << endl;
    }
}