#include <iostream>

using namespace std;

int main(){
    int sa,sb;
    sa=sb=100;
    int n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a>b)sb-=a;
        if(a<b)sa-=b;
    }
    cout <<sa << endl << sb << endl;
    return 0;
}