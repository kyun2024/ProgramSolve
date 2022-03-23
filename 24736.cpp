#include <iostream>

using namespace std;

int main(){
    int i=2,t,f,s,p,c;
    while(i--)
    {
        cin >> t >> f >> s >> p >> c;
        cout << t*6 + f*3 + s*2 + p*1 + c*2 << " ";
    }
    return 0;
}
