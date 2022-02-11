#include <iostream>

using namespace std;

int main(){
    int n;
    int i,j;
    
    cin >> n;
    for(j=0;j<n;j++){for(i=0;i<n*5;i++)cout << "@"; cout << endl;}
    for(j=0;j<n;j++){for(i=0;i<n;i++)cout << "@"; cout << endl;};
    for(j=0;j<n;j++){for(i=0;i<n*5;i++)cout << "@"; cout << endl;};
    for(j=0;j<n;j++){for(i=0;i<n;i++)cout << "@"; cout << endl;};
    for(j=0;j<n;j++){for(i=0;i<n*5;i++)cout << "@"; cout << endl;}
    return 0;
}