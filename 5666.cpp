#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double x,y;
    while(true){
        cin >> x >> y;
        if(cin.eof())break;
        cout << setprecision(2) << fixed << x/y << endl;
    }
    return 0;
}