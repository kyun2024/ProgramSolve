#include <iostream>

using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    cout << (x*y>0)+!(x>0&&y>0)+(x*y<0)+(y<0)+(x>0&&y<0) << endl;
    return 0;
}