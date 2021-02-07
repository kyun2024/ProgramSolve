#include <iostream>

using namespace std;

int main(){
    int n,i;
    int a,b,c;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        if(a+b<=c || a+c<=b || b+c<=a){
            cout << "invalid!\n";
        }
        else if(a==b && b==c){
            cout << "equilateral\n";
        }
        else if(a==b || b==c || a==c){
            cout << "isosceles\n";
        }
        else{
            cout << "scalene\n";
        }
    }
    return 0;
}