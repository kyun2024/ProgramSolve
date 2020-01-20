#include <iostream>

using namespace std;

int main(){
    int *bmax,*bmin,*fmax,*fmin,*sp;
    int am[3]{0,},an[3]={0, },bm[3]{0,},bn[3]={0,},ina[3];
    bmax = bm;
    bmin = bn;
    fmax = am;
    fmin = an;
    int n;
    cin >> n;
    while(--n>=0){
        cin >> ina[0] >> ina[1] >> ina[2];
        //maximize
        fmax[0] = max(bmax[0],bmax[1])+ina[0];
        fmax[1] = max(max(bmax[0],bmax[1]),bmax[2])+ina[1];
        fmax[2] = max(bmax[1],bmax[2])+ina[2];
        //minimize
        fmin[0] = min(bmin[0],bmin[1])+ina[0];
        fmin[1] = min(min(bmin[0],bmin[1]),bmin[2])+ina[1];
        fmin[2] = min(bmin[1],bmin[2])+ina[2];
        //swap
        sp = bmax;
        bmax = fmax;
        fmax = sp;
        sp = bmin;
        bmin = fmin;
        fmin = sp;
    }
    cout << max(max(bmax[0],bmax[1]),bmax[2]) << " " << min(min(bmin[0],bmin[1]),bmin[2]) << endl;
    return 0;
}