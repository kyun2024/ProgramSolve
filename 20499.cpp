#include <iostream>

using namespace std;

int main(){
    int k=0,d=0,a=0,b=0;
    char c;
    while(true){
        cin >> c;
        if(cin.eof())break;
        if(c=='/'){
            b++;
        }
        else if(b==0){
            k = 10*k+(c-'0');
        }else if(b==1){
            d = 10*d+(c-'0');
        }
        else{
            a = 10*a+(c-'0');
        }
    }
    if(k+a<d || d==0){
        cout << "hasu\n";
    }
    else{
        cout << "gosu\n";
    }
    return 0;
}