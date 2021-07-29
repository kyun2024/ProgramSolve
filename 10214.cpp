#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int i;
    int y,g,ys,gs;
    while(T--){
        ys = gs = 0;
        y = g = 0;
        for(i=0;i<9;i++){
            cin >> y >> g;
            ys += y;
            gs += g;
        }
        if(ys>gs)cout << "Yonsei" << endl;
        else if(ys<gs)cout << "Korea" << endl;
        else cout << "Draw" << endl;
    }
    return 0;
}