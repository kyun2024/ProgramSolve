#include <iostream>

using namespace std;

int main(){
    double r1,s1,p1,r2,s2,p2,r;
    int n;
    cin >> n;
    while(n--){
        cin >> r1 >> s1 >> p1;
        cin >> r2 >> s2 >> p2;
        r = r1*s2+s1*p2+p1*r2-(r2*s1+s2*p1+p2*r1);
        if(r>0)cout << "ADAM" << endl;
        else if(r<0)cout << "GOSIA" << endl;
        else cout << "=" << endl;
    }
    return 0;
}