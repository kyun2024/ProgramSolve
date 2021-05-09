#include <iostream>

using namespace std;

int s[45];

int main(){
    int T,t,n;
    cin >> T;
    s[1]=2;
    s[2]=3;
    for(int i=3;i<45;i++){
        s[i]=s[i-1]+s[i-2];
    }
    for(t=1;t<=T;t++){
        cout << "Scenario #" << t << ":" << endl;
        cin >> n;
        cout << s[n] << endl << endl;
    }
}