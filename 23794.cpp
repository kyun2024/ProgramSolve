#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i,j;
    for(i=0;i<n+2;i++)cout << "@"; cout << '\n';
    for(j=0;j<n;j++){cout << "@"; for(i=0;i<n;i++)cout << " "; cout << "@\n";}
    for(i=0;i<n+2;i++)cout << "@"; cout << '\n';
    return 0;
}