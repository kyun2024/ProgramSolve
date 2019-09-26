#include <iostream>
using namespace std;

int main(){
    int N{};
    cin >> N;
    if(N>=90)cout<<"A\n";
    else if(N>=80)cout<<"B\n";
    else if(N>=70)cout<<"C\n";
    else if(N>=60)cout<<"D\n";
    else cout<<"F\n";
    return 0;
}