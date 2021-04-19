#include <iostream>

using namespace std;

int main(){
    long long a,b,x,y,q;
    cin >> a >> b >> x >> y;
    if(a>b)swap(a,b);
    x = abs(x);
    if(x==0){
        if(a==b){
            cout << a << endl;
        }
        cout << "Unknwon Number" << endl;
        return 0;
    }
    if(y<0 || y>=x){
        cout << "Unknwon Number" << endl;
        return 0;
    }
    long long n = a+(y-((x+a)%x)+x)%x;
    if(n>b || n+x<=b){
        cout << "Unknwon Number" << endl;
    }
    else{
        cout << n << endl;
    }
    
    return 0;
}