#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    int a,b,c;
    cin >> n;
    cin >> a >> b >> c;
    if(b-a == c-b){
        cout << a+(b-a)*n << endl;
    }
    else{
        cout << a*(int)pow((b/a),n) << endl;
    }
    return 0;
}