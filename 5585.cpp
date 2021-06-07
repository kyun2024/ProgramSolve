#include <iostream>

using namespace std;

int main(){
    int n,c=0;
    cin >> n;
    n = 1000-n;
    while(n>=500){c++;n-=500;}
    while(n>=100){c++;n-=100;}
    while(n>=50){c++;n-=50;}
    while(n>=10){c++;n-=10;}
    while(n>=5){c++;n-=5;}
    while(n>=1){c++;n-=1;}
    cout << c << endl;
    return 0;
}