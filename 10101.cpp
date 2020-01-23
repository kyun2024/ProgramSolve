#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if (a+b+c != 180){
        cout << "Error" << endl;
    }
    else if(a==b && b==c){
        cout << "Equilateral" << endl;
    }
    else if(a==b || b==c || c==a){
        cout << "Isosceles" << endl;
    }
    else{
        cout << "Scalene" << endl;
    }
    return 0;
}