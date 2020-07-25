#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

int a[100];
int main(){
    int n;
    int i,g;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=1;i<n;i++){
        g = gcd(a[0],a[i]);
        cout << a[0]/g << "/" << a[i]/g << endl;
    }
    return 0;
}