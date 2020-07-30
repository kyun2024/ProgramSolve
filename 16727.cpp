#include <iostream>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a+d == b+c){
        if(b == d){
            cout << "Penalty" << endl;
        }
        else if(b>d){
            cout << "Esteghlal" << endl;
        }
        else{
            cout << "Persepolis" << endl;
        }
    }
    else if(a+d>b+c){
        cout << "Persepolis" << endl;
    }
    else{
        cout << "Esteghlal" << endl;
    }
    return 0;
}