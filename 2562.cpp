#include <iostream>

int main(){
    using namespace std;
    int t,i,m,idx;
    m = 0;
    idx = 0;
    for(i=1;i<=9;i++){
        cin >> t;
        if(m<t){
            m=t;
            idx = i;
        }
    }
    cout << m << endl << idx << endl;
    return 0;
}