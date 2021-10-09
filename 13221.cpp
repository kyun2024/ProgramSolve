#include <iostream>

using namespace std;

int main(){
    int x,y;
    int d=201;
    int n;
    int a,b,sa,sb;
    cin >> x >> y;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(abs(x-a)+abs(y-b)<d)
        {
            d = abs(x-a)+abs(y-b);
            sa = a;
            sb = b;
        }
    }
    cout << sa << " " << sb << endl;
    return 0;
}