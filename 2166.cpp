#include <iostream>

using namespace std;

int main(){
    long long summa=0;
    int n;
    int i;
    long long sx,sy,tx,ty,nx,ny;
    cin >> n;
    cin >> sx >> sy;
    cin >> tx >> ty;
    for(i=3;i<=n;i++){
        cin >> nx >> ny;
        summa += (sx*ny+nx*ty+tx*sy - (sx*ty+nx*sy+tx*ny));
        tx = nx;
        ty = ny;
    }
    if(summa<0)summa *= -1;
    if(summa%2==0){
        cout << summa / 2 << ".0" << endl;
    }
    else cout << summa /2 << ".5" << endl;
    return 0;
}