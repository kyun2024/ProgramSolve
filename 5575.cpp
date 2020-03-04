#include <iostream>

using namespace std;

int main(){
    int a[6];
    int i,j,t;
    for(i=0;i<3;i++){
        for(j=0;j<6;j++) cin >> a[j];
        t = a[3]*3600+a[4]*60+a[5]-a[0]*3600-a[1]*60-a[2];
        cout << t/3600 << " " << t/60%60 << " " << t%60 << endl;
    }
    return 0;
}