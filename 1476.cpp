#include <iostream>

using namespace std;

int main(){
    int y;
    int a,b,c;
    cin >> a >> b >> c;
    for(y=0;y<7980;y++){
        if(y%15==a-1 && y%28 == b-1 && y%19 == c-1){
            cout << y+1 << endl;
            break;
        }
    }
    return 0;
}