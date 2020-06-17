#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    while(true){
        cin >> a >> b >> c;
        if(a==b && b==c && c==0)break;
        if(max(max(a,b),c)==a && a*a==b*b+c*c || max(max(a,b),c)==b && b*b == a*a + c*c || max(max(a,b),c)==c && c*c==a*a+b*b){
            cout << "right" << endl;
        }
        else{
            cout << "wrong" << endl;
        }
    }
    return 0;
}