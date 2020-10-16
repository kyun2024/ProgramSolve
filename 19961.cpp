#include <iostream>

using namespace std;

int main(){
    int t1,v1,t2,v2,n;
    int t;
    int bt1,bt2,p1,p2;
    cin >> t1 >> v1 >> t2 >> v2 >> n;
    bt1 = 2*t1;
    bt2 = 2*t2;
    p1 = p2 = 0;
    for(int i=1;i<=2000000;i++){
        if(bt1>t1){
            p1 += v1;
        }
        if(bt2>t2){
            p2 += v2;
        }
        if(p1>=n && p2>=n){
            if((n-p1+v1)*v2<(n-p2+v2)*v1){
                cout << "First" << endl;
            }
            else if((n-p1+v1)*v2>(n-p2+v2)*v1){
                cout << "Second" << endl;
            }
            else cout << "Draw" << endl;
            break;
        }
        else if(p1>=n){
            cout << "First" << endl;
            break;
        }
        else if(p2>=n){
            cout << "Second" << endl;
            break;
        }
        bt1--;
        bt2--;
        if(bt1==0)bt1=2*t1;
        if(bt2==0)bt2=2*t2;
    }
}