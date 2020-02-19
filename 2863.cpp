#include <iostream>

using namespace std;

int main(){
    double a,b,c,d;
    double m=0;
    int res=0;
    cin >> a >> b >> c >> d;
    m=a/c+b/d;
    if(m<c/d+a/b){
        m=c/d+a/b;
        res=1;
    }
    if(m<d/b+c/a){
        m=d/b+c/a;
        res=2;
    }
    if(m<b/a + d/c){
        m=b/a + d/c;
        res=3;
    }
    cout << res << endl;
    return 0;
}