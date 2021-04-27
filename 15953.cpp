#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int a,b,r;
    while(T--){
        r=0;
        cin >> a >> b;
        if(a==0){

        }
        else if(a<=1){
            r += 500;
        }
        else if(a<=1+2){
            r += 300;
        }
        else if(a<=1+2+3){
            r += 200;
        }
        else if(a<=1+2+3+4){
            r += 50;
        }
        else if(a<=1+2+3+4+5){
            r += 30;
        }
        else if(a<=1+2+3+4+5+6){
            r += 10;
        }

        if(b==0){

        }
        else if(b<=1){
            r += 512;
        }
        else if(b<=1+2){
            r += 256;
        }
        else if(b<=1+2+4){
            r += 128;
        }
        else if(b<=1+2+4+8){
            r += 64;
        }
        else if(b<=1+2+4+8+16){
            r += 32;
        }
        
        cout << r << (r==0?"":"0000") << endl;
    }
    return 0;
}