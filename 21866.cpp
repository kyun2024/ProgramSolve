#include <iostream>

using namespace std;

int m[]={100,100,200,200,300,300,400,400,500};

auto main()->int{
    int n,s=0;
    for(int i=0;i<9;i++){
        cin >> n;
        if(n>m[i]){
            cout << "hacker\n";
            return 0;
        }
        s += n;
    }
    if(s>=100)cout << "draw\n";
    else cout << "none\n";
    return 0;
}