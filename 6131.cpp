#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a,b,res=0;
    for(a=1;a<=500;a++){
        for(b=1;b<=a;b++){
            if(a*a-b*b == n)res++;
        }
    }
    cout << res << endl;
    return 0;
}