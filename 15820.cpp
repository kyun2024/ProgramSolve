#include <iostream>

using namespace std;

int main(){
    int s1,s2;
    int a,b;
    cin >> s1 >> s2;
    while(s1--){
        cin >> a >> b;
        if(a!=b){
            cout << "Wrong Answer" << endl;
            return 0;
        }
    }
    while(s2--){
        cin >> a >> b;
        if(a!=b){
            cout << "Why Wrong!!!" << endl;
            return 0;
        }
    }
    cout << "Accepted" << endl;
    return 0;
}
