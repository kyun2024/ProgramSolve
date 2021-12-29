#include <iostream>

using namespace std;

int m[21];

int main(){
    int n=10;
    int a,b;
    int i;
    for(i=1;i<=20;i++)m[i]=i;
    while(n--){
        cin >> a >> b;
        for(i=0;i<(b-a+1)/2;i++){
            swap(m[a+i],m[b-i]);
        }
    }
    for(i=1;i<=20;i++)cout << m[i] << " ";
    cout << endl;
    return 0;
}