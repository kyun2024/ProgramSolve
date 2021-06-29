#include <iostream>

using namespace std;

int main(){
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int res=0;
    if(a<0 && b==0){
        cout << -a*c << endl;
    }
    else if(a<0 && b>0){
        cout << -a*c+d+b*e << endl;
    }
    else if(a>0){
        cout << (b-a)*e << endl;
    }
    return 0;
}