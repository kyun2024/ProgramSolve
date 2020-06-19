#include <iostream>

using namespace std;

int main(){
    int n,a,b,c;
    cin >> n >> a >> b;
    while(n--){
        cin >> c;
        if(c*c<=a*a+b*b){
            cout << "DA" << endl;
        }
        else{
            cout << "NE" << endl;
        }
    }
    return 0;
}