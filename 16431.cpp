#include <iostream>

using namespace std;

int main(){
    int x,y;
    int ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by >> x >> y;
    if(abs(bx-x)+abs(by-y)>max(abs(ax-x),abs(ay-y))){
        cout << "bessie" << endl;
    }
    else if(abs(bx-x)+abs(by-y)<max(abs(ax-x),abs(ay-y)))
    {
        cout << "daisy" << endl;
    }
    else{
        cout << "tie" << endl;
    }
    return 0;
}