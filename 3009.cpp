#include <iostream>

using namespace std;

int unique(int a,int b,int c){
    if(a==b)return c;
    if(b==c)return a;
    if(a==c)return b;
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << unique(x1,x2,x3) << " " << unique(y1,y2,y3) << endl;
    return 0;
}