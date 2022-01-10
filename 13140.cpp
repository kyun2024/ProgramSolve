#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    int h,e,l,o,w,d,r;

    cin >> n;
    for(h=1;h<=9;h++){
        for(w=1;w<=9;w++){
            if(w==h)continue;
            for(e=0;e<=9;e++){
                if(e==w || e==h)continue;
                for(o=0;o<=9;o++){
                    if(o==e || o==w || o==h)continue;
                    for(l=0;l<=9;l++){
                        if(l==o || l==e || l==w || l == h)continue;
                        for(r=0;r<=9;r++){
                            if(r==l || r==o || r==e || r==w || r==h)continue;
                            for(d=0;d<=9;d++){
                                if(d==r || d==l || d==o || d==e || d==w || d==h)continue;
                                if(10000*h+1000*e+110*l+o + 10000*w + 1000*o + 100*r + 10*l + d == n){
                                    cout << "  " << h << e << l << l << o << endl;
                                    cout << "+ " << w << o << r << l << d << endl;
                                    cout << "-------" << endl;
                                    cout << setw(7) << right << n << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No Answer" << endl;
    return 0;
}