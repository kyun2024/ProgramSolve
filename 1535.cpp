#include <iostream>

using namespace std;

int n;
int mhp[21],mhappy[21];

int maxHappy(int happy,int hp,int c){
    if(hp<=0)return -1;
    if(c>n){
        return happy;
    }
    return max(maxHappy(happy+mhappy[c],hp-mhp[c],c+1),maxHappy(happy,hp,c+1));
}

int main(){
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> mhp[i];
    }
    for(i=1;i<=n;i++){
        cin >> mhappy[i];
    }
    cout << maxHappy(0,100,1) << endl;
    return 0;
}