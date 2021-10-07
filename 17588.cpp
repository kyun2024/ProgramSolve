#include <iostream>

using namespace std;

int main(){
    int n,a,c;
    c = 1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        while(c<a){
            cout << c << endl;
            c++;
        }
        c++;
    }
    if(a==n){
        cout << "good job" << endl;
    }
    return 0;
}